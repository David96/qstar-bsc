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
        "uhh2.AnalysisModuleRunner.MC.qstar12TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW12TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_12TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar12TeV_", // original
        1000, 3500, // sig min/max
        1000, 5800, // model min/max
        1200, 1100, 1400 // mean, mean min/max
    };
    masspoints["W14TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar14TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW14TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_14TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar14TeV_", // original
        1000, 2000, // sig min/max
        1300, 6200, // model min/max
        1400, 1300, 1600 // mean, mean min/max
    };
    masspoints["W16TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar16TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW16TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_16TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar16TeV_", // original
        1000, 5000, // sig min/max
        1200, 6200, // model min/max
        1600, 1500, 1700 // mean, mean min/max
    };
    masspoints["W18TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar18TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW18TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_18TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar18TeV_", // original
        1000, 4000, // sig min/max
        1400, 6200, // model min/max
        1800, 1700, 2000 // mean, mean min/max
    };
    masspoints["W2TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar2TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW2TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_2TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar2TeV_", // original
        1000, 5800, // sig min/max
        1400, 5000, // model min/max
        2000, 1950, 2200 // mean, mean min/max
    };
    masspoints["W25TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar25TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW25TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_25TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar25TeV_", // original
        1200, 5000, // sig min/max
        1400, 6200, // model min/max
        2500, 2400, 2700 // mean, mean min/max
    };
    masspoints["W3TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar3TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW3TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_3TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar3TeV_", // original
        1800, 5000, // sig min/max
        1400, 6200, // model min/max
        3000, 2900, 3200 // mean, mean min/max
    };
    masspoints["W35TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar35TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW35TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_35TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar35TeV_", // original
        1800, 5000, // sig min/max
        1400, 6200, // model min/max
        3500, 3400, 3700 // mean, mean min/max
    };
    masspoints["W4TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar4TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW4TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_4TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar4TeV_", // original
        2000, 5500, // sig min/max
        1400, 6500, // model min/max
        4000, 3000, 5000 // mean, mean min/max
    };
    masspoints["W45TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar45TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW45TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_45TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar45TeV_", // original
        2000, 6200, // sig min/max
        1400, 6500, // model min/max
        4500, 3500, 5500 // mean, mean min/max
    };
    masspoints["W5TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar5TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW5TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_5TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar5TeV_", // original
        2000, 7000, // sig min/max
        1400, 6500, // model min/max
        5000, 4800, 5200 // mean, mean min/max
    };
    masspoints["W55TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar55TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW55TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_55TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar55TeV_", // original
        3000, 7000, // sig min/max
        1400, 7000, // model min/max
        5500, 5300, 5700 // mean, mean min/max
    };
    masspoints["W6TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar6TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW6TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_6TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar6TeV_", // original
        2000, 7000, // sig min/max
        1400, 7000, // model min/max
        6000, 5800, 6200 // mean, mean min/max
    };
    masspoints["W65TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar65TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW65TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_65TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar65TeV_", // original
        2000, 7000, // sig min/max
        1400, 8000, // model min/max
        6500, 6300, 6800 // mean, mean min/max
    };
    masspoints["W7TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar7TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW7TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_7TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar7TeV_", // original
        4500, 8000, // sig min/max
        1400, 8000, // model min/max
        7000, 6800, 7200 // mean, mean min/max
    };
    masspoints["W75TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar75TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQW75TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQW_OLD_TAGGER_75TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar75TeV_", // original
        5000, 8500, // sig min/max
        1400, 8000, // model min/max
        7500, 7200, 7800 // mean, mean min/max
    };
    /*masspoints["Z2TeV"] = {
        "output/uhh2.AnalysisModuleRunner.MC.qstar-Z-2TeV_",
        "output/uhh2.AnalysisModuleRunner.MC.QstarToQZ2TeV_PS_",
        "output/uhh2.AnalysisModuleRunner.MC.QstarToQZ_OLD_TAGGER_2TeV_PS_",
        "output/uhh2.AnalysisModuleRunner.MC.qstar-Z-2TeV_",
        1000, 2900, // sig min/max
        1400, 4500, // model min/max
        2000, 1000, 3000 // mean, mean min/max
    };
    masspoints["Z5TeV"] = {
        "output/uhh2.AnalysisModuleRunner.MC.qstar-Z-5TeV_",
        "output/uhh2.AnalysisModuleRunner.MC.QstarToQZ5TeV_PS_",
        "output/uhh2.AnalysisModuleRunner.MC.QstarToQZ_OLD_TAGGER_5TeV_PS_",
        "output/uhh2.AnalysisModuleRunner.MC.qstar-Z-5TeV_",
        4000, 6000, // sig min/max
        1400, 6000, // model min/max
        5000, 4000, 6000 // mean, mean min/max
    };*/
    masspoints["Z12TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-12TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ12TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ_OLD_TAGGER_12TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-12TeV_", // original
        1000, 3500, // sig min/max
        1000, 5800, // model min/max
        1200, 1100, 1400 // mean, mean min/max
    };
    masspoints["Z14TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-14TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ14TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ_OLD_TAGGER_14TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-14TeV_", // original
        1000, 2000, // sig min/max
        1300, 6200, // model min/max
        1400, 1300, 1600 // mean, mean min/max
    };
    masspoints["Z16TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-16TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ16TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ_OLD_TAGGER_16TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-16TeV_", // original
        1000, 5000, // sig min/max
        1200, 6200, // model min/max
        1600, 1500, 1700 // mean, mean min/max
    };
    masspoints["Z18TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-18TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ18TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ_OLD_TAGGER_18TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-18TeV_", // original
        1000, 4000, // sig min/max
        1400, 6200, // model min/max
        1800, 1700, 2000 // mean, mean min/max
    };
    masspoints["Z2TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-2TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ2TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ_OLD_TAGGER_2TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-2TeV_", // original
        1000, 5800, // sig min/max
        1300, 5000, // model min/max
        2000, 1950, 2200 // mean, mean min/max
    };
    masspoints["Z25TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-25TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ25TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ_OLD_TAGGER_25TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-25TeV_", // original
        1000, 5000, // sig min/max
        1400, 6200, // model min/max
        2500, 2400, 2700 // mean, mean min/max
    };
    masspoints["Z3TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-3TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ3TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ_OLD_TAGGER_3TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-3TeV_", // original
        1400, 5000, // sig min/max
        1400, 6200, // model min/max
        3000, 2900, 3200 // mean, mean min/max
    };
    masspoints["Z35TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-35TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ35TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ_OLD_TAGGER_35TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-35TeV_", // original
        1400, 5000, // sig min/max
        1400, 6200, // model min/max
        3500, 3400, 3700 // mean, mean min/max
    };
    masspoints["Z4TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-4TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ4TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ_OLD_TAGGER_4TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-4TeV_", // original
        1600, 5500, // sig min/max
        1400, 6500, // model min/max
        4000, 3000, 5000 // mean, mean min/max
    };
    masspoints["Z45TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-45TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ45TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ_OLD_TAGGER_45TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-45TeV_", // original
        1600, 6200, // sig min/max
        1400, 6500, // model min/max
        4500, 3500, 5500 // mean, mean min/max
    };
    masspoints["Z5TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-5TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ5TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ_OLD_TAGGER_5TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-5TeV_", // original
        1600, 7000, // sig min/max
        1400, 6500, // model min/max
        5000, 4800, 5200 // mean, mean min/max
    };
    masspoints["Z55TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-55TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ55TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ_OLD_TAGGER_55TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-55TeV_", // original
        2600, 7000, // sig min/max
        1400, 7000, // model min/max
        5500, 5300, 5700 // mean, mean min/max
    };
    masspoints["Z6TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-6TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ6TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ_OLD_TAGGER_6TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-6TeV_", // original
        1600, 7000, // sig min/max
        1400, 7000, // model min/max
        6000, 5800, 6200 // mean, mean min/max
    };
    masspoints["Z65TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-65TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ65TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ_OLD_TAGGER_65TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-65TeV_", // original
        2000, 8000, // sig min/max
        1400, 8000, // model min/max
        6500, 6300, 6800 // mean, mean min/max
    };
    masspoints["Z7TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-7TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ7TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ_OLD_TAGGER_7TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-7TeV_", // original
        5600, 8000, // sig min/max
        1400, 8000, // model min/max
        7000, 6800, 7200 // mean, mean min/max
    };
    masspoints["Z75TeV"] = {
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-75TeV_", // pre
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ75TeV_PS_", // post
        "uhh2.AnalysisModuleRunner.MC.QstarToQZ_OLD_TAGGER_75TeV_PS_", // old tagger
        "uhh2.AnalysisModuleRunner.MC.qstar-Z-75TeV_", // original
        5600, 8500, // sig min/max
        1400, 8000, // model min/max
        7500, 7200, 7800 // mean, mean min/max
    };
}
#endif
