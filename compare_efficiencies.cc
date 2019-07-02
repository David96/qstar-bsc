#include <iostream>
#include <map>

#include "masspoints.h"
#include "TROOT.h"
#include "TH1F.h"
#include "TFile.h"

using namespace std;

void compare_efficiencies(const char *signal1, const char *cut1, bool post1, const char *signal2 = NULL,
        const char *cut2 = NULL, bool post2 = false, const char *bg1 = "output/uhh2.AnalysisModuleRunner.MC.QCD_PS_2018.root",
        const char *bg2 = NULL) {
    if ((signal2 == NULL || bg2 == NULL) && cut2 == NULL) {
        cerr << "Can't have one file and one cut!" << endl;
        return;
    }
    map<string, masspoint_data> masspoints;
    init_masspoints(masspoints);
    TFile *fbg1 = new TFile(bg1);
    TFile *fbg2 = bg2 == NULL ? NULL : new TFile(bg2);
    TFile *fbg_orig = new TFile("output/current_bg/uhh2.AnalysisModuleRunner.MC.QCD_2018.root");

    cout << "Opened files" << endl;

    TH1F *hbg1, *hbg2, *hbg_orig;
    if (bg2 == NULL) {
        fbg1->GetObject(cut1, hbg1);
        fbg1->GetObject(cut2, hbg2);
    } else {
        fbg1->GetObject(cut1, hbg1);
        fbg2->GetObject(cut2 == NULL ? cut1 : cut2, hbg2);
    }
    fbg_orig->GetObject("common/N_jets", hbg_orig);

    cout << "Got all background objects" << endl;


    for(auto &mp : masspoints) {
        TFile *t1 = new TFile(( "output/signal/" + string(signal1) + "/" +
                    (post1?string(mp.second.filename):string(mp.second.preselection)) ).c_str());
        TFile *t2 = signal2 == NULL ? NULL : new TFile(( "output/signal/" + string(signal2) + "/" +
                    (post2?string(mp.second.filename):string(mp.second.preselection)) ).c_str());
        TFile *orig1 = new TFile(("output/signal/" + string(signal1) +
                    (post1?"/../":"/") + string(mp.second.orig)).c_str());
        TFile *orig2 = new TFile(("output/signal/" + string(signal2) +
                    (post2?"/../":"/") + string(mp.second.orig)).c_str());

        TH1F *njet1, *njet2, *njet1_orig, *njet2_orig;
        t1->GetObject(cut1, njet1);
        if (t2 == NULL) {
            t1->GetObject(cut2, njet2);
        } else {
            t2->GetObject(cut2 == NULL ? cut1 : cut2, njet2);
        }
        orig1->GetObject("common/N_jets", njet1_orig);
        orig2->GetObject("common/N_jets", njet2_orig);

        cout << "Masspoint " << mp.first << ": " << endl
             << "Efficiency 1 = " << njet1->Integral() << " / " << njet1_orig->Integral() << " = "
             << njet1->Integral() / njet1_orig->Integral() << endl
             << "Efficiency 2 = " << njet2->Integral() << " / " << njet2_orig->Integral() << " = "
             << njet2->Integral() / njet2_orig->Integral() << endl;

        delete t1; delete orig1; delete orig2;
        if (t2 != NULL) delete t2;
    }
    cout << "Background efficiency: " << endl
         << "Efficiency 1 = " << hbg1->Integral() << " / " << hbg_orig->Integral() << " = "
         << hbg1->Integral() / hbg_orig->Integral() << endl
         << "Efficiency 2 = " << hbg2->Integral() << " / " << hbg_orig->Integral() << " = "
         << hbg2->Integral() / hbg_orig->Integral() << endl;


    delete fbg1; delete fbg_orig;
    if (fbg2 != NULL) delete fbg2;
}
