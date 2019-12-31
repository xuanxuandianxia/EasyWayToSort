#!/usr/bin/fish
make
echo "enter the biggest number you want:"
read max
chmod a+x random 
chmod a+x sort
./random $max
chmod a+rw random_num.txt
./sort $max
chmod a+rw Sorted_num.txt


