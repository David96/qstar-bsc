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
#include "RooRealVar.h"
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

double crystal_ball(double x, double alpha, double n, double mean, double sigma) {
    double tmp = (x - mean) / sigma;
    double A = pow((n / abs(alpha)), n) * exp(-alpha*alpha/2);
    double B = n/abs(alpha) - abs(alpha);
    double C = n/abs(alpha) * 1/(n-1) * exp(-alpha*alpha/2);
    double D = sqrt(M_PI/2) * (1+erf(abs(alpha)/sqrt(2)));
    double N = 1/(sigma*(C+D));
    if(tmp > -alpha) {
        return N * exp(-tmp*tmp/2);
    } else {
        return A * pow(B - tmp, -n);
    }
}

void fit_macro(const char *bg_file, const char *bg_hist,
        const char *sig_file, const char *sig_hist) {
    TCanvas *c = new TCanvas("c", "c", 1720, 980);
    TFile *bgf = new TFile(bg_file);
    TH1F *bgh;
    bgf->GetObject(bg_hist, bgh);

    TFile *sigf = new TFile(sig_file);
    TH1F *sigh;
    sigf->GetObject(sig_hist, sigh);

    float epsilon = 0.5;
    for(int i = 1; i <= bgh->GetNbinsX(); ++i) {
        if (bgh->GetBinContent(i) <= 0) {
            //bgh->SetBinContent(i, 0.01);
        }
        if(bgh->GetBinContent(i) < epsilon) {
            //bgh->SetBinError(i, 0);
        }
    }
    for(int i = 1; i <= sigh->GetNbinsX(); ++i) {
        /*if(sigh->GetBinContent(i) <= 0) {
            sigh->SetBinContent(i, 0.1);
        }*/
        if(sigh->GetBinContent(i) < 2) {
            //sigh->SetBinError(i, 0);
        }
    }
    c->SetLogy();

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

#define X_MIN 1400
#define X_MAX 5200

    TF1 *bg = new TF1("bg", "[0] * ( (1-x/13000)^[2]) / (x/13000)^[1]", X_MIN, X_MAX);
    bg->SetParameters(0.05, 6.5, 6.8);
    bg->SetParLimits(0, 0.04, 0.065);
    bg->SetParLimits(1, 6.4, 6.7);
    bg->SetParLimits(2, 6.5, 7.5);
    //ROOT::Math::MinimizerOptions::SetDefaultMaxFunctionCalls(9999999);
    bgh->SetLineColor(kBlue);
    //bgh->Fit(bg, "RWLM", "", X_MIN, X_MAX);

    TF1 *sig = new TF1("sig", "gaus", 1500, 2500);
    //TF1 *sig = new TF1("sig", "crystal_ball(x,[0],[1],[2],[3])", 1500, 2500);
    sigh->SetMarkerColor(kRed);
    sigh->Fit(sig, "RWLM", "same", 1500, 2500);
    cout << "a: " << sig->GetParameter(0) << "; μ: " << sig->GetParameter(1) <<
        "; sigma: " << sig->GetParameter(2) << endl;
    cout << "error a: " << sig->GetParError(0) << endl;

    RooRealVar mjj("mjj", "m_{jj} [GeV]", X_MIN, X_MAX);
    auto P0 = bg->GetParameter(0); auto p0_err = bg->GetParError(0);
    auto P1 = bg->GetParameter(1); auto p1_err = bg->GetParError(1);
    auto P2 = bg->GetParameter(2); auto p2_err = bg->GetParError(2);
    RooRealVar p0("p0", "P0", P0, P0 - p0_err, P0 + p0_err);
    RooRealVar p1("p1", "P1", P1, P1 - p1_err, P1 + p1_err);
    RooRealVar p2("p2", "P2", P2, P2 - p2_err, P2 + p2_err);

    RooGenericPdf bg_pdf("bg", "Background", "(p0 * (1 - mjj /13000) ^ p2) / (mjj /13000)^p1",
            RooArgSet(mjj,p0,p1,p2));

    P0 = sig->GetParameter(0); p0_err = sig->GetParError(0);
    P1 = sig->GetParameter(1); p1_err = sig->GetParError(1);
    P2 = sig->GetParameter(2); p2_err = sig->GetParError(2);
    RooRealVar a("a", "Amplitude", P0, P0 - p0_err, P0 + p0_err);
    RooRealVar mu("mu", "Mu", P1, P1 - p1_err, P1 + p1_err);
    RooRealVar sigma("sigma", "Sigma", P2, P2 - p2_err, P2 + p2_err);

    RooGenericPdf sig_pdf("sig", "Signal", "a*exp(-0.5*((mjj-mu)/sigma)**2)", RooArgSet(mjj,a,mu,sigma));

    RooRealVar nsig("nsig","#signal events",0.,100000);
    RooRealVar nbkg("nbkg","#background events",0.,100000);
    RooAddPdf model("model", "bg+cb", RooArgList(bg_pdf, sig_pdf), RooArgList(nsig, nbkg));

    /*RooDataSet *gen_data = model.generate(mjj, 100000);
    model.fitTo(*gen_data, Range(X_MIN, X_MAX));

    RooPlot *dataFrame = mjj.frame(Title("m_{jj}"));
    gen_data->plotOn(dataFrame);
    model.plotOn(dataFrame);
    dataFrame->SetMinimum(0.1);
    dataFrame->Draw();*/
}
