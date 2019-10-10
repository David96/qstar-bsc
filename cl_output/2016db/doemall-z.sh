#!/bin/sh
combine -n qZ -m 1600 --rMax 10 ../../datacards/2016/deep_boosted/z16tev_datacard.txt
combine -n qZ -m 1800 ../../datacards/2016/deep_boosted/z18tev_datacard.txt
combine -n qZ -m 2000 ../../datacards/2016/deep_boosted/z2tev_datacard.txt
combine -n qZ -m 2500 ../../datacards/2016/deep_boosted/z25tev_datacard.txt
combine -n qZ -m 3000 ../../datacards/2016/deep_boosted/z3tev_datacard.txt
combine -n qZ -m 3500 ../../datacards/2016/deep_boosted/z35tev_datacard.txt
combine -n qZ -m 4000 ../../datacards/2016/deep_boosted/z4tev_datacard.txt
combine -n qZ -m 4500 --rMax 000.1 ../../datacards/2016/deep_boosted/z45tev_datacard.txt
combine -n qZ -m 5000 --rMax 000.1 ../../datacards/2016/deep_boosted/z5tev_datacard.txt
combine -n qZ -m 6000 --rMax 000.01 ../../datacards/2016/deep_boosted/z6tev_datacard.txt
combine -n qZ -m 7000 --rMax 000.01 ../../datacards/2016/deep_boosted/z7tev_datacard.txt
