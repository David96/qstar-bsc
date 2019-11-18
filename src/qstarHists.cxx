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
  N_jets = book<TH1F>("N_jets", "N_{jets}", 10, 0, 10);
  N_PU = book<TH1F>("N_PU", "N_{PU}", 100, 0, 100);
  eta_jet1 = book<TH1F>("eta_jet1", "#eta^{jet 1}", 40, -2.5, 2.5);
  eta_jet2 = book<TH1F>("eta_jet2", "#eta^{jet 2}", 40, -2.5, 2.5);
  eta_jet3 = book<TH1F>("eta_jet3", "#eta^{jet 3}", 40, -2.5, 2.5);
  eta_jet4 = book<TH1F>("eta_jet4", "#eta^{jet 4}", 40, -2.5, 2.5);
  pt_jet1 = book<TH1F>("pt_jet1", "p_{T}^{jet 1} [GeV]", 100, 150, 3000);
  pt_jet2 = book<TH1F>("pt_jet2", "p_{T}^{jet 2} [GeV]", 100, 150, 3000);
  pt12 = book<TH1F>("pt12", "p_{T}^{1+2} [GeV]", 100, 10, 3000);
  eta12 = book<TH1F>("eta12", "#eta^{1+2}", 40, -3.2, 3.2);
  deta = book<TH1F>("deta", "#Delta #eta^{1,2}", 80, 0, 4);
  dphi = book<TH1F>("dphi", "#Delta #phi^{1,2}", 40, 0, 5.0);

  // combined jets
  cb_pt = book<TH1F>("cb_pt", "p_{T} [GeV/c^{2}]", 100, 150, 3000);
  cb_eta = book<TH1F>("cb_eta", "#eta", 100, -3.2, 3.2);
  cb_m = book<TH1F>("cb_m", "m [GeV]", 100, 0, 300);
  cb_phi = book<TH1F>("cb_phi", "#phi", 100, -3.2, 3.2);
  cb_e = book<TH1F>("cb_e", "E [GeV]", 100, 0, 3500);

  // Substructure
  SoftDropMass_1 = book<TH1F>("SoftDropMass_1", "M_{1}^{SD} [GeV/c^{2}]", 60,0,210);
  CHF_1 = book<TH1F>("CHF_1","CHF_{1}",100,0,1);
  TAU1_1 = book<TH1F>("TAU1_1","#tau_{1_{1}}",20,0,1);
  TAU2_1 = book<TH1F>("TAU2_1","#tau_{2_{1}}",20,0,1);
  Tau21_1 = book<TH1F>("Tau21_1", "#tau_{2_{1}}/#tau_{1_{1}}", 20,0,1);

  SoftDropMass_2 = book<TH1F>("SoftDropMass_2", "M_{2}^{SD} [GeV/c^{2}]", 60,0,210);
  CHF_2 = book<TH1F>("CHF_2","CHF_{2}",100,0,1);
  TAU1_2 = book<TH1F>("TAU1_2","#tau_{1_{2}}",20,0,1);
  TAU2_2 = book<TH1F>("TAU2_2","#tau_{2_{2}}",20,0,1);
  Tau21_2 = book<TH1F>("Tau21_2", "#tau_{2_{2}}/#tau_{1_{2}}", 20,0,1);

  invMass = book<TH1F>("invMass","M_{jj}-AK8 [GeV/c^{2}]",38,1000,8600);
  invMass_1GeV = book<TH1F>("invMass_1GeV","M_{jj}-AK8 [GeV/c^{2}]",7600,1000,8600);

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
  N_pv = book<TH1F>("N_pv", "N^{PV}", 100, 0, 100);

  tagger_1 = book<TH1F>("uncorrelatedDeepBoosted_WvsQCD_1", "WvsQCD jet 1", 100, 0, 1);
  tagger_2 = book<TH1F>("uncorrelatedDeepBoosted_WvsQCD_2", "WvsQCD jet 2", 100, 0, 1);
}


