g++ kmpmaker.cpp -o f
g++ 1.cpp
g++ ramtin.cpp	-o g	
for((i=0;i<100;i++))
do
	./f >p
	./a.out <p >om
	./g <p >og
	if diff og om -q
	then
		echo "accepted" $i
	else
		echo "wrong answer"
		exit 0
	fi
done
