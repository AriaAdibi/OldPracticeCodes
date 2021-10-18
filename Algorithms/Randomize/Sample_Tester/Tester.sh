g++ Checker.cpp -O2 -o Checker.out
g++ Test_Gen.cpp -O2 -o Gen.out
g++ Insertion_Sort.cpp -O2 -o myCode.out

for (( i=0; i<2000; i++ ))
do
	./Gen.out > input
	./Checker.out < input > ans
	./myCode.out < input > myOutPut
	if (diff -q ans myOutPut )
	then
		echo $i::OK!!;
	else
		echo $i::Wrong!!;
		
		exit 0;
	fi
done
