#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TH1F.h"
#include "TH2D.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TPaveText.h"
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

void macro(const char *file1, const char *file2, const char *output_folder) {
    TFile *z_file = new TFile(file1);
    TFile *w_file = new TFile(file2);

    TIter next(z_file->GetListOfKeys());
    TKey* key;
    while ((key=(TKey*)next())) {
        if (strncmp(key->GetClassName(), "TDirectoryFile", 30) == 0) {
            TDirectory *dir = z_file->GetDirectory(key->GetName());
            TDirectory *dir_w = w_file->GetDirectory(key->GetName());
            cout << "Got direcoryfile: " << key->GetName() << endl;

            TIter next_h(dir->GetListOfKeys());
            TKey *key_h;
            while((key_h=(TKey*)next_h())) {
                if (strncmp(key_h->GetClassName(), "TH", 2) == 0) {
                    auto c1 = new TCanvas("c", "c", 600,500);
                    c1->SetBatch(kTRUE);
                    gStyle->SetOptTitle(0);

                    TH1 *z_hist, *w_hist;
                    dir->GetObject(key_h->GetName(), z_hist);
                    z_hist->SetStats(kFALSE);
                    z_hist->SetTitle(file1);
                    z_hist->SetLineColor(kBlue);
                    z_hist->SetFillColor(kBlue);
                    z_hist->SetMarkerColor(kBlue);

                    dir_w->GetObject(key_h->GetName(), w_hist);
                    w_hist->SetStats(kFALSE);
                    w_hist->SetTitle(file2);
                    w_hist->SetLineColor(kRed);
                    w_hist->SetFillColor(kRed);
                    w_hist->SetMarkerColor(kRed);

                    double minimum = min(z_hist->GetMinimum(), w_hist->GetMinimum());
                    z_hist->SetMinimum(minimum - minimum * 0.1);
                    double maximum = max(z_hist->GetMaximum(), w_hist->GetMaximum());
                    z_hist->SetMaximum(1.1 * maximum);

                    if (strncmp(z_hist->GetName(), "pt", 2) == 0 ||
                            strncmp(z_hist->GetName(), "cb_pt", 5) == 0 ||
                            strncmp(z_hist->GetName(), "invMass", 7) == 0) {
                        if (z_hist->GetMinimum() <= 0) {
                            z_hist->SetMinimum(0.1);
                        }
                        c1->SetLogy();
                        z_hist->SetMaximum(10 * maximum);
                    }
                    z_hist->Draw();
                    w_hist->Draw("same");

                    c1->BuildLegend(0.5, 0.8, 0.9, 0.9);
                    c1->SaveAs((string(output_folder) + "/" + string(key->GetName()) + "_" + string(key_h->GetName()) + ".pdf").c_str());
                    delete c1;
                    delete z_hist;
                    delete w_hist;
                }
            }
        }

        /*TH1F *z_mass;
        z_file->GetObject("Njet/SoftDropMass_1", z_mass);
        TH1F *w_mass;
        w_file->GetObject("Njet/SoftDropMass_1", w_mass);

        z_mass->SetLineColor(kRed);
        w_mass->SetLineColor(kBlue);

        z_mass->SetAxisRange(0, 130);
        z_mass->SetStats(kFALSE);
        z_mass->SetTitle("SoftDropMass with QZ Signal");

        w_mass->SetStats(kFALSE);
        w_mass->SetTitle("SoftDropmass with QW Signal");

        z_mass->Draw();
        w_mass->Draw("same");*/
    }


    /*auto legend = new TLegend(0.1,0.7,0.48,0.9);
    legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    legend->AddEntry(z_mass,"SoftDropMass with QZ Signal","lp");
    legend->AddEntry(w_mass,"SoftDropmass with QW Signal","lp");
    legend->Draw();*/
    //c1->BuildLegend(0.5, 0.8, 0.9, 0.9);
}

