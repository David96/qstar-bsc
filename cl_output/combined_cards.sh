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


