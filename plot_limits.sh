#!/bin/sh

for r in {qW,qZ}
do
	for y in {2016,Combined}
	do
		python beautiful_limits.py ${y}tau $r 
		python beautiful_limits.py ${y}db $r
	done
done
