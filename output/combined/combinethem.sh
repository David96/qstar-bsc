#!/bin/sh
for i in {{DB,TAU}*,LP,LPtau}
do
	hadd -f $i/uhh2.AnalysisModuleRunner.MC.QCD_PS_combined.root \
		../2018/$i/uhh2.AnalysisModuleRunner.MC.QCD_PS_2018.root \
		../2017/$i/uhh2.AnalysisModuleRunner.MC.QCD_PS_2017v2.root \
		../2016/$i/uhh2.AnalysisModuleRunner.MC.QCD_PS_2016v3.root
done

for m in {2,25,3,35,4,45,5,55,6,65,7,75}
do
	for i in {{DB,TAU}*,LP,LPtau}
	do
		hadd -f $i/uhh2.AnalysisModuleRunner.MC.QstarToQW${m}TeV_PS_combined.root \
			../2016/$i/uhh2.AnalysisModuleRunner.MC.QstarToQW${m}TeV_PS_2016v3.root \
			../2017/$i/uhh2.AnalysisModuleRunner.MC.QstarToQW${m}TeV_PS_2017v2.root \
			../2018/$i/uhh2.AnalysisModuleRunner.MC.QstarToQW${m}TeV_PS_2018.root
	done
done
