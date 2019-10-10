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
#include "TLegend.h"

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

int get_limits(vector<string>& files, double *limits, double *lupper, double *llower, double *lobserved, double *masses) {
    int skipped = 0;
    for (unsigned int i = 0; i < files.size(); ++i) {
        cout << "Using file " << files[i] << endl;
        TFile f(files[i].c_str());
        TTree *tree = (TTree*)f.Get("limit");
        if (tree != NULL) {
            tree->SetBranchAddress("mh", &masses[i - skipped]);
            /*
             * Limit entries:
             * 0 -> 2.5%
             * 1 -> 16%
             * 2 -> 50%
             * 3 -> 84%
             * 4 -> 97.5%
             * 5 -> lobserved
             */
            tree->SetBranchAddress("limit", &limits[i - skipped]);
            tree->GetEntry(2);
            tree->SetBranchAddress("limit", &lupper[i - skipped]);
            tree->GetEntry(3);
            tree->SetBranchAddress("limit", &llower[i - skipped]);
            tree->GetEntry(1);
            tree->SetBranchAddress("limit", &lobserved[i - skipped]);
            tree->GetEntry(5);
            limits[i-skipped] /= 100.;
            lupper[i-skipped] /= 100.;
            llower[i-skipped] /= 100.;
            lobserved[i-skipped] /= 100.;
            if (limits[i - skipped] < 0.00001) {
                cout << "Ignored entry: mass = " << masses[i - skipped] << "; limit = " << limits[i - skipped] << endl;
                skipped++;
            } else {
                cout << "Got entry: mass = " << masses[i - skipped] << "; limit = " << limits[i - skipped] << endl
                    << "Lower: " << llower[i - skipped] << " Upper: " << lupper[i - skipped] << endl
                    << "lobserved: " << lobserved[i -  skipped] << endl << endl;
            }
            delete tree;
        } else {
            skipped++;
        }
    }
    return skipped;
}

void plot(string output_dir, string name, TLegend *legend, int line_color = kBlack, bool first = true) {
    vector<string> files = glob("cl_output/" + string(output_dir) + "/higgsCombine" + name + ".AsymptoticLimits.mH*.root");
    cout << "Got " << files.size() << " files " << endl << endl;
    double limits[files.size()];
    double lupper[files.size()];
    double llower[files.size()];
    double lobserved[files.size()];
    double masses[files.size()];

    int skipped = get_limits(files, limits, lupper, llower, lobserved, masses);

    TGraph *g = new TGraph(files.size() - skipped, masses, limits);
    TGraph *upper = new TGraph(files.size() - skipped, masses, lupper);
    TGraph *lower = new TGraph(files.size() - skipped, masses, llower);
    TGraph *observed = new TGraph(files.size() - skipped, masses, lobserved);
    upper->SetLineColor(kGreen);
    lower->SetLineColor(kGreen);
    observed->SetLineColor(kBlue);
    g->SetLineColor(line_color);
    g->SetTitle(string("Cross-Section limit of " + name + ";Masspoint [GeV];Cross Section limit x BR").c_str());
    g->Sort();
    //observed->Draw("AL*");
    g->GetXaxis()->SetLimits(1600, 7000);
    g->GetYaxis()->SetRangeUser(0.0001, 1);
    if (first) g->Draw("AL");
    else g->Draw("same");
    legend->AddEntry(g, string("q \\rightarrow " + name + ", " + output_dir).c_str());
    //upper->Draw("same");
    //lower->Draw("same");
}

void cl_combine(const char *output_dir, string name) {
    TCanvas *c = new TCanvas();
    auto legend = new TLegend(0.5,0.7,0.9,0.9);
    c->SetLogy();
    plot("2016tau", "qZ", legend, kBlue);
    plot("2016db", "qZ", legend, kBlue + 2, false);
    plot("Combinedtau", "qZ", legend, kRed, false);
    plot("Combineddb", "qZ", legend, kRed + 2, false);

    legend->Draw();
    //plot(output_dir, name);
    //plot(output_dir + string("/HP"), name, kBlue, false);
    //plot(output_dir + string("/LP"), name, kRed, false);
}
