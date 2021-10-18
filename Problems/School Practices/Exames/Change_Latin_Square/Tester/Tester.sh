g++ Change_Latin_Square_v3.cpp -O2 -o myCode.out
g++ myChecker.cpp -O2 -o myChecker.out
g++ Gen.cpp -O2 -o G.out
g++ CorrectCode.cpp -O2 -o C_Code.out
for ((i=0; i<1000; i++ ))
do
	./G.out < I > Tinput
	./C_Code.out < Tinput > C_OutPut
	./myCode.out < Tinput > myOutPut
	./myChecker.out < myOutPut > Ans
	if ( diff Ans Correct )
	then
		echo $i::OK!
	else
		if ( diff Ans A )
		then
			if ( diff C_OutPut B )
			then
				echo $i::OK!
			else
				echo $i::WRONG!
				cat Tinput
				exit 0
			fi
		else
			echo $i::WRONG!
			cat Tinput
			exit 0
		fi
	fi
done
