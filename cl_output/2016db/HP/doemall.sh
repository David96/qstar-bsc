#!/bin/sh
combine -n qW -m 1600 --rMax 0.1 ../../../datacards/2016/deep_boosted/HP/w16tev_datacard.txt
combine -n qW -m 1800 ../../../datacards/2016/deep_boosted/HP/w18tev_datacard.txt
combine -n qW -m 2000 ../../../datacards/2016/deep_boosted/HP/w2tev_datacard.txt
combine -n qW -m 2500 ../../../datacards/2016/deep_boosted/HP/w25tev_datacard.txt
combine -n qW -m 3000 ../../../datacards/2016/deep_boosted/HP/w3tev_datacard.txt
combine -n qW -m 3500 ../../../datacards/2016/deep_boosted/HP/w35tev_datacard.txt
combine -n qW -m 4000 ../../../datacards/2016/deep_boosted/HP/w4tev_datacard.txt
combine -n qW -m 4500 --rMax 0.001 ../../../datacards/2016/deep_boosted/HP/w45tev_datacard.txt
combine -n qW -m 5000 --rMax 0.001 ../../../datacards/2016/deep_boosted/HP/w5tev_datacard.txt
combine -n qW -m 6000 --rMax 0.0001 ../../../datacards/2016/deep_boosted/HP/w6tev_datacard.txt
combine -n qW -m 7000 --rMax 0.0001 ../../../datacards/2016/deep_boosted/HP/w7tev_datacard.txt