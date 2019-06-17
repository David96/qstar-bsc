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

void cs_limits(const char *masspoint_name, const int mass, bool plot = false) {
    RooWorkspace *w;
    TFile *file = new TFile(("model_" + string(masspoint_name) + ".root").c_str());
    if (file == NULL) {
        cerr << "Filename invalid" << endl;
        return;
    }
    file->GetObject("model", w);
    if (w == NULL) {
        cerr << "Couldn't get Workspace" << endl;
        return;
    }
    auto nsig = w->var("nsig");
    auto nbkg = w->var("nbkg");
    if (nsig == NULL || nbkg == NULL) {
        cerr << "Couldn't get nsig or nbkg" << endl;
        return;
    }
    cout << "Cross Section limmits: " << endl
        << "High: " << (w->var("nsig")->getVal() + w->var("nsig")->getError() * 2) / 59740 << endl
        << "Low: " <<  (w->var("nsig")->getVal() - w->var("nsig")->getError() * 2) / 59740 << endl;
    RooAddPdf *model = (RooAddPdf*)w->pdf("model");
    if (model == NULL) {
        cerr << "Couldn't get model" << endl;
        return;
    }
    RooCBShape *signal = (RooCBShape*)w->pdf("sig");
    RooRealVar m0, sigma, alpha, n;
    m0 = *w->var("m0"); sigma = *w->var("sigma"); alpha = *w->var("alpha"); n = *w->var("n");
    if (signal == NULL) {
        cerr << "Couldn't get signal" << endl;
        return;
    }
    RooGenericPdf *bg = (RooGenericPdf*)w->pdf("bg");
    RooRealVar p0, p1, p2;
    p0 = *w->var("p0"); p1 = *w->var("p1"); p2 = *w->var("p2");
    if (bg == NULL) {
        cerr << "Couldn't get bg" << endl;
        return;
    }
    RooRealVar *mjj = w->var("mjj");
    mjj->setVal(mass);
    RooArgSet bg_args(*mjj);
    RooArgSet sig_args(*mjj);
    double bkg = nbkg->getVal() * bg->getVal(&bg_args);
    double sig = nsig->getVal() * signal->getVal(&sig_args);
    mjj->setRange("integral", mass * 0.9f, mass * 1.1f);
    RooAbsReal *int_sig = signal->createIntegral(*mjj, NormSet(sig_args), Range("integral"));
    RooAbsReal *int_bg = bg->createIntegral(*mjj, NormSet(bg_args), Range("integral"));

    cout << "Bg: " << bkg << endl << "Sig: " << sig << endl << "S/sqrt(B): " << sig / sqrt(bkg) << endl
         << "2sigma: " << nsig->getError() * 2 << endl;
    cout << "Signal integral: " << nsig->getVal() * int_sig->getVal() << endl
         << "Background integral: " << nbkg->getVal() * int_bg->getVal() << endl
         << "S/sqrt(B): "
         << nsig->getVal() * int_sig->getVal() / sqrt(nbkg->getVal() * int_bg->getVal()) << endl;
    if (plot) {
        RooPlot *dataFrame = mjj->frame(Title("m_{jj}"));
        model->plotOn(dataFrame);
        model->paramOn(dataFrame);
        model->plotOn(dataFrame, Components("bg"),LineStyle(kDashed));
        model->plotOn(dataFrame, Components("sig"),LineColor(kRed));
        dataFrame->Draw();
    }
}

