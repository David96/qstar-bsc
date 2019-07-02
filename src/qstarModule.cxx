#include <iostream>
#include <memory>

#include "UHH2/common/include/CleaningModules.h"
#include "UHH2/common/include/CommonModules.h"
#include "UHH2/common/include/ElectronHists.h"
#include "UHH2/common/include/ElectronIds.h"
#include "UHH2/common/include/JetCorrections.h"
#include "UHH2/common/include/JetHists.h"
#include "UHH2/common/include/MCWeight.h"
#include "UHH2/common/include/MuonHists.h"
#include "UHH2/common/include/MuonIds.h"
#include "UHH2/common/include/NSelections.h"
#include "UHH2/common/include/ObjectIdUtils.h"
#include "UHH2/common/include/PrintingModules.h"
#include "UHH2/common/include/Utils.h"
#include "UHH2/core/include/AnalysisModule.h"
#include "UHH2/core/include/Event.h"
#include "UHH2/qstar/include/qstarHists.h"
#include "UHH2/qstar/include/qstarSelections.h"

using namespace std;
using namespace uhh2;

// #define DEBUG

namespace uhh2examples {

/** \brief Basic analysis example of an AnalysisModule (formerly 'cycle') in UHH2
 *
 * This is the central class which calls other AnalysisModules, Hists or Selection classes.
 * This AnalysisModule, in turn, is called (via AnalysisModuleRunner) by SFrame.
 */
class qstarModule: public AnalysisModule {
public:

    explicit qstarModule(Context & ctx);
    virtual bool process(Event & event) override;

private:
    bool isMC;

    std::unique_ptr<CommonModules> common;

    std::unique_ptr<TopJetCleaner> topJetCleaner;

    std::unique_ptr<TopJetCorrector> jet_corrector;

    std::unique_ptr<TopJetCorrector> jet_corrector_A;
    std::unique_ptr<TopJetCorrector> jet_corrector_B;
    std::unique_ptr<TopJetCorrector> jet_corrector_C;
    std::unique_ptr<TopJetCorrector> jet_corrector_D;

    std::unique_ptr<GenericJetResolutionSmearer> jet_EResSmearer;

    std::unique_ptr<SoftDropMassCalculator> sdmCalc;

    // declare the Selections to use. Use unique_ptr to ensure automatic call of delete in the destructor,
    // to avoid memory leaks.
    std::unique_ptr<Selection> njet_sel, eta_sel, invmass_sel, muon_veto, ele_veto;

    // store the Hists collection as member variables. Again, use unique_ptr to avoid memory leaks.
    std::unique_ptr<Hists> h_nocuts, h_common, h_cleaner, h_corrections, h_njet,
        h_eta, h_muon_veto, h_ele_veto, h_invmass;

    std::unique_ptr<Hists> h_muon_before, h_muon_after, h_electron_before, h_electron_after;

    std::unique_ptr<uhh2::AnalysisModule> MCWeightModule;
    std::unique_ptr<MCPileupReweight> MCPileupReweightModule;

    std::unique_ptr<GenParticlesPrinter> printer;

