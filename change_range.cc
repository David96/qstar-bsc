#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
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
#include <glob.h> // glob(), globfree()
#include <string.h> // memset()
#include <vector>
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;
using namespace RooFit;

void change_range(const char *filename, bool remove, int s = 1, bool debug = false) {
    gROOT->ProcessLine(".L ../../../lib/slc6_amd64_gcc700/libHiggsAnalysisCombinedLimit.so");
    RooWorkspace *w1;
    TFile *file = new TFile(filename);
    file->GetObject("model", w1);
    RooWorkspace w(*w1);
    delete w1;
    file->Close();
    delete file;
    RooRealVar *p0 = w.var("p0");
    RooRealVar *p1 = w.var("p1");
    RooRealVar *p2 = w.var("p2");
    cout << "Current bounds: " << endl
         << p0->getMin() << "; " << p0->getMax() << endl
         << p1->getMin() << "; " << p1->getMax() << endl
         << p2->getMin() << "; " << p2->getMax() << endl;

    if (!debug) {
        if (remove) {
            cout << "Removing bounds" << endl;
            p0->setRange(0, 100);
            p1->setRange(0, 100);
            p2->setRange(0, 100);
        } else {
            cout << "Setting bounds to 1 sigma" << endl;
            p0->setRange(max(0., p0->getVal() - s * p0->getError()), p0->getVal() + s * p0->getError());
            p1->setRange(max(0., p1->getVal() - s * p1->getError()), p1->getVal() + s * p1->getError());
            p2->setRange(max(0., p2->getVal() - s * p1->getError()), p2->getVal() + s * p2->getError());
        }
        cout << "Saving new file to " << filename << endl;
        w.writeToFile(filename);
    }
}
