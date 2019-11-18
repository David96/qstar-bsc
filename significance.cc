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

std::vector<std::string> glob(const std::string& pattern) {
    using namespace std;

    // glob struct resides on the stack
    glob_t glob_result;
    memset(&glob_result, 0, sizeof(glob_result));

    // do the glob operation
    int return_value = glob(pattern.c_str(), GLOB_TILDE, NULL, &glob_result);
    if(return_value != 0) {
        globfree(&glob_result);
        stringstream ss;
        ss << "glob() failed with return_value " << return_value << endl;
        throw std::runtime_error(ss.str());
    }

    // collect all the filenames into a std::list<std::string>
    vector<string> filenames;
    for(size_t i = 0; i < glob_result.gl_pathc; ++i) {
        filenames.push_back(string(glob_result.gl_pathv[i]));
    }

    // cleanup
    globfree(&glob_result);

    // done
    return filenames;
}

float getXValue(const string &filename, const string &opt) {
    int offset = ("models/2018/" + opt).length();
    string x = filename.substr(offset, 3);
    return atof(x.c_str()) / (pow(10, x.length() - 1));
}

void significance(const char *masspoint_name, const int mass, const string opt, float minx = 0.) {

    float y[255];
    float x[255];

    vector<string> files = glob("models/2018/" + opt + "*" + string(masspoint_name) + ".root");
    int skipped_i = 0;
    for (unsigned int i = 0; i < files.size(); i++) {
        cout << "Significance for " << files[i] << endl;
        float tmp_x = getXValue(files[i], opt);
        if (tmp_x >= minx) {
            x[i - skipped_i] = tmp_x;
            RooWorkspace *w;
            TFile *file = new TFile(files[i].c_str());
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
            y[i - skipped_i] = significance;
        } else {
            skipped_i++;
        }
    }
    TGraph *g = new TGraph(files.size() - skipped_i, x, y);
    g->SetTitle(string(/*"Significance of " + string(masspoint_name) + " at " + to_string(mass) + " GeV*/";\\tau_{21};Significance").c_str());
    g->Sort();
    g->Draw("AL*");
}
