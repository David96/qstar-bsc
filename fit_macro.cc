#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TF1.h"
#include "TH1.h"
#include "TH1F.h"
#include "TH2D.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TPaveText.h"
#include <iostream>
#include <string>
#include <string.h>
#include "RooRealVar.h"
#include "RooConstVar.h"
#include "RooGaussian.h"
#include "RooArgusBG.h"
#include "RooAddPdf.h"
#include "RooDataSet.h"
#include "RooPlot.h"
#include "RooGenericPdf.h"
#include "RooDataHist.h"
#include "RooCBShape.h"

using namespace std;
using namespace RooFit;


void fit_macro(const char *bg_file, const char *bg_hist,
        const char *sig_file, const char *sig_hist) {
    TCanvas *c = new TCanvas("c", "c", 1720, 980);
    //c->SetLogy();
    TFile *bgf = new TFile(bg_file);
    TH1F *bgh;
    bgf->GetObject(bg_hist, bgh);

    TFile *sigf = new TFile(sig_file);
    TH1F *sigh;
    sigf->GetObject(sig_hist, sigh);

    bgh->SetMinimum(1);
    sigh->SetMinimum(1);

    /*TF1 *bg = new TF1("bg", "([0] * (1-x/13000) ^ [2]) / (x/13000)^[1]", 1050, 5000);
    hist->Fit(bg, "", "", 1050, 5000);

    hist->SetMinimum(1);
    hist->Draw();
    bg->Draw("same");

    cout << "Chi^2: " << hist->Chisquare(bg) / ((5000-1050) / hist->GetBinWidth(1) - 3) << endl;*/

    RooRealVar mjj("mjj", "m_{jj} [GeV]", 1000, 7000);
    RooRealVar p0("p0", "P0", 0, 10);
    RooRealVar p1("p1", "P1", 0, 10);
    RooRealVar p2("p2", "P2", 0, 50);

    RooGenericPdf bg("bg", "Background", "(p0 * (1- mjj /13000) ^ p2) / (mjj /13000)^p1",
            RooArgSet(mjj,p0,p1,p2));

    RooRealVar m("m", "CB_m", 1000, 3000);
    RooRealVar sigma("sigma", "CB_sigma", 100, 1000);
    RooRealVar alpha("alpha", "CB_alpha", 1, 10.f);
    RooRealVar n("n", "CB_n", 100, 1000.f);
    RooCBShape sig("sig", "Crystal Ball Signal", mjj, m, sigma, alpha, n);

    RooDataHist data("data", "dataset of m_{jj}", mjj, bgh);
    bg.fitTo(data);

    RooDataHist signal("signal data", "signal of m_{jj}", mjj, sigh);
    sig.fitTo(signal);

    RooPlot *dataFrame = mjj.frame(Title("m_{jj}"));
    data.plotOn(dataFrame, MarkerColor(kBlack));
    bg.plotOn(dataFrame, LineColor(kBlue));
    signal.plotOn(dataFrame, MarkerColor(kRed));
    sig.plotOn(dataFrame, LineColor(kRed));
    dataFrame->Draw();
}
