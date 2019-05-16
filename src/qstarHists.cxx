#include "UHH2/qstar/include/qstarHists.h"
#include "UHH2/core/include/Event.h"
#include "UHH2/common/include/Utils.h"

#include "TH1F.h"
#include "TH2F.h"
#include <iostream>

using namespace std;
using namespace uhh2;
using namespace uhh2examples;

qstarHists::qstarHists(Context & ctx, const string & dirname): Hists(ctx, dirname){
  // book all histograms here
  // jets
  N_jets = book<TH1F>("N_jets", "N_{jets}", 20, 0, 20);
  N_PU = book<TH1F>("N_PU", "N_{PU}", 100, 0, 100);
  eta_jet1 = book<TH1F>("eta_jet1", "#eta^{jet 1}", 40, -2.5, 2.5);
  eta_jet2 = book<TH1F>("eta_jet2", "#eta^{jet 2}", 40, -2.5, 2.5);
  eta_jet3 = book<TH1F>("eta_jet3", "#eta^{jet 3}", 40, -2.5, 2.5);
  eta_jet4 = book<TH1F>("eta_jet4", "#eta^{jet 4}", 40, -2.5, 2.5);
  pt_jet1 = book<TH1F>("pt_jet1", "p_{T}^{jet 1}", 100, 0, 0);
  pt_jet2 = book<TH1F>("pt_jet2", "p_{T}^{jet 2}", 100, 0, 0);
  pt12 = book<TH1F>("pt12", "combined p_T", 100, 0, 0);
  eta12 = book<TH1F>("eta12", "combined #eta", 40, -2.5, 2.5);

  // combined jets
  cb_pt = book<TH1F>("cb_pt", "all jets p_T", 100, 0, 0);
  cb_eta = book<TH1F>("cb_eta", "all jets eta", 100, 0, 0);
  cb_m = book<TH1F>("cb_m", "all jets m", 100, 0, 0);
  cb_phi = book<TH1F>("cb_phi", "all jets phi", 100, 0, 0);
  cb_e = book<TH1F>("cb_e", "all jets E", 100, 0, 0);

  // Substructure
  SoftDropMass_1 = book<TH1F>("SoftDropMass_1", "M_{1}^{SD} [GeV/c^{2}]", 50,0,300);
  CHF_1 = book<TH1F>("CHF_1","CHF_{1}",100,0,1);
  TAU1_1 = book<TH1F>("TAU1_1","#tau_{1_{1}}",20,0,1);
  TAU2_1 = book<TH1F>("TAU2_1","#tau_{2_{1}}",20,0,1);
  Tau21_1 = book<TH1F>("Tau21_1", "#tau_{2_{1}}/#tau_{1_{1}}", 20,0,1);

  SoftDropMass_2 = book<TH1F>("SoftDropMass_2", "M_{2}^{SD} [GeV/c^{2}]", 50,0,300);
  CHF_2 = book<TH1F>("CHF_2","CHF_{2}",100,0,1);
  TAU1_2 = book<TH1F>("TAU1_2","#tau_{1_{2}}",20,0,1);
  TAU2_2 = book<TH1F>("TAU2_2","#tau_{2_{2}}",20,0,1);
  Tau21_2 = book<TH1F>("Tau21_2", "#tau_{2_{2}}/#tau_{1_{2}}", 20,0,1);

  invMass = book<TH1F>("invMass","M_{jj}-AK8 [GeV/c^{2}]",30,1000,7000);

  HADcharged_jet1 = book<TH1F>("HADcharged_jet1", "HADcharged_jet1", 100,0.0,1.0);
  HADneutral_jet1 = book<TH1F>("HADneutral_jet1", "HADneutral_jet1", 100,0.0,1.0);

  HADcharged_vs_eta_jet1 = book<TH2D>("HADcharged_vs_eta_jet1","HADcharged vs #eta; #eta; HADcharged",100,-6,6,100,0.0,1.0);
  HADneutral_vs_eta_jet1 = book<TH2D>("HADneutral_vs_eta_jet1","HADneutral vs #eta; #eta; HADneutral",100,-6,6,100,0.0,1.0);
  HADcharged_vs_PU_jet1 = book<TH2D>("HADcharged_vs_PU_jet1","HADcharged vs PU; PU; HADcharged",100,0,100,100,0.0,1.0);
  HADneutral_vs_PU_jet1 = book<TH2D>("HADneutral_vs_PU_jet1","HADneutral vs PU; PU; HADneutral",100,0,100,100,0.0,1.0);


  // leptons
  N_mu = book<TH1F>("N_mu", "N^{#mu}", 10, 0, 10);
  pt_mu = book<TH1F>("pt_mu", "p_{T}^{#mu} [GeV/c]", 40, 0, 200);
  eta_mu = book<TH1F>("eta_mu", "#eta^{#mu}", 40, -2.1, 2.1);
  reliso_mu = book<TH1F>("reliso_mu", "#mu rel. Iso", 40, 0, 0.5);

  // primary vertices
  N_pv = book<TH1F>("N_pv", "N^{PV}", 50, 0, 50);
}


