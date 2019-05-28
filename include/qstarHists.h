#pragma once

#include "UHH2/core/include/Hists.h"
#include "TH1F.h"
#include "TH2D.h"

namespace uhh2examples {

/**  \brief Example class for booking and filling histograms
 * 
 * NOTE: This class uses the 'hist' method to retrieve histograms.
 * This requires a string lookup and is therefore slow if you have
 * many histograms. Therefore, it is recommended to use histogram
 * pointers as member data instead, like in 'common/include/ElectronHists.h'.
 */
class qstarHists: public uhh2::Hists {
public:
    // use the same constructor arguments as Hists for forwarding:
    qstarHists(uhh2::Context & ctx, const std::string & dirname);

    virtual void fill(const uhh2::Event & ev) override;
    virtual ~qstarHists();

private:
    TH1F *N_jets, *N_PU, *eta_jet1, *eta_jet2, *eta_jet3, *eta_jet4, *pt_jet1,
        *pt_jet2, *pt12, *eta12, *SoftDropMass_1, *CHF_1, *TAU1_1, *TAU2_1, *Tau21_1,
        *SoftDropMass_2, *CHF_2, *TAU1_2, *TAU2_2, *Tau21_2, *invMass,
        *N_mu, *pt_mu, *eta_mu, *reliso_mu, *N_pv, *cb_pt, *cb_eta,
        *cb_m, *cb_phi, *cb_e, *deta;
    TH2D *HADcharged_vs_eta_jet1, *HADneutral_vs_eta_jet1, *HADcharged_vs_PU_jet1,
        *HADneutral_vs_PU_jet1;
};

}
