#!/bin/sh

for m in {W,Z}
do
	echo Running for ${m}
	for i in ${m}{16,18,2,25,3,35,4,45,5,6,7}TeV; do root -l -b -q 'fit_macro.cc("deep_boosted/invMass_1GeV", "'$i'", "2016", false /*signal*/, "MC.QCD_PS_2016v3" /*sel*/, false /*bg*/, "DB083")'; done
	for i in ${m}{16,18,2,25,3,35,4,45,5,6,7}TeV; do root -l -b -q 'fit_macro.cc("deep_boosted/invMass_1GeV", "'$i'", "2016", false /*signal*/, "MC.QCD_PS_2016v3" /*sel*/, false /*bg*/, "LP")'; done
	for i in ${m}{16,18,2,25,3,35,4,45,5,6,7}TeV; do root -l -b -q 'fit_macro.cc("tau21/invMass_1GeV", "'$i'", "2016", false /*signal*/, "MC.QCD_PS_2016v3" /*sel*/, false /*bg*/, "TAU035")'; done
	for i in ${m}{16,18,2,25,3,35,4,45,5,6,7}TeV; do root -l -b -q 'fit_macro.cc("tau21/invMass_1GeV", "'$i'", "2016", false /*signal*/, "MC.QCD_PS_2016v3" /*sel*/, false /*bg*/, "LPtau")'; done

	#for i in ${m}{16,18,2,25,3,35,4,45,5,55,6,65,7,75}TeV; do root -l -b -q 'fit_macro.cc("deep_boosted/invMass_1GeV", "'$i'", "2017", false /*signal*/, "MC.QCD_PS_2017v2" /*sel*/, false /*bg*/, "DB083")'; done
	#for i in ${m}{16,18,2,25,3,35,4,45,5,55,6,65,7,75}TeV; do root -l -b -q 'fit_macro.cc("deep_boosted/invMass_1GeV", "'$i'", "2017", false /*signal*/, "MC.QCD_PS_2017v2" /*sel*/, false /*bg*/, "LP")'; done
	#for i in ${m}{16,18,2,25,3,35,4,45,5,55,6,65,7,75}TeV; do root -l -b -q 'fit_macro.cc("tau21/invMass_1GeV", "'$i'", "2017", false /*signal*/, "MC.QCD_PS_2017v2" /*sel*/, false /*bg*/, "TAU035")'; done
	#for i in ${m}{16,18,2,25,3,35,4,45,5,55,6,65,7,75}TeV; do root -l -b -q 'fit_macro.cc("tau21/invMass_1GeV", "'$i'", "2017", false /*signal*/, "MC.QCD_PS_2017v2" /*sel*/, false /*bg*/, "LPtau")'; done

	#for i in ${m}{16,18,2,25,3,35,4,45,5,55,6,65,7,75}TeV; do root -l -b -q 'fit_macro.cc("deep_boosted/invMass_1GeV", "'$i'", "2018", false /*signal*/, "MC.QCD_PS_2018" /*sel*/, false /*bg*/, "DB083")'; done
	#for i in ${m}{16,18,2,25,3,35,4,45,5,55,6,65,7,75}TeV; do root -l -b -q 'fit_macro.cc("deep_boosted/invMass_1GeV", "'$i'", "2018", false /*signal*/, "MC.QCD_PS_2018" /*sel*/, false /*bg*/, "LP")'; done
	#for i in ${m}{16,18,2,25,3,35,4,45,5,55,6,65,7,75}TeV; do root -l -b -q 'fit_macro.cc("tau21/invMass_1GeV", "'$i'", "2018", false /*signal*/, "MC.QCD_PS_2018" /*sel*/, false /*bg*/, "TAU035")'; done
	#for i in ${m}{16,18,2,25,3,35,4,45,5,55,6,65,7,75}TeV; do root -l -b -q 'fit_macro.cc("tau21/invMass_1GeV", "'$i'", "2018", false /*signal*/, "MC.QCD_PS_2018" /*sel*/, false /*bg*/, "LPtau")'; done

	for i in ${m}{16,18,2,25,3,35,4,45,5,6,7}TeV; do root -l -b -q 'fit_macro.cc("deep_boosted/invMass_1GeV", "'$i'", "combined", false /*signal*/, "MC.QCD_PS_combined" /*sel*/, false /*bg*/, "DB083")'; done
	for i in ${m}{16,18,2,25,3,35,4,45,5,6,7}TeV; do root -l -b -q 'fit_macro.cc("deep_boosted/invMass_1GeV", "'$i'", "combined", false /*signal*/, "MC.QCD_PS_combined" /*sel*/, false /*bg*/, "LP")'; done
	for i in ${m}{16,18,2,25,3,35,4,45,5,6,7}TeV; do root -l -b -q 'fit_macro.cc("tau21/invMass_1GeV", "'$i'", "combined", false /*signal*/, "MC.QCD_PS_combined" /*sel*/, false /*bg*/, "TAU035")'; done
	for i in ${m}{16,18,2,25,3,35,4,45,5,6,7}TeV; do root -l -b -q 'fit_macro.cc("tau21/invMass_1GeV", "'$i'", "combined", false /*signal*/, "MC.QCD_PS_combined" /*sel*/, false /*bg*/, "LPtau")'; done
done
