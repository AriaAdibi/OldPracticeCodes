g++ Spanning_Path_v1.cpp -O2 -o a.out
g++ myChecker.cpp -O2 -o b.out
g++ Gen.cpp -O2 -o g.out
for ((i=0; i<5000; i++ ))
do
	./g.out > input
	./a.out < input > myOut
	./b.out < input > ans
	if (diff ans myOut )
	then
		echo $i::OK!
	else
		echo $i::WRONG!
		cat > error < input
		cat input
		exit 0
	fi
done
