#g++ gen.cpp -Wall -O2 -o g
g++ $1.cpp -Wall -O2 -o stu
g++ aban.cpp -Wall -O2 
g++ 1.cpp -Wall -O2 -o d
g++ ok.cpp -Wall -O2 -o f
for((i=0;i<100;i++))
do
echo $i"___________________"
#./g>inp$i
./f.exe<inp$i >out
time ./stu.exe<inp$i >myout
if diff out myout -sq
then
	echo "accepted"
else
	echo " Wrong"
	exit
fi
#time ./f<inp$i 
#time ./d<inp$i
done
