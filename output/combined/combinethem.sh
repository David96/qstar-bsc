#!/bin/sh
hadd -f -T uhh2.AnalysisModuleRunner.MC.QCD.root \
	../2018/uhh2.AnalysisModuleRunner.MC.QCD.root \
	../2017/uhh2.AnalysisModuleRunner.MC.QCD.root \
	../2016/uhh2.AnalysisModuleRunner.MC.QCD.root

#for i in {DB083,TAU035,LP,LPtau}
#do
#	hadd -f $i/uhh2.AnalysisModuleRunner.MC.QCD_PS_combined.root \
#		../2018/$i/uhh2.AnalysisModuleRunner.MC.QCD_PS_2018.root \
#		../2017/$i/uhh2.AnalysisModuleRunner.MC.QCD_PS_2017v2.root \
#		../2016/$i/uhh2.AnalysisModuleRunner.MC.QCD_PS_2016v3.root
#	hadd -f $i/uhh2.AnalysisModuleRunner.data.DATA_PS_combined.root \
#		../2018/$i/uhh2.AnalysisModuleRunner.data.DATA_PS_2018.root \
#		../2017/$i/uhh2.AnalysisModuleRunner.data.DATA_PS_2017v2.root \
#		../2016/$i/uhh2.AnalysisModuleRunner.data.DATA_PS_2016v3.root
#done

for m in {12,14,16,18,2,25,3,35,4,45,5,6,7}
do
	hadd -f -T uhh2.AnalysisModuleRunner.MC.qstar${m}TeV_combined.root \
		../2018/uhh2.AnalysisModuleRunner.MC.qstar${m}TeV_2018.root \
		../2017/uhh2.AnalysisModuleRunner.MC.qstar${m}TeV_2017v2.root \
		../2016/uhh2.AnalysisModuleRunner.MC.qstar${m}TeV_2016v2.root
	hadd -f -T uhh2.AnalysisModuleRunner.MC.qstar-Z-${m}TeV_combined.root \
		../2018/uhh2.AnalysisModuleRunner.MC.qstar-Z-${m}TeV_2018.root \
		../2017/uhh2.AnalysisModuleRunner.MC.qstar-Z-${m}TeV_2017v2.root \
		../2016/uhh2.AnalysisModuleRunner.MC.qstar-Z-${m}TeV_2016v2.root

	#for i in {DB083,TAU035,LP,LPtau}
	#do
	#	hadd -f $i/uhh2.AnalysisModuleRunner.MC.QstarToQW${m}TeV_PS_combined.root \
	#		../2016/$i/uhh2.AnalysisModuleRunner.MC.QstarToQW${m}TeV_PS_2016v2.root \
	#		../2017/$i/uhh2.AnalysisModuleRunner.MC.QstarToQW${m}TeV_PS_2017v2.root \
	#		../2018/$i/uhh2.AnalysisModuleRunner.MC.QstarToQW${m}TeV_PS_2018.root
	#	hadd -f $i/uhh2.AnalysisModuleRunner.MC.QstarToQZ${m}TeV_PS_combined.root \
	#		../2016/$i/uhh2.AnalysisModuleRunner.MC.QstarToQZ${m}TeV_PS_2016v2.root \
	#		../2017/$i/uhh2.AnalysisModuleRunner.MC.QstarToQZ${m}TeV_PS_2017v2.root \
	#		../2018/$i/uhh2.AnalysisModuleRunner.MC.QstarToQZ${m}TeV_PS_2018.root
	#done
done
