#include <iostream>
#include <memory>

#include "UHH2/core/include/AnalysisModule.h"
#include "UHH2/core/include/Event.h"
#include "UHH2/common/include/CommonModules.h"
#include "UHH2/common/include/CleaningModules.h"
#include "UHH2/common/include/ElectronHists.h"
#include "UHH2/common/include/MuonHists.h"
#include "UHH2/common/include/NSelections.h"
#include "UHH2/common/include/JetCorrections.h"
#include "UHH2/qstar/include/qstarSelections.h"
#include "UHH2/qstar/include/qstarHists.h"
#include "UHH2/common/include/JetHists.h"
#include "UHH2/common/include/Utils.h"
#include "UHH2/common/include/PrintingModules.h"
#include "UHH2/common/include/ObjectIdUtils.h"
#include "UHH2/common/include/MuonIds.h"
#include "UHH2/common/include/ElectronIds.h"
#include "UHH2/common/include/MCWeight.h"

using namespace std;
using namespace uhh2;

// #define DEBUG

namespace uhh2examples {


class qstarPostSelection: public AnalysisModule {
public:

    explicit qstarPostSelection(Context & ctx);
    virtual bool process(Event & event) override;

private:
    bool isMC, deepBoostedTagger;

    std::unique_ptr<Selection> sdm_sel, tau21_sel, vvsqcd_sel;

    std::unique_ptr<Hists> h_nocuts, h_sdm, h_tau21, h_deep_boosted;

    std::unique_ptr<uhh2::AnalysisModule> MCWeightModule;
    std::unique_ptr<uhh2::AnalysisModule> MCPileupReweightModule;
};

qstarPostSelection::qstarPostSelection(Context &ctx) {
    cout << "Post selection started…" << endl;

    h_nocuts.reset(new qstarHists(ctx, "NoCuts"));

    deepBoostedTagger = ctx.get("use_deep_boosted", "false").compare("true") == 0;

    sdm_sel.reset(new SdmSelection(65, 105));
    h_sdm.reset(new qstarHists(ctx, "SDM"));

    if (deepBoostedTagger) {
        float vvsqcd_min = stof(ctx.get("vvsqcd_min", "0.3"));
        cout << "Using deep boosted with vvsqcd_min = " << vvsqcd_min<< endl;
        vvsqcd_sel.reset(new VvsQCDSelection(vvsqcd_min, (SdmSelection*)sdm_sel.get()));
        h_deep_boosted.reset(new qstarHists(ctx, "deep_boosted"));
    } else {

        float tau_max = stof(ctx.get("tau21_sel", "0.35"));
        tau21_sel.reset(new Tau21Selection(tau_max, (SdmSelection*)sdm_sel.get()));
        h_tau21.reset(new qstarHists(ctx, "tau21"));
    }

    isMC = ctx.get("dataset_type") == "MC";
    if (isMC) {
        cout << "Initialising lumi weight module" << endl;
        MCWeightModule.reset(new MCLumiWeight(ctx));
        MCPileupReweightModule.reset(new MCPileupReweight(ctx));
    }
}

bool qstarPostSelection::process(Event &event) {
    if (isMC) {
        MCWeightModule->process(event);
        MCPileupReweightModule->process(event);
    }
    h_nocuts->fill(event);

    if (!sdm_sel->passes(event)) return false;
    h_sdm->fill(event);

    if (deepBoostedTagger) {
        if (!vvsqcd_sel->passes(event)) return false;
        h_deep_boosted->fill(event);
    } else {
        if (!tau21_sel->passes(event)) return false;
        h_tau21->fill(event);
    }

    return true;
}

UHH2_REGISTER_ANALYSIS_MODULE(qstarPostSelection)

}
