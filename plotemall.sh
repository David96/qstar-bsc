#!/bin/sh

for y in {2016,combined}
do
	Plots -f steers/${y}/data-bg.steer
	Plots -f steers/${y}/data-bg-log.steer
	Plots -f steers/${y}/data-bg-sideband.steer
	Plots -f steers/${y}/data-bg-sideband-log.steer
	Plots -f steers/${y}/w2w5-pre.steer
	Plots -f steers/${y}/w2w5-pre-log.steer
done