void qstarHists::fill(const Event & event){
  // Don't forget to always use the weight when filling.
  double weight = event.weight;

  std::vector<TopJet> jets = *event.topjets;
  int Njets = jets.size();
  N_jets->Fill(Njets, weight);
  N_jets->SetXTitle(N_jets->GetTitle());
  N_jets->SetYTitle("#events");
  if(!event.isRealData)  {
    N_PU->Fill(event.genInfo->pileup_TrueNumInteractions(), weight);

    N_PU->SetXTitle(N_PU->GetTitle());
    N_PU->SetYTitle("#events");
  }

  if(Njets>=1){
    eta_jet1->Fill(jets[0].eta(), weight);
    pt_jet1->Fill(jets[0].pt(), weight);

    HADcharged_vs_eta_jet1->Fill(jets[0].eta(),jets[0].chargedHadronEnergyFraction(), weight);
    HADcharged_vs_eta_jet1->SetXTitle("#eta");
    HADcharged_vs_eta_jet1->SetYTitle("HADcharged");

    HADneutral_vs_eta_jet1->Fill(jets[0].eta(),jets[0].neutralHadronEnergyFraction(), weight);
    HADneutral_vs_eta_jet1->SetXTitle("#eta");
    HADneutral_vs_eta_jet1->SetYTitle("HADneutral");
    if(!event.isRealData){
      HADcharged_vs_PU_jet1->Fill(event.genInfo->pileup_TrueNumInteractions(),jets[0].chargedHadronEnergyFraction(), weight);
      HADcharged_vs_PU_jet1->SetXTitle("Pileup");
      HADcharged_vs_PU_jet1->SetYTitle("HADcharged");
      HADneutral_vs_PU_jet1->Fill(event.genInfo->pileup_TrueNumInteractions(),jets[0].neutralHadronEnergyFraction(), weight);
      HADneutral_vs_PU_jet1->SetXTitle("Pileup");
      HADneutral_vs_PU_jet1->SetYTitle("HADneutral");
    }

    eta_jet1->SetXTitle(eta_jet1->GetTitle());
    eta_jet1->SetYTitle("#events");
    pt_jet1->SetXTitle(pt_jet1->GetTitle());
    pt_jet1->SetYTitle("#events");
  }
  if(Njets>=2){
    auto v4 = jets[0].v4() + jets[1].v4();
    eta_jet2->Fill(jets[1].eta(), weight);
    pt_jet2->Fill(jets[1].pt(), weight);
    pt12->Fill(v4.Pt(), weight);
    eta12->Fill(v4.Eta(), weight);
    deta->Fill(abs(jets[0].eta() - jets[1].eta()), weight);
    dphi->Fill(abs(jets[0].phi() - jets[1].phi()), weight);

    eta_jet2->SetXTitle(eta_jet2->GetTitle());
    eta_jet2->SetYTitle("#events");
    pt_jet2->SetXTitle(pt_jet2->GetTitle());
    pt_jet2->SetYTitle("#events");
    pt12->SetXTitle(pt12->GetTitle());
    pt12->SetYTitle("#events");
    eta12->SetXTitle(eta12->GetTitle());
    eta12->SetYTitle("#events");
    deta->SetXTitle(deta->GetTitle());
    deta->SetYTitle("#events");
    dphi->SetXTitle(deta->GetTitle());
    dphi->SetYTitle("#events");
  }
  if(Njets>=3){
    eta_jet3->Fill(jets[2].eta(), weight);
    eta_jet3->SetXTitle(eta_jet3->GetTitle());
    eta_jet3->SetYTitle("#events");
  }
  if(Njets>=4){
    eta_jet4->Fill(jets[3].eta(), weight);
    eta_jet4->SetXTitle(eta_jet4->GetTitle());
    eta_jet4->SetYTitle("#events");
  }

  // combined jets
  for (TopJet &jet : jets) {
    cb_pt->Fill(jet.pt(), weight);
    cb_eta->Fill(jet.eta(), weight);
    cb_m->Fill(jet.v4().M(), weight);
    cb_phi->Fill(jet.phi(), weight);
    cb_e->Fill(jet.v4().E(), weight);

    cb_pt->SetXTitle(cb_pt->GetTitle());
    cb_pt->SetYTitle("#events");
    cb_eta->SetXTitle(cb_eta->GetTitle());
    cb_eta->SetYTitle("#events");
    cb_m->SetXTitle(cb_m->GetTitle());
    cb_m->SetYTitle("#events");
    cb_phi->SetXTitle(cb_phi->GetTitle());
    cb_phi->SetYTitle("#events");
    cb_e->SetXTitle(cb_e->GetTitle());
    cb_e->SetYTitle("#events");
  }

  // Substructure
  if(jets.size()<1) return;

  if (jets.size() >= 2) {
    SoftDropMass_1->Fill(jets[0].softdropmass(), weight);
    SoftDropMass_1->SetXTitle(SoftDropMass_1->GetTitle());
    SoftDropMass_1->SetYTitle("#events");

    SoftDropMass_2->Fill(jets[1].softdropmass(), weight);
    SoftDropMass_2->SetXTitle(SoftDropMass_2->GetTitle());
    SoftDropMass_2->SetYTitle("#events");

    float chf_1 = jets[0].chargedHadronEnergyFraction();
    CHF_1->Fill(chf_1, weight);
    float tau1_1 = jets[0].tau1();
    TAU1_1->Fill(tau1_1, weight);
    float tau2_1 = jets[0].tau2();
    TAU2_1->Fill(tau2_1, weight);
    float tau21_1 = tau2_1/tau1_1;
    Tau21_1->Fill(tau21_1, weight);

    CHF_1->SetXTitle(CHF_1->GetTitle());
    CHF_1->SetYTitle("#events");
    TAU1_1->SetXTitle(TAU1_1->GetTitle());
    TAU1_1->SetYTitle("#events");
    TAU2_1->SetXTitle(TAU2_1->GetTitle());
    TAU2_1->SetYTitle("#events");
    Tau21_1->SetXTitle(Tau21_1->GetTitle());
    Tau21_1->SetYTitle("#events");

    float chf_2 = jets[1].chargedHadronEnergyFraction();
    CHF_2->Fill(chf_2, weight);
    float tau1_2 = jets[1].tau1();
    TAU1_2->Fill(tau1_2, weight);
    float tau2_2 = jets[1].tau2();
    TAU2_2->Fill(tau2_2, weight);
    float tau21_2 = tau2_2/tau1_2;
    Tau21_2->Fill(tau21_2, weight);

    CHF_2->SetXTitle(CHF_2->GetTitle());
    CHF_2->SetYTitle("#events");
    TAU1_2->SetXTitle(TAU1_2->GetTitle());
    TAU1_2->SetYTitle("#events");
    TAU2_2->SetXTitle(TAU2_2->GetTitle());
    TAU2_2->SetYTitle("#events");
    Tau21_2->SetXTitle(Tau21_2->GetTitle());
    Tau21_2->SetYTitle("#events");

    float mass = inv_mass_safe(jets[0].v4() + jets[1].v4());
    invMass->Fill(mass, weight);

    invMass->SetXTitle(invMass->GetTitle());
    invMass->SetYTitle("#events");

    invMass_1GeV->Fill(mass, weight);

    invMass_1GeV->SetXTitle(invMass_1GeV->GetTitle());
    invMass_1GeV->SetYTitle("#events");

    tagger_1->Fill(jets[0].btag_MassDecorrelatedDeepBoosted_WvsQCD(), weight);
    tagger_2->Fill(jets[1].btag_MassDecorrelatedDeepBoosted_WvsQCD(), weight);

    tagger_1->SetXTitle(tagger_1->GetTitle());
    tagger_2->SetXTitle(tagger_2->GetTitle());
    tagger_1->SetYTitle("WvsQCD");
    tagger_2->SetYTitle("WvsQCD");
  }

  // Muons
  int Nmuons = event.muons->size();
  N_mu->Fill(Nmuons, weight);
  N_mu->SetXTitle(N_mu->GetTitle());
  N_mu->SetYTitle("#events");
  for (const Muon & thismu : *event.muons){
      pt_mu->Fill(thismu.pt(), weight);
      eta_mu->Fill(thismu.eta(), weight);
      reliso_mu->Fill(thismu.relIso(), weight);
  }

  pt_mu->SetXTitle(pt_mu->GetTitle());
  pt_mu->SetYTitle("#events");
  eta_mu->SetXTitle(eta_mu->GetTitle());
  eta_mu->SetYTitle("#events");
  reliso_mu->SetXTitle(reliso_mu->GetTitle());
  reliso_mu->SetYTitle("#events");

  int Npvs = event.pvs->size();
  N_pv->Fill(Npvs, weight);
  N_pv->SetXTitle(N_pv->GetTitle());
  N_pv->SetYTitle("#events");
}

qstarHists::~qstarHists(){}
