g++ gen.cpp -Wall -O2 -o g
g++ 1.cpp -Wall -O2 
for((i=0;i<10;i++))
do
echo $i"___________________"
./g>inp$i
./a.out<inp$i 
done
