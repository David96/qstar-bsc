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

using namespace std;
using namespace uhh2;

// #define DEBUG

namespace uhh2examples {


class qstarPostSelection: public AnalysisModule {
public:

    explicit qstarPostSelection(Context & ctx);
    virtual bool process(Event & event) override;

private:

    std::unique_ptr<Selection> pt1_sel;

    std::unique_ptr<Hists> h_nocuts, h_pt1;

    std::unique_ptr<PtCleaner> topJetCleaner;
};

qstarPostSelection::qstarPostSelection(Context &ctx) {
    cout << "Post selection started…" << endl;

    pt1_sel.reset(new Pt1Selection(700.));

    h_nocuts.reset(new qstarHists(ctx, "NoCuts"));
    h_pt1.reset(new qstarHists(ctx, "Pt1"));

    topJetCleaner.reset(new PtCleaner(ctx, 400., 700.));
}

bool qstarPostSelection::process(Event &event) {
    h_nocuts->fill(event);

    // Remove jets with 400 < pt < 700 GeV
    topJetCleaner->process(event);
    sort_by_pt<TopJet>(*event.topjets);

    if (!pt1_sel->passes(event)) return false;
    h_pt1->fill(event);

    return true;
}

UHH2_REGISTER_ANALYSIS_MODULE(qstarPostSelection)

}
