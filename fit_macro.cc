#include <iostream>
#include <string>
#include <string.h>
#include <cmath>

#include "RooAddPdf.h"
#include "RooArgusBG.h"
#include "RooCBShape.h"
#include "RooConstVar.h"
#include "RooDataHist.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooGenericPdf.h"
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

using namespace std;
using namespace RooFit;

struct masspoint_data {
    const char* filename;
    int sig_min, sig_max, model_min, model_max;
    int mean, mean_min, mean_max;
};

void init_masspoints(map<string, masspoint_data> &masspoints) {
    masspoints["W12TeV"] = {
        "output/uhh2.AnalysisModuleRunner.MC.QstarToQW12TeV_PS_2018.root",
        1000, 1800, // sig min/max
        1000, 4500, // model min/max
        2000, 1000, 3000 // mean, mean min/max
    };
    masspoints["W14TeV"] = {
        "output/uhh2.AnalysisModuleRunner.MC.QstarToQW14TeV_PS_2018.root",
        1000, 2300, // sig min/max
        1000, 4500, // model min/max
        2000, 1000, 3000 // mean, mean min/max
    };
    masspoints["W16TeV"] = {
        "output/uhh2.AnalysisModuleRunner.MC.QstarToQW16TeV_PS_2018.root",
        1200, 2500, // sig min/max
        1000, 4500, // model min/max
        2000, 1000, 3000 // mean, mean min/max
    };
    masspoints["W18TeV"] = {
        "output/uhh2.AnalysisModuleRunner.MC.QstarToQW18TeV_PS_2018.root",
        1200, 2700, // sig min/max
        1000, 4500, // model min/max
        2000, 1000, 3000 // mean, mean min/max
    };
    masspoints["W2TeV"] = {
        "output/uhh2.AnalysisModuleRunner.MC.QstarToQW2TeV_PS_2018.root",
        1000, 2900, // sig min/max
        1000, 4500, // model min/max
        2000, 1000, 3000 // mean, mean min/max
    };
    masspoints["W25TeV"] = {
        "output/uhh2.AnalysisModuleRunner.MC.QstarToQW25TeV_PS_2018.root",
        1700, 3300, // sig min/max
        1000, 4500, // model min/max
        2500, 1000, 3500 // mean, mean min/max
    };
    masspoints["W3TeV"] = {
        "output/uhh2.AnalysisModuleRunner.MC.QstarToQW3TeV_PS_2018.root",
        2000, 3800, // sig min/max
        1000, 5000, // model min/max
        3000, 2000, 4000 // mean, mean min/max
    };
    masspoints["W4TeV"] = {
        "output/uhh2.AnalysisModuleRunner.MC.QstarToQW4TeV_PS_2018.root",
        3000, 4800, // sig min/max
        1000, 5000, // model min/max
        4000, 3000, 5000 // mean, mean min/max
    };
    masspoints["W45TeV"] = {
        "output/uhh2.AnalysisModuleRunner.MC.QstarToQW45TeV_PS_2018.root",
        3500, 5300, // sig min/max
        1000, 5500, // model min/max
        4500, 3500, 5500 // mean, mean min/max
    };
    masspoints["W5TeV"] = {
        "output/uhh2.AnalysisModuleRunner.MC.QstarToQW5TeV_PS_2018.root",
        4000, 6000, // sig min/max
        1000, 6000, // model min/max
        5000, 4000, 6000 // mean, mean min/max
    };
    masspoints["Z2TeV"] = {
        "output/uhh2.AnalysisModuleRunner.MC.QstarToQZ2TeV_PS_2018.root",
        1000, 2900, // sig min/max
        1000, 4500, // model min/max
        2000, 1000, 3000 // mean, mean min/max
    };
    masspoints["Z5TeV"] = {
        "output/uhh2.AnalysisModuleRunner.MC.QstarToQZ5TeV_PS_2018.root",
        4000, 6000, // sig min/max
        1000, 6000, // model min/max
        5000, 4000, 6000 // mean, mean min/max
    };
}