void qstarHists::fill(const Event & event){
  // Don't forget to always use the weight when filling.
  double weight = event.weight;

  std::vector<TopJet> jets = *event.topjets;
  int Njets = jets.size();
  N_jets->Fill(Njets, weight);
  if(!event.isRealData)  N_PU->Fill(event.genInfo->pileup_TrueNumInteractions(), weight);

  if(Njets>=1){
    eta_jet1->Fill(jets[0].eta(), weight);
    pt_jet1->Fill(jets[0].pt(), weight);
    HADcharged_jet1->Fill(jets[0].chargedHadronEnergyFraction(), weight);
    HADneutral_jet1->Fill(jets[0].neutralHadronEnergyFraction(), weight);

    HADcharged_vs_eta_jet1->Fill(jets[0].eta(),jets[0].chargedHadronEnergyFraction(), weight);
    HADneutral_vs_eta_jet1->Fill(jets[0].eta(),jets[0].neutralHadronEnergyFraction(), weight);
    if(!event.isRealData){
      HADcharged_vs_PU_jet1->Fill(event.genInfo->pileup_TrueNumInteractions(),jets[0].chargedHadronEnergyFraction(), weight);
      HADneutral_vs_PU_jet1->Fill(event.genInfo->pileup_TrueNumInteractions(),jets[0].neutralHadronEnergyFraction(), weight);
    }
  }
  if(Njets>=2){
    auto v4 = jets[0].v4() + jets[1].v4();
    eta_jet2->Fill(jets[1].eta(), weight);
    pt_jet2->Fill(jets[1].pt(), weight);
    pt12->Fill(v4.Pt());
    eta12->Fill(v4.Eta());
  }
  if(Njets>=3){
    eta_jet3->Fill(jets[2].eta(), weight);
  }
  if(Njets>=4){
    eta_jet4->Fill(jets[3].eta(), weight);
  }

  // combined jets
  for (TopJet &jet : jets) {
    cb_pt->Fill(jet.pt(), weight);
    cb_eta->Fill(jet.eta(), weight);
    cb_m->Fill(jet.v4().M(), weight);
    cb_phi->Fill(jet.phi(), weight);
  }

  // Substructure
  if(jets.size()<1) return;

  if (jets.size() >= 2) {
    SoftDropMass_1->Fill(jets[0].softdropmass(), weight);
    SoftDropMass_2->Fill(jets[1].softdropmass(), weight);
  }
  float chf_1 = jets[0].chargedHadronEnergyFraction();
  CHF_1->Fill(chf_1, weight);
  float tau1_1 = jets[0].tau1();
  TAU1_1->Fill(tau1_1, weight);
  float tau2_1 = jets[0].tau2();
  TAU2_1->Fill(tau2_1, weight);
  float tau21_1 = tau2_1/tau1_1;
  Tau21_1->Fill(tau21_1, weight);

  float chf_2 = jets[1].chargedHadronEnergyFraction();
  CHF_2->Fill(chf_2, weight);
  float tau1_2 = jets[1].tau1();
  TAU1_2->Fill(tau1_2, weight);
  float tau2_2 = jets[1].tau2();
  TAU2_2->Fill(tau2_2, weight);
  float tau21_2 = tau2_2/tau1_2;
  Tau21_2->Fill(tau21_2, weight);

  float mass = inv_mass_safe(jets[0].v4() + jets[1].v4());
  invMass->Fill(mass, weight);

  // Muons
  int Nmuons = event.muons->size();
  N_mu->Fill(Nmuons, weight);
  for (const Muon & thismu : *event.muons){
      pt_mu->Fill(thismu.pt(), weight);
      eta_mu->Fill(thismu.eta(), weight);
      reliso_mu->Fill(thismu.relIso(), weight);
  }

  int Npvs = event.pvs->size();
  N_pv->Fill(Npvs, weight);
}

qstarHists::~qstarHists(){}
