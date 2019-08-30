#!/bin/sh

for i in W{2,25,3,35,4,45,5,55,6,65,7,75}TeV; do root -l -b -q 'fit_macro.cc("deep_boosted/invMass", "'$i'", "2016", false /*signal*/, "MC.QCD_PS_2016v3" /*sel*/, false /*bg*/, "DB083")'; done
for i in W{2,25,3,35,4,45,5,55,6,65,7,75}TeV; do root -l -b -q 'fit_macro.cc("deep_boosted/invMass", "'$i'", "2016", false /*signal*/, "MC.QCD_PS_2016v3" /*sel*/, false /*bg*/, "LP")'; done
for i in W{2,25,3,35,4,45,5,55,6,65,7,75}TeV; do root -l -b -q 'fit_macro.cc("tau21/invMass", "'$i'", "2016", false /*signal*/, "MC.QCD_PS_2016v3" /*sel*/, false /*bg*/, "TAU035")'; done
for i in W{2,25,3,35,4,45,5,55,6,65,7,75}TeV; do root -l -b -q 'fit_macro.cc("tau21/invMass", "'$i'", "2016", false /*signal*/, "MC.QCD_PS_2016v3" /*sel*/, false /*bg*/, "TAU075")'; done

for i in W{2,25,3,35,4,45,5,55,6,65,7,75}TeV; do root -l -b -q 'fit_macro.cc("deep_boosted/invMass", "'$i'", "2017", false /*signal*/, "MC.QCD_PS_2017v2" /*sel*/, false /*bg*/, "DB083")'; done
for i in W{2,25,3,35,4,45,5,55,6,65,7,75}TeV; do root -l -b -q 'fit_macro.cc("deep_boosted/invMass", "'$i'", "2017", false /*signal*/, "MC.QCD_PS_2017v2" /*sel*/, false /*bg*/, "LP")'; done
for i in W{2,25,3,35,4,45,5,55,6,65,7,75}TeV; do root -l -b -q 'fit_macro.cc("tau21/invMass", "'$i'", "2017", false /*signal*/, "MC.QCD_PS_2017v2" /*sel*/, false /*bg*/, "TAU035")'; done
for i in W{2,25,3,35,4,45,5,55,6,65,7,75}TeV; do root -l -b -q 'fit_macro.cc("tau21/invMass", "'$i'", "2017", false /*signal*/, "MC.QCD_PS_2017v2" /*sel*/, false /*bg*/, "TAU075")'; done

for i in W{2,25,3,35,4,45,5,55,6,65,7,75}TeV; do root -l -b -q 'fit_macro.cc("deep_boosted/invMass", "'$i'", "2018", false /*signal*/, "MC.QCD_PS_2018" /*sel*/, false /*bg*/, "DB083")'; done
for i in W{2,25,3,35,4,45,5,55,6,65,7,75}TeV; do root -l -b -q 'fit_macro.cc("deep_boosted/invMass", "'$i'", "2018", false /*signal*/, "MC.QCD_PS_2018" /*sel*/, false /*bg*/, "LP")'; done
for i in W{2,25,3,35,4,45,5,55,6,65,7,75}TeV; do root -l -b -q 'fit_macro.cc("tau21/invMass", "'$i'", "2018", false /*signal*/, "MC.QCD_PS_2018" /*sel*/, false /*bg*/, "TAU035")'; done
for i in W{2,25,3,35,4,45,5,55,6,65,7,75}TeV; do root -l -b -q 'fit_macro.cc("tau21/invMass", "'$i'", "2018", false /*signal*/, "MC.QCD_PS_2018" /*sel*/, false /*bg*/, "TAU075")'; done

for i in W{2,25,3,35,4,45,5,55,6,65,7,75}TeV; do root -l -b -q 'fit_macro.cc("deep_boosted/invMass", "'$i'", "combined", false /*signal*/, "MC.QCD_PS_combined" /*sel*/, false /*bg*/, "DB083")'; done
for i in W{2,25,3,35,4,45,5,55,6,65,7,75}TeV; do root -l -b -q 'fit_macro.cc("deep_boosted/invMass", "'$i'", "combined", false /*signal*/, "MC.QCD_PS_combined" /*sel*/, false /*bg*/, "LP")'; done
for i in W{2,25,3,35,4,45,5,55,6,65,7,75}TeV; do root -l -b -q 'fit_macro.cc("tau21/invMass", "'$i'", "combined", false /*signal*/, "MC.QCD_PS_combined" /*sel*/, false /*bg*/, "TAU035")'; done
for i in W{2,25,3,35,4,45,5,55,6,65,7,75}TeV; do root -l -b -q 'fit_macro.cc("tau21/invMass", "'$i'", "combined", false /*signal*/, "MC.QCD_PS_combined" /*sel*/, false /*bg*/, "TAU075")'; done
