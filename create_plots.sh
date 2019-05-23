#!/bin/sh

root -q -l -b 'macro.cc("uhh2.AnalysisModuleRunner.MC.qstar2TeV_2018.root", "uhh2.AnalysisModuleRunner.MC.qstar5TeV_2018.root", "plots/W2vsW5");'
root -q -l -b 'macro.cc("uhh2.AnalysisModuleRunner.MC.qstar2TeV_2018.root", "uhh2.AnalysisModuleRunner.MC.qstar-Z-2TeV_2018.root", "plots/WvsZ2TeV");'
root -q -l -b 'macro.cc("uhh2.AnalysisModuleRunner.MC.qstar-Z-2TeV_2018.root", "uhh2.AnalysisModuleRunner.MC.qstar-Z-5TeV_2018.root", "plots/Z2vsZ5");'
root -q -l -b 'macro.cc("uhh2.AnalysisModuleRunner.MC.qstar5TeV_2018.root", "uhh2.AnalysisModuleRunner.MC.qstar-Z-5TeV_2018.root", "plots/WvsZ5TeV");'
