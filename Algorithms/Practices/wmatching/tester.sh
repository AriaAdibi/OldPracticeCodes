g++ gen.cpp -Wall -O2 -o g
g++ 1.cpp -Wall -O2 
g++ rahmtin.cpp -Wall -O2 -o f
for((i=0;i<100;i++))
do
echo $i"___________________"
./g>inp$i
./a.out<inp$i >out
./f<inp$i >out2
diff out out2 -sq

done
