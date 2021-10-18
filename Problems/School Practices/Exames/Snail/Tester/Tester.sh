g++ Snail.cpp -o a.out
g++ Checker.cpp -O2 -o b.out
g++ Gen.cpp -O2 -o g.out
for ((i=0; i<1000; i++ ))
do
	./g.out > Input
	./a.out < Input > myAns
	./b.out < Input > Ans
	if ( diff Ans myAns )
	then
		echo $i::OK!
	else
		echo $i::WRONG!
		cat Input
		exit 0
	fi
done
