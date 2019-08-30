#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <algorithm>

#include "RooAddPdf.h"
#include "RooArgusBG.h"
#include "RooBukinPdf.h"
#include "RooCBShape.h"
#include "RooConstVar.h"
#include "RooDataHist.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooGenericPdf.h"
#include "RooNovosibirsk.h"
#include "RooPlot.h"
#include "RooPoisson.h"
#include "RooRandom.h"
#include "RooRealVar.h"
#include "RooWorkspace.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH1.h"
#include "TH2D.h"
#include "TLegend.h"
#include "TPaveText.h"
#include "TROOT.h"
#include "TTree.h"
#include "masspoints.h"
#include "HZZ2L2QRooPdfs.h"
#include "RooStats/ModelConfig.h"

using namespace std;
using namespace RooFit;
using namespace RooStats;

void fit_macro(const char *hist, string masspoint_name, string version,
        bool debug_signal = false, string selection = "MC.QCD_2018", bool debug_bg = false,
        string opt = "") {
    gROOT->ProcessLine(".L ../../../lib/slc6_amd64_gcc700/libHiggsAnalysisCombinedLimit.so");

    map<string, masspoint_data> masspoints;
    init_masspoints(masspoints);

    if(masspoints.find(masspoint_name) == masspoints.end()) {
        cerr << "Masspoint " << masspoint_name << " doesn't exist!" << endl;
        return;
    }
    auto masspoint = masspoints[masspoint_name];

    TCanvas *c = new TCanvas("c", "c", 1720, 980);

    /* Get histograms from files */
    TFile *bgf = new TFile(("output/" + version + "/" + (opt == "" ? "" : opt + "/")+ "uhh2.AnalysisModuleRunner." +
                selection + ".root").c_str());
    TH1F *bgh;
    bgf->GetObject(hist, bgh);
    if (bgh == NULL) {
        cerr << "File " << ("output/" + version + "/" + (opt == "" ? "" : opt + "/") + "uhh2.AnalysisModuleRunner." +
                selection + ".root") << " doesn't include histogram " << hist << endl;
        return;
    }

    c->SetLogy();

    bgh->Scale(1 / bgh->GetBinWidth(1));
    /* Rebinning */
    int nbins = bgh->GetNbinsX();
    int big_bins = 8;
    int bins_to_combine = 2;
    int new_bins = nbins + 1 - big_bins * (bins_to_combine - 1);
    double bins[new_bins];
    cout << "Size of new bins: " << new_bins << endl;
    int normal_bins = nbins - big_bins * bins_to_combine;
    for (int i = 1; i <= normal_bins; ++i) {
        bins[i - 1] = bgh->GetBinLowEdge(i);
        //cout << bins[i - 1] << ";" << i - 1 << endl;
    }
    for (int i = normal_bins; i < normal_bins + big_bins; ++i) {
        bins[i] = bgh->GetBinLowEdge(normal_bins + (i - normal_bins) * bins_to_combine + 1);
        //cout << bins[i] << ";" << i << endl;
    }
    bins[new_bins - 1] = bgh->GetBinLowEdge(nbins) + bgh->GetBinWidth(nbins);
    //cout << "Last higher edge (bin[" << new_bins - 1 << "]): " << bins[new_bins - 1] << endl;
    TH1F *bgh_rebinned = (TH1F*)bgh->Rebin(new_bins - 1, "newbg", bins);
    for (int i = bgh_rebinned->GetNbinsX(); i > bgh_rebinned->GetNbinsX() - big_bins; --i) {
        bgh_rebinned->SetBinContent(i, bgh_rebinned->GetBinContent(i) / bins_to_combine);
    }
    //cout << "Last bin content: " << bgh->GetBinContent(bgh->GetNbinsX()) << endl;

    /* Background fit */
    TF1 *bg = new TF1("bg", "[0] * ( (1-x/13000)^[2]) / (x/13000)^[1]", 1400, 6200);
    bg->SetParameters(0.05, 6.5, 6.8);
    /*bg->SetParLimits(0, 0.04, 0.3);
    bg->SetParLimits(1, 6.0, 6.75);
    bg->SetParLimits(2, 6.45, 7.6);*/
    //ROOT::Math::MinimizerOptions::SetDefaultMaxFunctionCalls(9999999);
    bgh_rebinned->SetLineColor(kBlue);
    bgh_rebinned->Fit(bg, "VRWLM", "", 1400, 6200);
    if (debug_bg/* && false*/) {
        bgh_rebinned->Draw();
    } else {
        /* Open signal file */
        string year = (version == "2016"?"2016v2":(version=="2017"?"2017v2":version));
        TFile *sigf = new TFile(( "output/" + version + "/" + (opt == "" ? "" : opt + "/") +
                    (selection == "MC.QCD_2018" ? string(masspoint.preselection) : string(masspoint.filename))
                    + year + ".root").c_str());
        TH1F *sigh;
        sigf->GetObject(hist, sigh);
        if (sigh == NULL) {
            cerr << "File " << ( "output/" + version + "/" + (opt == "" ? "" : opt + "/") +
                    (selection == "MC.QCD_2018" ? string(masspoint.preselection) : string(masspoint.filename))
                    + year + ".root" ) << " doesn't include histogram " << hist << endl;
            return;
        }

        sigh->Scale(1 / sigh->GetBinWidth(1));

        /* Signal fit */

        /* find sigma */
        float sum = 0;
        int min = masspoint.mean - 3*sigh->GetBinWidth(1);
        int max = masspoint.mean + 3*sigh->GetBinWidth(1);
        int nentries = 0;
        for (int i = min; i <= max; i += sigh->GetBinWidth(1)) {
            int bin_number = sigh->GetXaxis()->FindBin(i);
            if (bin_number != 0) {
                int bin_content = sigh->GetBinContent(bin_number);
                sum += bin_content * pow(i - masspoint.mean, 2);
                nentries += bin_content;
            }
        }
        float sigma_est = sqrt(1/(float)(nentries - 1 ) * sum);

        RooRealVar mjj("mjj", "m_{jj} [GeV]", 1000, 8500);
        RooRealVar m0("m0", "mean", masspoint.mean, masspoint.mean_min, masspoint.mean_max);
        RooRealVar sigma("sigma", "sigma", /*sigma_est * 0.8*/masspoint.mean * 0.1, masspoint.mean * 0.03, masspoint.mean * 0.10);
        //sigma.setConstant();
        RooRealVar alpha1("alpha1", "alpha", 1, 0, 1.8);
        RooRealVar alpha2("alpha2", "alpha", 1, 0, 1.8);
        RooRealVar n1("n1", "n", 5, 0.5, 30);
        RooRealVar n2("n2", "n", 5, 0.0, 30);
        //ncb.setConstant(); ng.setConstant();
        //RooCBShape sig_pdf_cb("sig_cb", "Signal", mjj, m0, sigma, alpha, n);
        //RooGaussian sig_pdf_g("sig_g", "Signal", mjj, m0_g, sigma_g);
        //RooAddPdf sig_pdf("sig", "sig_cb+sig_g", RooArgList(sig_pdf_cb, sig_pdf_g), RooArgList(ncb, ng));
        //RooBukinPdf sig_pdf("sig", "Signal", mjj, m0, sigma, alpha, n_left, n_right);
        //RooNovosibirsk sig_pdf("sig", "Signal", mjj, m0, sigma, n_left);
        RooDoubleCB sig_pdf("sig", "Signal", mjj, m0, sigma, alpha1, n1, alpha2, n2);
        RooDataHist sig_h("sig_hist", "Signal data", mjj, sigh);
        sig_pdf.fitTo(sig_h, Range(masspoint.sig_min, masspoint.sig_max));

        /* Fix signal parameters */
        if (!debug_signal) {
            m0.setConstant();
            sigma.setConstant();
            alpha1.setConstant();
            alpha2.setConstant();
            n1.setConstant();
            n2.setConstant();
        }

        /* Transfer bg params to RooFit */
        auto P0 = bg->GetParameter(0); auto p0_err = bg->GetParError(0);
        auto P1 = bg->GetParameter(1); auto p1_err = bg->GetParError(1);
        auto P2 = bg->GetParameter(2); auto p2_err = bg->GetParError(2);
        RooRealVar p0("p0", "P0", P0, std::max(0.001, P0 - 1 * p0_err), P0 + 5 * p0_err);
        RooRealVar p1("p1", "P1", P1, std::max(0.1, P1 - 1 * p1_err), P1 + 1 * p1_err);
        RooRealVar p2("p2", "P2", P2, std::max(0.1, P2 - 1 * p2_err), P2 + 1 * p2_err);
        p0.setError(p0_err);
        p1.setError(p1_err);
        p2.setError(p2_err);
        /*p0.setConstant();
        p1.setConstant();
        p2.setConstant();*/

        RooGenericPdf bg_pdf("bg", "Background", "(p0 * (1 - mjj /13000) ^ p2) / (mjj /13000)^p1",
                RooArgSet(mjj,p0,p1,p2));
        RooDataHist bg_h("bg_hist", "Background data", mjj, bgh);
        //bg_pdf.fitTo(bg_h, Range(1200, 6200));

        /* combined fit */
        RooRealVar nsig("nsig","#signal events", masspoint.mean == 7500 ? 0 : 4000, 0., 10000000);
        RooRealVar nbkg("nbkg","#background events",0.,100000000);
        //nsig.setConstant();
        RooAddPdf model("model", "bg+sig", RooArgList(bg_pdf, sig_pdf), RooArgList(nbkg, nsig));

        RooPlot *dataFrame = mjj.frame(Title("m_{jj}"));
        if (!debug_signal) {
            // make stuff deterministic - otherwise every run gives a slightly different result
            RooRandom::randomGenerator()->SetSeed(142);
            cout << "Sig bins: " << sigh->GetNbinsX() << "; Bg bins: " << bgh->GetNbinsX() << endl;
            for (int i = 1; i <= bgh->GetNbinsX(); ++i) {
                bgh->SetBinContent(i, bgh->GetBinContent(i) + sigh->GetBinContent(i));
                bgh->SetBinError(i, sqrt(bgh->GetBinContent(i)));
            }
            RooDataHist model_h("model_hist", "Model", mjj, bgh);
            //RooDataSet *gen_data = model.generate(mjj, 100000);
            if (!debug_bg) {
                model.fitTo(model_h, Range(masspoint.model_min, masspoint.model_max));
            }
            //model.chi2FitTo(model_h, Range(masspoint.model_min, masspoint.model_max));


            /* plot all that stuff */
            if (debug_bg) {
                bg_h.plotOn(dataFrame);
                bg_pdf.plotOn(dataFrame);
                bg_pdf.paramOn(dataFrame);
            } else {
                model_h.plotOn(dataFrame);
                model.plotOn(dataFrame);
                RooAbsData *data;
                int floatPars = 5;//model.getParameters(data)->selectByAttrib("Constant", kFALSE)->getSize() - 1;
                cout << "Number of free parameters: " << floatPars << endl;
                cout << "chi^2/ndof: " <<  dataFrame->chiSquare(floatPars) << endl;
                model.plotOn(dataFrame, Components("bg"),LineStyle(kDashed));
                model.plotOn(dataFrame, Components("sig"),LineColor(kRed));
                model.paramOn(dataFrame);
            }


            // save to RooWorkspace
            // unrestrict parameters for limit calculation
            //p0.setRange(0, 10);
            //p1.setRange(0, 30);
            //p2.setRange(0, 30);
            p0.setRange(std::max(0.001, P0 - 5 * p0_err), P0 + 5 * p0_err);
            p1.setRange(std::max(0.001, P1 - 3 * p1_err), P1 + 3 * p1_err);
            p2.setRange(std::max(0.001, P2 - 3 * p2_err), P2 + 3 * p2_err);
            RooWorkspace w("model");
            w.autoImportClassCode(kTRUE);
            w.addClassDeclImportDir("./");
            w.addClassImplImportDir("./");
            w.importClassCode(RooDoubleCB::Class(), kTRUE);
            //w.import(sig_pdf);
            //w.import(bg_pdf);
            mjj.setVal(masspoint.mean);
            w.import(model);
            w.defineSet("obs_bg", "mjj");
            w.defineSet("obs_model", "mjj");
            w.defineSet("poi", "nsig");

            ModelConfig bgModel("bgModel", &w);
            bgModel.SetPdf(bg_pdf);
            bgModel.SetObservables(*w.set("obs_bg"));
            bgModel.SetParametersOfInterest(*w.set("poi"));
            bgModel.SetSnapshot(*w.set("poi"));

            ModelConfig completeModel("bg+sModel", &w);
            completeModel.SetPdf(model);
            completeModel.SetObservables(*w.set("obs_model"));
            completeModel.SetParametersOfInterest(*w.set("poi"));
            completeModel.SetSnapshot(*w.set("poi"));

            w.import(bgModel);
            w.import(completeModel);
            w.import(model_h);
            w.Print();
            std::replace(opt.begin(), opt.end(), '/', '_');
            w.writeToFile(("models/" + version + "/" + opt + masspoint_name + ".root").c_str());

            cout << "Nsig integral: " << sigh->Integral() / (bgh->Integral() + sigh->Integral()) << endl
                << "Nsig fit: " << nsig.getVal() / (nsig.getVal() + nbkg.getVal()) << endl;

            cout << "Bg integral: " << bgh->Integral() << endl
                 << "Sig integral: " << sigh->Integral() << endl;

            string datacard = "";
            transform(masspoint_name.begin(), masspoint_name.end(), masspoint_name.begin(),
                    [](unsigned char c){ return std::tolower(c); });

            if (opt == "DB083") {
                cout << "Writing rate for deep boosted HP category" << endl;
                datacard = "datacards/" + version + "/deep_boosted/HP/" + masspoint_name + "_datacard.txt";
            } else if (opt == "LP") {
                cout << "Writing rate for deep boosted LP category" << endl;
                datacard = "datacards/" + version + "/deep_boosted/LP/" + masspoint_name + "_datacard.txt";
            } else if (opt == "TAU035") {
                cout << "Writing rate for tau HP category" << endl;
                datacard = "datacards/" + version + "/tau21/HP/" + masspoint_name + "_datacard.txt";
            } else if (opt == "LPtau") {
                cout << "Writing rate for tau LP category" << endl;
                datacard = "datacards/" + version + "/tau21/LP/" + masspoint_name + "_datacard.txt";
            }
            if (datacard != "") {
                string sed = string("sed -i 's/rate .*/rate    ") + to_string(sigh->Integral()) + " " +
                    to_string(bgh->Integral()) + "/g' " + datacard;
                cout << "Running " << sed << endl;
                cout << "sed run with exit code " << system(sed.c_str()) << endl;
            }
        } else {
            sig_h.plotOn(dataFrame);
            sig_pdf.plotOn(dataFrame);
            //sig_pdf.plotOn(dataFrame, Components("sig_cb"), LineColor(kYellow));
            //sig_pdf.plotOn(dataFrame, Components("sig_g"), LineColor(kRed));
            sig_pdf.paramOn(dataFrame);
            cout << "N: " << sigh->GetEntries() << endl;
            cout << "Sum: " << sum << endl;
            cout << "Nentries: " << nentries << endl;
            cout << "Esitmated sigma: " << sigma_est << endl;
            cout << "Chi^2 " << dataFrame->chiSquare(6) << endl;
        }
        dataFrame->SetMinimum(0.001);
        dataFrame->Draw();
    }
}
