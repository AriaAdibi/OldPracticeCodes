g++ gen.cpp -Wall -O2 -o g
g++ 1.cpp -Wall -O2 
g++ maxmatch.cpp -Wall -O2 -o f
for((i=0;i<10;i++))
do
echo $i"___________________"
./g>inp$i
./a.out<inp$i >out
./f<inp$i >out2
cat out 
cat out2

done
