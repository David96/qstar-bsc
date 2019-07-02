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


class sidebandModule: public AnalysisModule {
public:

    explicit sidebandModule(Context & ctx);
    virtual bool process(Event & event) override;

private:
    bool isMC;

    std::unique_ptr<Selection> sdm_sel, tau21_sel;

    std::unique_ptr<Hists> h_nocuts, h_sdm;

    std::unique_ptr<uhh2::AnalysisModule> MCWeightModule;
    std::unique_ptr<uhh2::AnalysisModule> MCPileupReweightModule;
};

sidebandModule::sidebandModule(Context &ctx) {
    cout << "Post selection started…" << endl;

    h_nocuts.reset(new qstarHists(ctx, "NoCuts"));
    h_sdm.reset(new qstarHists(ctx, "SDM"));

    sdm_sel.reset(new SdmSelection(65, 105));
    tau21_sel.reset(new Tau21Selection(0.35, (SdmSelection*)sdm_sel.get()));

    isMC = ctx.get("dataset_type") == "MC";
    if (isMC) {
        cout << "Initialising lumi weight module" << endl;
        MCWeightModule.reset(new MCLumiWeight(ctx));
        MCPileupReweightModule.reset(new MCPileupReweight(ctx));
    }
}

bool sidebandModule::process(Event &event) {
    if (isMC) {
        MCWeightModule->process(event);
        MCPileupReweightModule->process(event);
    }
    h_nocuts->fill(event);

    if (event.topjets->size() >= 2 &&
            event.topjets->at(0).softdropmass() > 105 && event.topjets->at(1).softdropmass() > 105) {
        h_sdm->fill(event);
        return true;
    }

    return false;
}

UHH2_REGISTER_ANALYSIS_MODULE(sidebandModule)

}
