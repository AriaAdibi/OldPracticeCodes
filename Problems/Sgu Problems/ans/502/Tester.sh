g++ 502.cpp -O2 -o my_Code.out
g++ Checker.cpp -O2 -o Checker.out
g++ Gen.cpp -O2 -o Gen.out
for ((i=0; i<3000; i++))
do
	./Gen.out > input
	./my_Code.out < input > my_OutPut
	./Checker.out < my_OutPut > Ans
	if ( diff Ans Correct )
	then
		echo $i::OK!
	else
		echo $i::Wrong!!
		cat input
		exit 0
	fi
done
