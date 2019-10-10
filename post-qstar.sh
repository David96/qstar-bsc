#!/bin/sh

for y in 20{16,17,18}
do
	sframe_main config/${y}/qstar-post.xml
	sframe_main config/${y}/qstar-lp.xml
	sframe_main config/${y}/qstar-z-post.xml
	sframe_main config/${y}/qstar-z-lp.xml
done
