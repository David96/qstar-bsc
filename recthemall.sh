#!/bin/sh

for y in 20{16,17,18}
do
	sframe_batch.py -f config/${y}/qcd-post.xml
	sframe_batch.py -f config/${y}/qcd-lp.xml
	sframe_batch.py -f config/${y}/data-post.xml
	sframe_batch.py -f config/${y}/data-lp.xml
done

sleep 60

cd output/2016
hadd -f DB095/uhh2.AnalysisModuleRunner.MC.QCD_PS_2016v3.root DB095/*PS_HT*.root
hadd -f DB095/uhh2.AnalysisModuleRunner.data.DATA_PS_2016v3.root DB095/*PS_JetHT*.root
hadd -f LP/uhh2.AnalysisModuleRunner.MC.QCD_PS_2016v3.root LP/*PS_HT*.root
hadd -f LP/uhh2.AnalysisModuleRunner.data.DATA_PS_2016v3.root LP/*PS_JetHT*.root

cd ../2017
hadd -f DB095/uhh2.AnalysisModuleRunner.MC.QCD_PS_2017v2.root DB095/*PS_HT*.root
hadd -f DB095/uhh2.AnalysisModuleRunner.data.DATA_PS_2017v2.root DB095/*PS_JetHT*.root
hadd -f LP/uhh2.AnalysisModuleRunner.MC.QCD_PS_2017v2.root LP/*PS_HT*.root
hadd -f LP/uhh2.AnalysisModuleRunner.data.DATA_PS_2017v2.root LP/*PS_JetHT*.root

cd ../2018
hadd -f DB095/uhh2.AnalysisModuleRunner.MC.QCD_PS_2018.root DB095/*PS_HT*.root
hadd -f DB095/uhh2.AnalysisModuleRunner.data.DATA_PS_2018.root DB095/*PS_JetHT*.root
hadd -f LP/uhh2.AnalysisModuleRunner.MC.QCD_PS_2018.root LP/*PS_HT*.root
hadd -f LP/uhh2.AnalysisModuleRunner.data.DATA_PS_2018.root LP/*PS_JetHT*.root
