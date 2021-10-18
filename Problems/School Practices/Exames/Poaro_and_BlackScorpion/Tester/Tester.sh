g++ Poaro_and_BlackScorpion.cpp -O2 -o a.out
g++ myChecker.cpp -O2 -o b.out
g++ Gen.cpp -O2 -o g.out
for ((i=0; i<1000; i++))
do
	./g.out > input
	./a.out < input > myOut
	./b.out < input > Ans
	if ( diff Ans myOut )
	then
		echo $i::OK!
	else
		echo $i::WRONG!
		cat input
		exit 0
	fi
done
