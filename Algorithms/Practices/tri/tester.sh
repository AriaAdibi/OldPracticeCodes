g++ 1.cpp -Wall -O2
for((i=1;i<2;i++))
do
echo $i"___________________"
./a.out<tri3b.in >out
diff out tri3b.out -sqb
done
