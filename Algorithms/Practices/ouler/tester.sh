g++ gen.cpp -Wall -O2 -o g
g++ 1.cpp -Wall -O2 
g++ judge.cpp -Wall -O2 -o f
for((i=0;i<10;i++))
do
echo $i"___________________"
./g>inp$i
time ./a.out<inp$i >>inp$i
./f<inp$i

done
