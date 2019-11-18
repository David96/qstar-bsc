#!/bin/sh

for y in 20{16,17,18}
do
	sframe_batch.py -s config/${y}/qcd-post.xml
	sframe_batch.py -s config/${y}/qcd-lp.xml
	sframe_batch.py -s config/${y}/data-post.xml
	sframe_batch.py -s config/${y}/data-lp.xml
done