    const int runnr_2018_Ab = 315252;
    const int runnr_2018_Ae = 316995;
    const int runnr_2018_Bb = 317080;
    const int runnr_2018_Be = 319310;
    const int runnr_2018_Cb = 319337;
    const int runnr_2018_Ce = 320065;
    const int runnr_2018_Db = 320673;
    const int runnr_2018_De = 325175;
};


qstarModule::qstarModule(Context & ctx){
    // In the constructor, the typical tasks are to initialize the
    // member variables, in particular the AnalysisModules such as
    // CommonModules or some cleaner module, Selections and Hists.
    // But you can do more and e.g. access the configuration, as shown below.

    // If needed, access the configuration of the module here, e.g.:
    // string testvalue = ctx.get("TestKey", "<not set>");
    // cout << "TestKey in the configuration was: " << testvalue << endl;

    // If running in SFrame, the keys "dataset_version", "dataset_type", "dataset_lumi",
    // and "target_lumi" are set to the according values in the xml file. For CMSSW, these are
    // not set automatically, but can be set in the python config file.
    for(auto & kv : ctx.get_all()){
        cout << " " << kv.first << " = " << kv.second << endl;
    }

    // 1. setup other modules. CommonModules and the JetCleaner:
    common.reset(new CommonModules());
    common->switch_jetlepcleaner(false);
    common->disable_jetpfidfilter();
    common->disable_jec();
    common->disable_jersmear();
    common->init(ctx);
    topJetCleaner.reset(new TopJetCleaner(ctx, PtEtaCut(200., 2.4)));

    const string jec_tag = "Autumn18";
    const string jec_ver = "8";
    const string ResolutionFileName = "2018/Autumn18_V4_MC_PtResolution_AK8PFPuppi.txt";
    const string jec_jet_coll_AK8puppi = "AK8PFPuppi";
    isMC = ctx.get("dataset_type") == "MC";

    std::cout << "USING "<< "?" << " MC JEC: "<< jec_tag << " V" << jec_ver << std::endl;
    std::cout << "for the following jet collections: " << jec_jet_coll_AK8puppi << std::endl;
    std::cout << "Smearing: " << jec_jet_coll_AK8puppi << " with "<< ResolutionFileName << std::endl;

    if (isMC) {
        jet_corrector.reset(new TopJetCorrector(ctx, JERFiles::Autumn18_V8_L123_AK8PFPuppi_MC));
        jet_EResSmearer.reset(new GenericJetResolutionSmearer(ctx,"topjets","gentopjets",
                    JERSmearing::SF_13TeV_Autumn18_RunABCD_V4, ResolutionFileName));

        // Needed to save weight_pu branch in root file
        MCWeightModule.reset(new MCLumiWeight(ctx));
        MCPileupReweightModule.reset(new MCPileupReweight(ctx));
    } else {
        jet_corrector_A.reset(new TopJetCorrector(ctx, JERFiles::Autumn18_V8_A_L123_noRes_AK8PFPuppi_DATA));
        jet_corrector_B.reset(new TopJetCorrector(ctx, JERFiles::Autumn18_V8_B_L123_noRes_AK8PFPuppi_DATA));
        jet_corrector_C.reset(new TopJetCorrector(ctx, JERFiles::Autumn18_V8_C_L123_noRes_AK8PFPuppi_DATA));
        jet_corrector_D.reset(new TopJetCorrector(ctx, JERFiles::Autumn18_V8_D_L123_noRes_AK8PFPuppi_DATA));
    }

    sdmCalc.reset(new SoftDropMassCalculator(ctx, true,
                "/nfs/dust/cms/user/lepplada/UHH2/CMSSW_10_2_10/src/UHH2/common/data/2018/puppiCorr.root", "topjets"));

    // note that the JetCleaner is only kept for the sake of example;
    // instead of constructing a jetcleaner explicitly,
    // the cleaning can also be achieved with less code via CommonModules with:
    // common->set_jet_id(PtEtaCut(30.0, 2.4));
    // before the 'common->init(ctx)' line.

    // 2. set up selections
    njet_sel.reset(new NTopJetSelection(2)); // see common/include/NSelections.h
    eta_sel.reset(new EtaSelection(1.3)); // see qstarSelections
    invmass_sel.reset(new InvMassSelection());

    MuonId MuId  = AndId<Muon>(MuonID(Muon::CutBasedIdTight), PtEtaCut(30., 2.4), MuonID(Muon::TkIsoLoose)); //changed for 102X
    ElectronId EleId = AndId<Electron>(ElectronID_HEEP_RunII_25ns, PtEtaCut(35., 2.5));

    muon_veto.reset(new MuonVeto(MuId, 0.8));
    ele_veto.reset(new ElectronVeto(EleId, 0.8));

    // 3. Set up Hists classes:
    h_nocuts.reset(new qstarHists(ctx, "NoCuts"));
    h_common.reset(new qstarHists(ctx, "common"));
    h_muon_veto.reset(new qstarHists(ctx, "muon_veto"));
    h_ele_veto.reset(new qstarHists(ctx, "ele_veto"));
    h_corrections.reset(new qstarHists(ctx, "Corrections"));
    h_cleaner.reset(new qstarHists(ctx, "Cleaner"));
    h_njet.reset(new qstarHists(ctx, "Njet"));
    h_eta.reset(new qstarHists(ctx, "Eta"));
    h_invmass.reset(new qstarHists(ctx, "invmass"));

    h_muon_before.reset(new MuonHists(ctx, "muon_before"));
    h_muon_after.reset(new MuonHists(ctx, "muon_after"));
    h_electron_before.reset(new ElectronHists(ctx, "electron_before"));
    h_electron_after.reset(new ElectronHists(ctx, "electron_after"));

#ifdef DEBUG
    printer.reset(new GenParticlesPrinter(ctx));
#endif
}

bool qstarModule::process(Event & event) {
    // This is the main procedure, called for each event. Typically,
    // do some pre-processing by calling the modules' process method
    // of the modules constructed in the constructor (1).
    // Then, test whether the event passes some selection and -- if yes --
    // use it to fill the histograms (2).
    // Finally, decide whether or not to keep the event in the output (3);
    // this is controlled by the return value of this method: If it
    // returns true, the event is kept; if it returns false, the event
    // is thrown away.

#ifdef DEBUG
    cout << "qstarModule: Starting to process event (runid, eventid) = ("
         << event.run << ", " << event.event << "); weight = " << event.weight << endl;
    //printer->process(event);
#endif

    h_nocuts->fill(event);

    // 1. run all modules other modules.
    if (!common->process(event)) {
        return false;
    }
    // Resort in case, after the common module changes, the first jet is no
    // longer the one with the highest pt. Should be done after all changes that
    // could affect that order
    sort_by_pt<TopJet>(*event.topjets);
    sdmCalc->process(event);
    h_common->fill(event);

    h_muon_before->fill(event);

#ifdef DEBUG
    cout << "Calling muon veto" << endl;
#endif
    if (!muon_veto->passes(event)) return false;
    h_muon_veto->fill(event);
    h_muon_after->fill(event);

    h_electron_before->fill(event);
#ifdef DEBUG
    cout << "Calling electron veto" << endl;
#endif
    if (!ele_veto->passes(event)) return false;
    h_ele_veto->fill(event);
    h_electron_after->fill(event);

    if (isMC) {
        jet_corrector->process(event);
        jet_EResSmearer->process(event);
    } else {
        if(event.run >= runnr_2018_Ab && event.run <= runnr_2018_Ae){
            jet_corrector_A->process(event);
        }
        else if(event.run >= runnr_2018_Bb && event.run <= runnr_2018_Be){
            jet_corrector_B->process(event);
        }
        else if(event.run >= runnr_2018_Cb && event.run <= runnr_2018_Ce){
            jet_corrector_C->process(event);
        }
        else if(event.run >= runnr_2018_Db && event.run <= runnr_2018_De){
            jet_corrector_D->process(event);
        }
    }
    sort_by_pt<TopJet>(*event.topjets);

    h_corrections->fill(event);

    topJetCleaner->process(event);
    sort_by_pt<TopJet>(*event.topjets);

    h_cleaner->fill(event);

    // 2. test selections and fill histograms
    if (!njet_sel->passes(event)) return false;
    h_njet->fill(event);

    if (!eta_sel->passes(event)) return false;
    h_eta->fill(event);

    if(!invmass_sel->passes(event)) return false;
    h_invmass->fill(event);

    // 3. decide whether or not to keep the current event in the output:
    return true;
}

// as we want to run the ExampleCycleNew directly with AnalysisModuleRunner,
// make sure the qstarModule is found by class name. This is ensured by this macro:
UHH2_REGISTER_ANALYSIS_MODULE(qstarModule)

}
