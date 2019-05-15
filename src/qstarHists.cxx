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
  book<TH1F>("N_jets", "N_{jets}", 20, 0, 20);
  book<TH1F>("N_PU", "N_{PU}", 100, 0, 100);
  book<TH1F>("eta_jet1", "#eta^{jet 1}", 40, -2.5, 2.5);
  book<TH1F>("pt_jet1", "p_{T}^{jet 1}", 100, 0, 0);
  book<TH1F>("eta_jet2", "#eta^{jet 2}", 40, -2.5, 2.5);
  book<TH1F>("eta_jet3", "#eta^{jet 3}", 40, -2.5, 2.5);
  book<TH1F>("eta_jet4", "#eta^{jet 4}", 40, -2.5, 2.5);

  //substructure
  book<TH1F>("SoftDropMass_1", "M_{1}^{SD} [GeV/c^{2}]", 50,0,300);
  book<TH1F>("CHF_1","CHF_{1}",100,0,1);
  book<TH1F>("TAU1_1","#tau_{1_{1}}",20,0,1);
  book<TH1F>("TAU2_1","#tau_{2_{1}}",20,0,1);
  book<TH1F>("Tau21_1", "#tau_{2_{1}}/#tau_{1_{1}}", 20,0,1);

  book<TH1F>("SoftDropMass_2", "M_{2}^{SD} [GeV/c^{2}]", 50,0,300);
  book<TH1F>("CHF_2","CHF_{2}",100,0,1);
  book<TH1F>("TAU1_2","#tau_{1_{2}}",20,0,1);
  book<TH1F>("TAU2_2","#tau_{2_{2}}",20,0,1);
  book<TH1F>("Tau21_2", "#tau_{2_{2}}/#tau_{1_{2}}", 20,0,1);

  book<TH1F>("invMass","M_{jj}-AK8 [GeV/c^{2}]",30,1000,7000);

  book<TH1F>("HADcharged_jet1", "HADcharged_jet1", 100,0.0,1.0);
  book<TH1F>("HADneutral_jet1", "HADneutral_jet1", 100,0.0,1.0);

  book<TH2D>("HADcharged_vs_eta_jet1","HADcharged vs #eta; #eta; HADcharged",100,-6,6,100,0.0,1.0);
  book<TH2D>("HADneutral_vs_eta_jet1","HADneutral vs #eta; #eta; HADneutral",100,-6,6,100,0.0,1.0);
  book<TH2D>("HADcharged_vs_PU_jet1","HADcharged vs PU; PU; HADcharged",100,0,100,100,0.0,1.0);
  book<TH2D>("HADneutral_vs_PU_jet1","HADneutral vs PU; PU; HADneutral",100,0,100,100,0.0,1.0);


  // leptons
  book<TH1F>("N_mu", "N^{#mu}", 10, 0, 10);
  book<TH1F>("pt_mu", "p_{T}^{#mu} [GeV/c]", 40, 0, 200);
  book<TH1F>("eta_mu", "#eta^{#mu}", 40, -2.1, 2.1);
  book<TH1F>("reliso_mu", "#mu rel. Iso", 40, 0, 0.5);

  // primary vertices
  book<TH1F>("N_pv", "N^{PV}", 50, 0, 50);
}


void qstarHists::fill(const Event & event){
  // fill the histograms. Please note the comments in the header file:
  // 'hist' is used here a lot for simplicity, but it will be rather
  // slow when you have many histograms; therefore, better
  // use histogram pointers as members as in 'UHH2/common/include/ElectronHists.h'

  // Don't forget to always use the weight when filling.
  double weight = event.weight;

  std::vector<TopJet> jets = *event.topjets;
  int Njets = jets.size();
  hist("N_jets")->Fill(Njets, weight);
  if(!event.isRealData)  hist("N_PU")->Fill(event.genInfo->pileup_TrueNumInteractions(), weight);

  if(Njets>=1){
    hist("eta_jet1")->Fill(jets[0].eta(), weight);
    hist("pt_jet1")->Fill(jets[0].pt(), weight);
    hist("HADcharged_jet1")->Fill(jets[0].chargedHadronEnergyFraction(), weight);
    hist("HADneutral_jet1")->Fill(jets[0].neutralHadronEnergyFraction(), weight);

    ((TH2D*)hist("HADcharged_vs_eta_jet1"))->Fill(jets[0].eta(),jets[0].chargedHadronEnergyFraction(), weight);
    ((TH2D*)hist("HADneutral_vs_eta_jet1"))->Fill(jets[0].eta(),jets[0].neutralHadronEnergyFraction(), weight);
    if(!event.isRealData){
      ((TH2D*)hist("HADcharged_vs_PU_jet1"))->Fill(event.genInfo->pileup_TrueNumInteractions(),jets[0].chargedHadronEnergyFraction(), weight);
      ((TH2D*)hist("HADneutral_vs_PU_jet1"))->Fill(event.genInfo->pileup_TrueNumInteractions(),jets[0].neutralHadronEnergyFraction(), weight);
    }
  }
  if(Njets>=2){
    hist("eta_jet2")->Fill(jets[1].eta(), weight);
  }
  if(Njets>=3){
    hist("eta_jet3")->Fill(jets[2].eta(), weight);
  }
  if(Njets>=4){
    hist("eta_jet4")->Fill(jets[3].eta(), weight);
  }

  // Substructure
  if(jets.size()<1) return;

  if (jets.size() >= 2) {
    hist("SoftDropMass_1")->Fill(jets[0].softdropmass(), weight);
    hist("SoftDropMass_2")->Fill(jets[1].softdropmass(), weight);
  }
  float chf_1 = jets[0].chargedHadronEnergyFraction();
  hist("CHF_1")->Fill(chf_1, weight);
  float tau1_1 = jets[0].tau1();
  hist("TAU1_1")->Fill(tau1_1, weight);
  float tau2_1 = jets[0].tau2();
  hist("TAU2_1")->Fill(tau2_1, weight);
  float tau21_1 = tau2_1/tau1_1;
  hist("Tau21_1")->Fill(tau21_1, weight);

  float chf_2 = jets[1].chargedHadronEnergyFraction();
  hist("CHF_2")->Fill(chf_2, weight);
  float tau1_2 = jets[1].tau1();
  hist("TAU1_2")->Fill(tau1_2, weight);
  float tau2_2 = jets[1].tau2();
  hist("TAU2_2")->Fill(tau2_2, weight);
  float tau21_2 = tau2_2/tau1_2;
  hist("Tau21_2")->Fill(tau21_2, weight);

  //      float mass = (jets[0].v4() + jets[1].v4()).M();
  float mass = inv_mass_safe(jets[0].v4() + jets[1].v4());
  hist("invMass")->Fill(mass, weight);

  int Nmuons = event.muons->size();
  hist("N_mu")->Fill(Nmuons, weight);
  for (const Muon & thismu : *event.muons){
      hist("pt_mu")->Fill(thismu.pt(), weight);
      hist("eta_mu")->Fill(thismu.eta(), weight);
      hist("reliso_mu")->Fill(thismu.relIso(), weight);
  }

  int Npvs = event.pvs->size();
  hist("N_pv")->Fill(Npvs, weight);
}

qstarHists::~qstarHists(){}