void fit_macro(const char *bg_file, const char *hist, string masspoint_name, bool debug_signal = false) {

    map<string, masspoint_data> masspoints;
    init_masspoints(masspoints);

    if(masspoints.find(masspoint_name) == masspoints.end()) {
        cerr << "Masspoint " << masspoint_name << " doesn't exist!" << endl;
        return;
    }
    auto masspoint = masspoints[masspoint_name];

    TCanvas *c = new TCanvas("c", "c", 1720, 980);

    /* Get histograms from files */
    TFile *bgf = new TFile(bg_file);
    TH1F *bgh;
    bgf->GetObject(hist, bgh);
    if (bgh == NULL) {
        cerr << "File " << bg_file << " doesn't include histogram " << hist << endl;
        return;
    }

    TFile *sigf = new TFile(masspoint.filename);
    TH1F *sigh;
    sigf->GetObject(hist, sigh);
    if (sigh == NULL) {
        cerr << "File " << masspoint.filename << " doesn't include histogram " << hist << endl;
        return;
    }

    c->SetLogy();

    /* Rebinning */
    int nbins = bgh->GetNbinsX();
    int big_bins = 6;
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
    bgh = (TH1F*)bgh->Rebin(new_bins - 1, "newbg", bins);
    //cout << "Last bin content: " << bgh->GetBinContent(bgh->GetNbinsX()) << endl;

    /* Background fit */
    TF1 *bg = new TF1("bg", "[0] * ( (1-x/13000)^[2]) / (x/13000)^[1]", 1400, 5200);
    bg->SetParameters(0.05, 6.5, 6.8);
    bg->SetParLimits(0, 0.04, 0.065);
    bg->SetParLimits(1, 6.4, 6.7);
    bg->SetParLimits(2, 6.5, 7.5);
    //ROOT::Math::MinimizerOptions::SetDefaultMaxFunctionCalls(9999999);
    bgh->SetLineColor(kBlue);
    bgh->Fit(bg, "RWLM", "", 1400, 5200);

    /* Signal fit */
    RooRealVar mjj("mjj", "m_{jj} [GeV]", 1000, 6000);
    RooRealVar m0("m0", "mean", masspoint.mean, masspoint.mean_min, masspoint.mean_max);
    RooRealVar sigma("sigma", "sigma", 100, 100, 400);
    RooRealVar alpha("alpha", "alpha", 1, 0.5, 100);
    RooRealVar n("n", "n", 0.01, 0, 100);
    RooCBShape sig_pdf("sig", "Signal", mjj, m0, sigma, alpha, n);
    RooDataHist sig_h("sig_hist", "Signal data", mjj, sigh);
    sig_pdf.fitTo(sig_h, Range(masspoint.sig_min, masspoint.sig_max));

    /* Transfer bg params to RooFit */
    auto P0 = bg->GetParameter(0); auto p0_err = bg->GetParError(0);
    auto P1 = bg->GetParameter(1); auto p1_err = bg->GetParError(1);
    auto P2 = bg->GetParameter(2); auto p2_err = bg->GetParError(2);
    RooRealVar p0("p0", "P0", P0, P0 - 3 * p0_err, P0 + 3 * p0_err);
    RooRealVar p1("p1", "P1", P1, P1 - 3 * p1_err, P1 + 3 * p1_err);
    RooRealVar p2("p2", "P2", P2, P2 - 3 * p2_err, P2 + 3 * p2_err);

    RooGenericPdf bg_pdf("bg", "Background", "(p0 * (1 - mjj /13000) ^ p2) / (mjj /13000)^p1",
            RooArgSet(mjj,p0,p1,p2));

    /* combined fit */
    RooRealVar nsig("nsig","#signal events",0.,100000);
    RooRealVar nbkg("nbkg","#background events",0.,100000);
    RooAddPdf model("model", "bg+sig", RooArgList(bg_pdf, sig_pdf), RooArgList(nbkg, nsig));

    RooPlot *dataFrame = mjj.frame(Title("m_{jj}"));
    if (!debug_signal) {
        // make stuff deterministic - otherwise every run gives a slightly different result
        RooRandom::randomGenerator()->SetSeed(142);
        RooDataSet *gen_data = model.generate(mjj, 100000);
        model.fitTo(*gen_data, Range(masspoint.model_min, masspoint.model_max));

        // save to RooWorkspace
        RooWorkspace w("model");
        w.import(sig_pdf);
        w.import(bg_pdf);
        w.import(model);
        w.writeToFile(("model_" + masspoint_name + ".root").c_str());

        /* plot all that stuff */
        gen_data->plotOn(dataFrame);
        model.plotOn(dataFrame);
        model.plotOn(dataFrame, Components("bg"),LineStyle(kDashed));
        model.plotOn(dataFrame, Components("sig"),LineColor(kRed));
        model.paramOn(dataFrame);
    } else {
        sig_h.plotOn(dataFrame);
        sig_pdf.plotOn(dataFrame);
        sig_pdf.paramOn(dataFrame);
    }
    dataFrame->SetMinimum(0.1);
    dataFrame->Draw();
}
