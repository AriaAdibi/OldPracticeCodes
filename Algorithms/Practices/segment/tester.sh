g++ gen.cpp -Wall -O2 -o g
g++ $1.cpp -Wall -O2 -o t 
g++ ok.cpp -Wall -O2 -o f
for((i=0;i<100;i++))
do
echo $i"___________________"
#./g>inp$i
./t.exe<inp$i >out
./f.exe<inp$i >out2
if diff out out2 -sqb
then
	echo "[accepted]"
else
	echo "[WRONG]"
	exit
fi

done
