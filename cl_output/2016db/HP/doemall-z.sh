#!/bin/sh
combine -n qZ -m 1600 --rMax 0.1 ../../../datacards/2016/deep_boosted/HP/z16tev_datacard.txt
combine -n qZ -m 1800 ../../../datacards/2016/deep_boosted/HP/z18tev_datacard.txt
combine -n qZ -m 2000 ../../../datacards/2016/deep_boosted/HP/z2tev_datacard.txt
combine -n qZ -m 2500 ../../../datacards/2016/deep_boosted/HP/z25tev_datacard.txt
combine -n qZ -m 3000 ../../../datacards/2016/deep_boosted/HP/z3tev_datacard.txt
combine -n qZ -m 3500 ../../../datacards/2016/deep_boosted/HP/z35tev_datacard.txt
combine -n qZ -m 4000 ../../../datacards/2016/deep_boosted/HP/z4tev_datacard.txt
combine -n qZ -m 4500 --rMax 0.001 ../../../datacards/2016/deep_boosted/HP/z45tev_datacard.txt
combine -n qZ -m 5000 --rMax 0.001 ../../../datacards/2016/deep_boosted/HP/z5tev_datacard.txt
combine -n qZ -m 6000 --rMax 0.0001 ../../../datacards/2016/deep_boosted/HP/z6tev_datacard.txt
combine -n qZ -m 7000 --rMax 0.0001 ../../../datacards/2016/deep_boosted/HP/z7tev_datacard.txt
