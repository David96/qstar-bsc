#include "UHH2/qstar/include/qstarSelections.h"
#include "UHH2/core/include/Event.h"
#include "UHH2/common/include/Utils.h"
#include "UHH2/common/include/ObjectIdUtils.h"

#include <stdexcept>

using namespace uhh2examples;
using namespace uhh2;


EtaSelection::EtaSelection(float deta_max_): deta_max(deta_max_){}

bool EtaSelection::passes(const Event & event){
    assert(event.topjets); // if this fails, it probably means jets are not read in
    if(event.topjets->size() < 2) return false;
    const auto & jet0 = event.topjets->at(0);
    const auto & jet1 = event.topjets->at(1);
    return abs(jet0.eta() - jet1.eta()) < deta_max;
}

InvMassSelection::InvMassSelection(float invmass_min_) : invmass_min(invmass_min_){}

bool InvMassSelection::passes(const Event &event) {
    assert(event.topjets);
    if(event.topjets->size() < 2) return false;
    return inv_mass_safe(event.topjets->at(0).v4() + event.topjets->at(1).v4())
                    > invmass_min;
}


MuonVeto::MuonVeto(float deltaR_min_, const boost::optional<MuonId> &muid_): deltaR_min(deltaR_min_), muid(muid_){}

bool MuonVeto::passes(const Event & event){
    assert(event.topjets);
    assert(event.muons);
    if(muid) {
        for(const auto &muon : *event.muons) {
            for(const auto &topjet : *event.topjets) {
                return deltaR(topjet, muon) >= deltaR_min;
            }
        }
    }
    return true;
}

ElectronVeto::ElectronVeto(float deltaR_min_, const boost::optional<ElectronId> & eleid_)
                         : deltaR_min(deltaR_min_), eleid(eleid_){}

bool ElectronVeto::passes(const Event & event){
    assert(event.topjets);
    assert(event.electrons);
    if(eleid) {
        for(const auto &topjet : *event.topjets) {
            for(const auto &electron : *event.electrons) {
                return deltaR(topjet, electron) >= deltaR_min;
            }
        }
    }
    return true;
}

bool Pt1Selection::passes(const Event& event) {
    assert(event.topjets);
    if (event.topjets->size() == 0) return false;
    return event.topjets->at(0).pt() > pt_min;
}

void PtCleaner::process(Event &event) {
    using namespace std;
    vector<TopJet> topjets;
    vector<TopJet> &topjet_col = event.get(hndl);
    for (const TopJet &jet : *event.topjets) {
        if (!(jet.pt() > pt_min && jet.pt() < pt_max)){
            topjets.push_back(jet);
        }
    }
    std::swap(topjets, topjet_col);
}

bool SdmSelection::passes(const Event &event) {
    TopJet v_boson = event.topjets->at(0).softdropmass() > event.topjets->at(1).softdropmass() ?
                        event.topjets->at(0) : event.topjets->at(1);
    return v_boson.softdropmass() >= sdm_min && v_boson.softdropmass() <= sdm_max;
}

bool Tau21Selection::passes(const Event &event) {
    TopJet v_boson = event.topjets->at(0).softdropmass() > event.topjets->at(1).softdropmass() ?
                        event.topjets->at(0) : event.topjets->at(1);
    float tau21 = v_boson.tau2() / v_boson.tau1();
    return tau21 <= tau21_max;
}
