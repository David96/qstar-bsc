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
#include "HZZ2L2QRooPdfs.cc"

using namespace std;
using namespace RooFit;

void significance(const char *masspoint_name, const int mass) {

    float y[9];
    float x[9];

    for (int i = 0; i < 9; i++) {
        x[i] = (i + 1) / 10.f;
        RooWorkspace *w;
        TFile *file = new TFile(("model_OPT0" + to_string(i + 1) + string(masspoint_name) + ".root").c_str());
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
        RooDoubleCB *signal = (RooDoubleCB*)w->pdf("sig");
        if (signal == NULL) {
            cerr << "Couldn't get signal" << endl;
            return;
        }
        RooGenericPdf *bg = (RooGenericPdf*)w->pdf("bg");
        if (bg == NULL) {
            cerr << "Couldn't get bg" << endl;
            return;
        }
        RooRealVar *mjj = w->var("mjj");
        mjj->setVal(mass);
        RooArgSet bg_args(*mjj);
        RooArgSet sig_args(*mjj);
        mjj->setRange("integral", mass * 0.9f, mass * 1.1f);
        RooAbsReal *int_sig = signal->createIntegral(*mjj, NormSet(sig_args), Range("integral"));
        RooAbsReal *int_bg = bg->createIntegral(*mjj, NormSet(bg_args), Range("integral"));

        float significance = nsig->getVal() * int_sig->getVal() / sqrt(nbkg->getVal() * int_bg->getVal());
        cout << "S/sqrt(B): " << significance << endl;
        y[i] = significance;
    }
    TGraph *g = new TGraph(9, x, y);
    g->Draw("AL*");
}
