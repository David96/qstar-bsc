#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <glob.h>

#include "TROOT.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TGraph.h"
#include "TTree.h"

using namespace std;

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

void cl_combine(const char *output_dir) {
    vector<string> files = glob("cl_output/" + string(output_dir) + "/higgsCombineTest.AsymptoticLimits.mH*.root");
    double limits[files.size()];
    double lupper[files.size()];
    double llower[files.size()];
    double masses[files.size()];
    int skipped = 0;
    for (unsigned int i = 0; i < files.size(); ++i) {
        TFile f(files[i].c_str());
        TTree *tree = (TTree*)f.Get("limit");
        tree->SetBranchAddress("mh", &masses[i - skipped]);
        /*
         * Limit entries:
         * 0 -> 2.5%
         * 1 -> 16%
         * 2 -> 50%
         * 3 -> 84%
         * 4 -> 97.5%
         * 5 -> observed
         */
        tree->SetBranchAddress("limit", &limits[i - skipped]);
        tree->GetEntry(2);
        tree->SetBranchAddress("limit", &lupper[i - skipped]);
        tree->GetEntry(3);
        tree->SetBranchAddress("limit", &llower[i - skipped]);
        tree->GetEntry(1);
        if (limits[i - skipped] < 0.00001) {
            cout << "Ignored entry: mass = " << masses[i - skipped] << "; limit = " << limits[i - skipped] << endl;
            skipped++;
        } else {
            cout << "Got entry: mass = " << masses[i - skipped] << "; limit = " << limits[i - skipped] << endl
                << "Lower: " << llower[i - skipped] << " Upper: " << lupper[i - skipped] << endl << endl;
        }
        delete tree;
    }
    TCanvas *c = new TCanvas();
    c->SetLogy();
    TGraph *g = new TGraph(files.size() - skipped, masses, limits);
    TGraph *upper = new TGraph(files.size() - skipped, masses, lupper);
    TGraph *lower = new TGraph(files.size() - skipped, masses, llower);
    upper->SetLineColor(kGreen);
    lower->SetLineColor(kGreen);
    g->SetTitle(string("Cross-Section limit of " + string(output_dir) + ";Masspoint [GeV];Cross Section limit x BR").c_str());
    g->Sort();
    g->Draw("AL*");
    upper->Draw("same");
    lower->Draw("same");
}
