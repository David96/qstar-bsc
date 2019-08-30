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


class qstarLP: public AnalysisModule {
public:

    explicit qstarLP(Context & ctx);
    virtual bool process(Event & event) override;

private:
    bool isMC, deepBoostedTagger;

    std::unique_ptr<Selection> sdm_sel, tau21_sel_1, tau21_sel_2, vvsqcd_sel;

    std::unique_ptr<Hists> h_nocuts, h_tau21, h_deep_boosted;

    std::unique_ptr<uhh2::AnalysisModule> MCWeightModule;
    std::unique_ptr<uhh2::AnalysisModule> MCPileupReweightModule;
};

qstarLP::qstarLP(Context &ctx) {
    cout << "Post selection started…" << endl;

    h_nocuts.reset(new qstarHists(ctx, "NoCuts"));

    deepBoostedTagger = ctx.get("use_deep_boosted", "false").compare("true") == 0;

    sdm_sel.reset(new SdmSelection(65, 105));

    if (deepBoostedTagger) {
        float vvsqcd_min = stof(ctx.get("vvsqcd_min", "0.85"));
        cout << "Using deep boosted with vvsqcd_min = " << vvsqcd_min<< endl;
        vvsqcd_sel.reset(new VvsQCDSelection(vvsqcd_min, (SdmSelection*)sdm_sel.get()));
        h_deep_boosted.reset(new qstarHists(ctx, "deep_boosted"));
    } else {
        float tau_max = stof(ctx.get("tau21_sel", "0.35"));
        tau21_sel_1.reset(new Tau21Selection(0.35, (SdmSelection*)sdm_sel.get()));
        tau21_sel_2.reset(new Tau21Selection(0.75, (SdmSelection*)sdm_sel.get()));
        h_tau21.reset(new qstarHists(ctx, "tau21"));
    }

    isMC = ctx.get("dataset_type") == "MC";
    if (isMC) {
        cout << "Initialising lumi weight module" << endl;
        MCWeightModule.reset(new MCLumiWeight(ctx));
        MCPileupReweightModule.reset(new MCPileupReweight(ctx));
    }
}

bool qstarLP::process(Event &event) {
    if (isMC) {
        MCWeightModule->process(event);
        MCPileupReweightModule->process(event);
    }
    h_nocuts->fill(event);

    if (!sdm_sel->passes(event)) return false;

    if (deepBoostedTagger) {
        if (vvsqcd_sel->passes(event)) return false;
        h_deep_boosted->fill(event);
    } else {
        if (!tau21_sel_1->passes(event) && tau21_sel_2->passes(event)) return false;
        h_tau21->fill(event);
    }

    return true;
}

UHH2_REGISTER_ANALYSIS_MODULE(qstarLP)

}
