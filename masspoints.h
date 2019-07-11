#ifndef MASSPOINTS_H
#define MASSPOINTS_H
#include <iostream>
#include <string>
#include <map>

using namespace std;

struct masspoint_data {
    const char* preselection;
    const char* filename;
    const char* old_tagger;
    const char* orig;
    int sig_min, sig_max, model_min, model_max;
    int mean, mean_min, mean_max;
};

void init_masspoints(map<string, masspoint_data> &masspoints) {
    masspoints["W12TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar12TeV_2018.root", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW12TeV_PS_2018.root", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_12TeV_PS_2018.root", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar12TeV_2018.root", // original
        1000, 3500, // sig min/max
        1000, 5800, // model min/max
        1200, 1100, 1400 // mean, mean min/max
    };
    masspoints["W14TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar14TeV_2018.root", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW14TeV_PS_2018.root", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_14TeV_PS_2018.root", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar14TeV_2018.root", // original
        1000, 2000, // sig min/max
        1300, 6200, // model min/max
        1400, 1300, 1600 // mean, mean min/max
    };
    masspoints["W16TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar16TeV_2018.root", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW16TeV_PS_2018.root", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_16TeV_PS_2018.root", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar16TeV_2018.root", // original
        1000, 5000, // sig min/max
        1200, 6200, // model min/max
        1600, 1500, 1700 // mean, mean min/max
    };
    masspoints["W18TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar18TeV_2018.root", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW18TeV_PS_2018.root", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_18TeV_PS_2018.root", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar18TeV_2018.root", // original
        1000, 4000, // sig min/max
        1400, 6200, // model min/max
        1800, 1700, 2000 // mean, mean min/max
    };
    masspoints["W2TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar2TeV_2018.root", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW2TeV_PS_2018.root", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_2TeV_PS_2018.root", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar2TeV_2018.root", // original
        1000, 5800, // sig min/max
        1400, 5000, // model min/max
        2000, 1950, 2200 // mean, mean min/max
    };
    masspoints["W25TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar25TeV_2018.root", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW25TeV_PS_2018.root", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_25TeV_PS_2018.root", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar25TeV_2018.root", // original
        1200, 5000, // sig min/max
        1400, 6200, // model min/max
        2500, 2400, 2700 // mean, mean min/max
    };
    masspoints["W3TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar3TeV_2018.root", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW3TeV_PS_2018.root", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_3TeV_PS_2018.root", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar3TeV_2018.root", // original
        1800, 5000, // sig min/max
        1400, 6200, // model min/max
        3000, 2900, 3200 // mean, mean min/max
    };
    masspoints["W35TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar35TeV_2018.root", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW35TeV_PS_2018.root", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_35TeV_PS_2018.root", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar35TeV_2018.root", // original
        1800, 5000, // sig min/max
        1400, 6200, // model min/max
        3500, 3400, 3700 // mean, mean min/max
    };
    masspoints["W4TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar4TeV_2018.root", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW4TeV_PS_2018.root", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_4TeV_PS_2018.root", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar4TeV_2018.root", // original
        2000, 5500, // sig min/max
        1400, 5800, // model min/max
        4000, 3000, 5000 // mean, mean min/max
    };
    masspoints["W45TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar45TeV_2018.root", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW45TeV_PS_2018.root", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_45TeV_PS_2018.root", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar45TeV_2018.root", // original
        2000, 6200, // sig min/max
        1400, 6000, // model min/max
        4500, 3500, 5500 // mean, mean min/max
    };
    masspoints["W5TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar5TeV_2018.root", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW5TeV_PS_2018.root", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_5TeV_PS_2018.root", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar5TeV_2018.root", // original
        2000, 7000, // sig min/max
        1400, 6000, // model min/max
        5000, 4800, 5200 // mean, mean min/max
    };
    masspoints["W55TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar55TeV_2018.root", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW55TeV_PS_2018.root", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_55TeV_PS_2018.root", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar55TeV_2018.root", // original
        2000, 7000, // sig min/max
        1400, 6000, // model min/max
        5000, 4800, 5200 // mean, mean min/max
    };
    masspoints["W6TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar6TeV_2018.root", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW6TeV_PS_2018.root", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_6TeV_PS_2018.root", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar6TeV_2018.root", // original
        2000, 7000, // sig min/max
        1400, 7000, // model min/max
        6000, 5800, 6200 // mean, mean min/max
    };
    /*masspoints["Z2TeV"] = {
        "output/uhh2.AnalysisModuleRunner.MC.qstar-Z-2TeV_2018.root",
        "output/uhh2.AnalysisModuleRunner.MC.QstarToQZ2TeV_PS_2018.root",
        "output/uhh2.AnalysisModuleRunner.MC.QstarToQZ_OLD_TAGGER_2TeV_PS_2018.root",
        "output/uhh2.AnalysisModuleRunner.MC.qstar-Z-2TeV_2018.root",
        1000, 2900, // sig min/max
        1400, 4500, // model min/max
        2000, 1000, 3000 // mean, mean min/max
    };
    masspoints["Z5TeV"] = {
        "output/uhh2.AnalysisModuleRunner.MC.qstar-Z-5TeV_2018.root",
        "output/uhh2.AnalysisModuleRunner.MC.QstarToQZ5TeV_PS_2018.root",
        "output/uhh2.AnalysisModuleRunner.MC.QstarToQZ_OLD_TAGGER_5TeV_PS_2018.root",
        "output/uhh2.AnalysisModuleRunner.MC.qstar-Z-5TeV_2018.root",
        4000, 6000, // sig min/max
        1400, 6000, // model min/max
        5000, 4000, 6000 // mean, mean min/max
    };*/
}
#endif
