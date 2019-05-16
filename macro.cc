#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TLegend.h"
#include "TCanvas.h"
#include <iostream>

using namespace std;

void macro() {
    auto c1 = new TCanvas("c", "c", 600,500);
    TFile *z_file = new TFile("uhh2.AnalysisModuleRunner.MC.qstar-Z-2TeV_2018.root");
    TFile *w_file = new TFile("uhh2.AnalysisModuleRunner.MC.qstar2TeV_2018.root");

    TH1F *z_mass;
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
    w_mass->Draw("same");

    /*auto legend = new TLegend(0.1,0.7,0.48,0.9);
    legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    legend->AddEntry(z_mass,"SoftDropMass with QZ Signal","lp");
    legend->AddEntry(w_mass,"SoftDropmass with QW Signal","lp");
    legend->Draw();*/
    c1->BuildLegend(0.5, 0.8, 0.9, 0.9);
}

int main() {
    macro();
}
