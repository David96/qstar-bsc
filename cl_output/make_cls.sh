#!/bin/sh
cd ../datacards/2016/deep_boosted/HP
echo "Combining cards for 2016, deep_boosted"
pwd
for i in *.txt; do combineCards.py $i ../LP/$i > ../$i; done
cd ..
for i in *.txt; do sed -i "s/\.\.\/LP\///g" $i; done
for i in *.txt; do sed -i "s/\.\.\/\.\.\/\.\.\//\.\.\/\.\.\//g" $i; done

cd ../tau21/HP
echo "Combining cards for 2016, tau21"
pwd
for i in *.txt; do combineCards.py $i ../LP/$i > ../$i; done
cd ..
for i in *.txt; do sed -i "s/\.\.\/LP\///g" $i; done
for i in *.txt; do sed -i "s/\.\.\/\.\.\/\.\.\//\.\.\/\.\.\//g" $i; done

cd ../../2017/deep_boosted/HP
echo "Combining cards for 2017, deep_boosted"
pwd
for i in *.txt; do combineCards.py $i ../LP/$i > ../$i; done
cd ..
for i in *.txt; do sed -i "s/\.\.\/LP\///g" $i; done
for i in *.txt; do sed -i "s/\.\.\/\.\.\/\.\.\//\.\.\/\.\.\//g" $i; done

cd ../tau21/HP
echo "Combining cards for 2017, tau21"
pwd
for i in *.txt; do combineCards.py $i ../LP/$i > ../$i; done
cd ..
for i in *.txt; do sed -i "s/\.\.\/LP\///g" $i; done
for i in *.txt; do sed -i "s/\.\.\/\.\.\/\.\.\//\.\.\/\.\.\//g" $i; done

cd ../../2018/deep_boosted/HP
echo "Combining cards for 2018, deep_boosted"
pwd
for i in *.txt; do combineCards.py $i ../LP/$i > ../$i; done
cd ..
for i in *.txt; do sed -i "s/\.\.\/LP\///g" $i; done
for i in *.txt; do sed -i "s/\.\.\/\.\.\/\.\.\//\.\.\/\.\.\//g" $i; done

cd ../tau21/HP
echo "Combining cards for 2018, tau21"
pwd
for i in *.txt; do combineCards.py $i ../LP/$i > ../$i; done
cd ..
for i in *.txt; do sed -i "s/\.\.\/LP\///g" $i; done
for i in *.txt; do sed -i "s/\.\.\/\.\.\/\.\.\//\.\.\/\.\.\//g" $i; done

cd ../../combined/deep_boosted/HP
echo "Combining cards for all of them, deep_boosted"
pwd
for i in *.txt; do combineCards.py $i ../LP/$i > ../$i; done
cd ..
for i in *.txt; do sed -i "s/\.\.\/LP\///g" $i; done
for i in *.txt; do sed -i "s/\.\.\/\.\.\/\.\.\//\.\.\/\.\.\//g" $i; done

cd ../tau21/HP
echo "Combining cards for all of them, tau21"
pwd
for i in *.txt; do combineCards.py $i ../LP/$i > ../$i; done
cd ..
for i in *.txt; do sed -i "s/\.\.\/LP\///g" $i; done
for i in *.txt; do sed -i "s/\.\.\/\.\.\/\.\.\//\.\.\/\.\.\//g" $i; done

cd ../../../cl_output
pwd
cd 2016db
./doemall.sh
./doemall-z.sh
#cd HP
#./doemall.sh
#./doemall-z.sh
#cd ../LP
#./doemall.sh
#./doemall-z.sh
#cd ..

#cd ../2016tau
#./doemall.sh
#./doemall-z.sh
#cd HP
#./doemall.sh
#./doemall-z.sh
#cd ../LP
#./doemall.sh
#./doemall-z.sh
#cd ..

#cd ../2017db
#./doemall.sh
#./doemall-z.sh
#cd HP
#./doemall.sh
#./doemall-z.sh
#cd ../LP
#./doemall.sh
#./doemall-z.sh
#cd ..
#
#cd ../2017tau
#./doemall.sh
#./doemall-z.sh
#cd HP
#./doemall.sh
#./doemall-z.sh
#cd ../LP
#./doemall.sh
#./doemall-z.sh
#cd ..
#
#cd ../2018db
#./doemall.sh
#./doemall-z.sh
#cd HP
#./doemall.sh
#./doemall-z.sh
#cd ../LP
#./doemall.sh
#./doemall-z.sh
#cd ..
#
#cd ../2018tau
#./doemall.sh
#./doemall-z.sh
#cd HP
#./doemall.sh
#./doemall-z.sh
#cd ../LP
#./doemall.sh
#./doemall-z.sh
#cd ..

#cd ../Combineddb
#./doemall.sh
#./doemall-z.sh
#cd HP
#./doemall.sh
#./doemall-z.sh
#cd ../LP
#./doemall.sh
#./doemall-z.sh
#cd ..

#cd ../Combinedtau
#./doemall.sh
#./doemall-z.sh
#cd HP
#./doemall.sh
#./doemall-z.sh
#cd ../LP
#./doemall.sh
#./doemall-z.sh
cd ../..
