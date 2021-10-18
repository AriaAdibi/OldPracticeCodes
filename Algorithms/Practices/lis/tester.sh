g++ gen.cpp -Wall -O2 -o g
g++ 1.cpp -Wall -O2 
g++ ok.cpp -Wall -O2 -o f
g++ judge.cpp -Wall -O2 -o j
for((i=0;i<10;i++))
do
echo $i"___________________"
./g>inp$i
time ./a.out<inp$i >out
time ./f<inp$i >out2
./j<out
diff out out2 -sqb
done
