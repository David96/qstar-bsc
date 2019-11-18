#include <iostream>
#include <memory>

#include "UHH2/common/include/CleaningModules.h"
#include "UHH2/common/include/CommonModules.h"
#include "UHH2/common/include/ElectronHists.h"
#include "UHH2/common/include/ElectronIds.h"
#include "UHH2/common/include/JetCorrections.h"
#include "UHH2/common/include/JetHists.h"
#include "UHH2/common/include/MCLargeWeightKiller.h"
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

    unique_ptr<MCLargeWeightKiller> weightKiller;

    unique_ptr<CommonModules> common;

    unique_ptr<TopJetCleaner> topJetCleaner;

    unique_ptr<TopJetCorrector> jet_corrector;

    unique_ptr<TopJetCorrector> jet_corrector_2016_B;
    unique_ptr<TopJetCorrector> jet_corrector_2016_C;
    unique_ptr<TopJetCorrector> jet_corrector_2016_D;
    unique_ptr<TopJetCorrector> jet_corrector_2016_E;
    unique_ptr<TopJetCorrector> jet_corrector_2016_F;
    unique_ptr<TopJetCorrector> jet_corrector_2016_G;
    unique_ptr<TopJetCorrector> jet_corrector_2016_H;

    unique_ptr<TopJetCorrector> jet_corrector_2017_B;
    unique_ptr<TopJetCorrector> jet_corrector_2017_C;
    unique_ptr<TopJetCorrector> jet_corrector_2017_D;
    unique_ptr<TopJetCorrector> jet_corrector_2017_E;
    unique_ptr<TopJetCorrector> jet_corrector_2017_F;

    unique_ptr<TopJetCorrector> jet_corrector_2018_A;
    unique_ptr<TopJetCorrector> jet_corrector_2018_B;
    unique_ptr<TopJetCorrector> jet_corrector_2018_C;
    unique_ptr<TopJetCorrector> jet_corrector_2018_D;

    unique_ptr<GenericJetResolutionSmearer> jet_EResSmearer;

    unique_ptr<SoftDropMassCalculator> sdmCalc;

    // declare the Selections to use. Use unique_ptr to ensure automatic call of delete in the destructor,
    // to avoid memory leaks.
    unique_ptr<Selection> njet_sel, eta_sel, invmass_sel, muon_veto, ele_veto;

    // store the Hists collection as member variables. Again, use unique_ptr to avoid memory leaks.
    unique_ptr<Hists> h_nocuts, h_common, h_cleaner, h_corrections, h_njet,
        h_eta, h_muon_veto, h_ele_veto, h_invmass;

    unique_ptr<Hists> h_muon_before, h_muon_after, h_electron_before, h_electron_after;

    unique_ptr<AnalysisModule> MCWeightModule;
    unique_ptr<MCPileupReweight> MCPileupReweightModule;

    unique_ptr<GenParticlesPrinter> printer;

    Year year;

    const int runnr_2016_Ab = 271036;
    const int runnr_2016_Ae = 271658;
    const int runnr_2016_Bb = 272007;
    const int runnr_2016_Be = 275376;
    const int runnr_2016_Cb = 275657;
    const int runnr_2016_Ce = 276283;
    const int runnr_2016_Db = 276315;
    const int runnr_2016_De = 276811;
    const int runnr_2016_Eb = 276831;
    const int runnr_2016_Ee = 277420;
    const int runnr_2016_Fb = 277772;
    const int runnr_2016_Fe = 278808;
    const int runnr_2016_Gb = 278820;
    const int runnr_2016_Ge = 280385;
    const int runnr_2016_Hb = 280919;
    const int runnr_2016_He = 284044;

    const int runnr_2017_Ab = 294927;
    const int runnr_2017_Ae = 297019;
    const int runnr_2017_Bb = 297046;
    const int runnr_2017_Be = 299329;
    const int runnr_2017_Cb = 299368;
    const int runnr_2017_Ce = 302029;
    const int runnr_2017_Db = 302030;
    const int runnr_2017_De = 303434;
    const int runnr_2017_Eb = 303824;
    const int runnr_2017_Ee = 304797;
    const int runnr_2017_Fb = 305040;
    const int runnr_2017_Fe = 306462;

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

    string ResolutionFileName;
    isMC = ctx.get("dataset_type") == "MC";
    year = extract_year(ctx);

    JERSmearing::SFtype1 smearing;
    switch (year) {
        case Year::is2016v3:
        case Year::is2016v2:
            smearing = JERSmearing::SF_13TeV_Summer16_25nsV1;
            ResolutionFileName = "2016/Summer16_25nsV1_MC_PtResolution_AK8PFPuppi.txt";
            cout << "Year 2016" << endl;
            break;
        case Year::is2017v2:
            smearing = JERSmearing::SF_13TeV_Fall17_V3;
            ResolutionFileName = "2017/Fall17_V3_MC_PtResolution_AK8PFPuppi.txt";
            cout << "Year 2017" << endl;
            break;
        case Year::is2018:
            smearing = JERSmearing::SF_13TeV_Autumn18_RunABCD_V4;
            ResolutionFileName = "2018/Autumn18_V4_MC_PtResolution_AK8PFPuppi.txt";
            cout << "Year 2018" << endl;
            break;
        default:
            cerr << "No year detected!!!" << endl;
    }

    if (isMC) {
        jet_corrector.reset(new TopJetCorrector(ctx, JERFiles::Autumn18_V8_L123_AK8PFPuppi_MC));
        jet_EResSmearer.reset(new GenericJetResolutionSmearer(ctx,"topjets","gentopjets", smearing, ResolutionFileName));


        weightKiller.reset(new MCLargeWeightKiller(ctx,
                                     2,  // maximum allowed ratio of leading reco jet pT / generator HT
                                     2,  // maximum allowed ratio of leading gen jet pT / generator HT
                                     2,  // maximum allowed ratio of leading reco jet pT / Q scale
                                     2,  // maximum allowed ratio of PU maximum pTHat / gen HT
                                         // (ensures scale of PU < scale of hard interaction)
                                     2,  // maximum allowed ratio of leading reco jet pT / pTHat
                                     2,  // maximum allowed ratio of leading gen jet pT / pTHat
                                     "topjets", // name of jet collection to be used
                                     "gentopjets" // name of genjet collection to be used
                    ));
        // Needed to save weight_pu branch in root file
        MCWeightModule.reset(new MCLumiWeight(ctx));
        MCPileupReweightModule.reset(new MCPileupReweight(ctx));
    } else {
        if (year == Year::is2016v3) {
            jet_corrector_2016_B.reset(new TopJetCorrector(ctx, JERFiles::Summer16_07Aug2017_V11_B_L123_AK8PFPuppi_DATA));
            jet_corrector_2016_C.reset(new TopJetCorrector(ctx, JERFiles::Summer16_07Aug2017_V11_B_L123_AK8PFPuppi_DATA));
            jet_corrector_2016_D.reset(new TopJetCorrector(ctx, JERFiles::Summer16_07Aug2017_V11_B_L123_AK8PFPuppi_DATA));
            jet_corrector_2016_E.reset(new TopJetCorrector(ctx, JERFiles::Summer16_07Aug2017_V11_B_L123_AK8PFPuppi_DATA));
            jet_corrector_2016_F.reset(new TopJetCorrector(ctx, JERFiles::Summer16_07Aug2017_V11_B_L123_AK8PFPuppi_DATA));
            jet_corrector_2016_G.reset(new TopJetCorrector(ctx, JERFiles::Summer16_07Aug2017_V11_B_L123_AK8PFPuppi_DATA));
            jet_corrector_2016_H.reset(new TopJetCorrector(ctx, JERFiles::Summer16_07Aug2017_V11_B_L123_AK8PFPuppi_DATA));
        } else if (year == Year::is2017v2) {
            jet_corrector_2017_B.reset(new TopJetCorrector(ctx, JERFiles::Fall17_17Nov2017_V32_B_L123_AK8PFPuppi_DATA));
            jet_corrector_2017_C.reset(new TopJetCorrector(ctx, JERFiles::Fall17_17Nov2017_V32_C_L123_AK8PFPuppi_DATA));
            jet_corrector_2017_D.reset(new TopJetCorrector(ctx, JERFiles::Fall17_17Nov2017_V32_D_L123_AK8PFPuppi_DATA));
            jet_corrector_2017_E.reset(new TopJetCorrector(ctx, JERFiles::Fall17_17Nov2017_V32_E_L123_AK8PFPuppi_DATA));
            jet_corrector_2017_F.reset(new TopJetCorrector(ctx, JERFiles::Fall17_17Nov2017_V32_F_L123_AK8PFPuppi_DATA));
        } else if (year == Year::is2018) {
            jet_corrector_2018_A.reset(new TopJetCorrector(ctx, JERFiles::Autumn18_V8_A_L123_noRes_AK8PFPuppi_DATA));
            jet_corrector_2018_B.reset(new TopJetCorrector(ctx, JERFiles::Autumn18_V8_B_L123_noRes_AK8PFPuppi_DATA));
            jet_corrector_2018_C.reset(new TopJetCorrector(ctx, JERFiles::Autumn18_V8_C_L123_noRes_AK8PFPuppi_DATA));
            jet_corrector_2018_D.reset(new TopJetCorrector(ctx, JERFiles::Autumn18_V8_D_L123_noRes_AK8PFPuppi_DATA));
        }
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
    if (isMC && !weightKiller->passes(event))
        return false;

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
        if (event.run >= runnr_2016_Bb && event.run <= runnr_2016_Be) {
            jet_corrector_2016_B->process(event);
        }
        else if(event.run >= runnr_2016_Cb && event.run <= runnr_2016_Ce){
            jet_corrector_2016_C->process(event);
        }
        else if(event.run >= runnr_2016_Db && event.run <= runnr_2016_De){
            jet_corrector_2016_D->process(event);
        }
        else if(event.run >= runnr_2016_Eb && event.run <= runnr_2016_Ee){
            jet_corrector_2016_E->process(event);
        }
        else if(event.run >= runnr_2016_Fb && event.run <= runnr_2016_Fe){
            jet_corrector_2016_F->process(event);
        }
        else if(event.run >= runnr_2016_Gb && event.run <= runnr_2016_Ge){
            jet_corrector_2016_G->process(event);
        }
        else if(event.run >= runnr_2016_Hb && event.run <= runnr_2016_He){
            jet_corrector_2016_H->process(event);
        }
        else if(event.run >= runnr_2017_Bb && event.run <= runnr_2017_Be){
            jet_corrector_2017_B->process(event);
        }
        else if(event.run >= runnr_2017_Cb && event.run <= runnr_2017_Ce){
            jet_corrector_2017_C->process(event);
        }
        else if(event.run >= runnr_2017_Db && event.run <= runnr_2017_De){
            jet_corrector_2017_D->process(event);
        }
        else if(event.run >= runnr_2017_Eb && event.run <= runnr_2017_Ee){
            jet_corrector_2017_E->process(event);
        }
        else if(event.run >= runnr_2017_Fb && event.run <= runnr_2017_Fe){
            jet_corrector_2017_F->process(event);
        }
        else if(event.run >= runnr_2018_Ab && event.run <= runnr_2018_Ae){
            jet_corrector_2018_A->process(event);
        }
        else if(event.run >= runnr_2018_Bb && event.run <= runnr_2018_Be){
            jet_corrector_2018_B->process(event);
        }
        else if(event.run >= runnr_2018_Cb && event.run <= runnr_2018_Ce){
            jet_corrector_2018_C->process(event);
        }
        else if(event.run >= runnr_2018_Db && event.run <= runnr_2018_De){
            jet_corrector_2018_D->process(event);
        } else {
            cerr << "No correct JEC Corrector found!" << endl;
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
