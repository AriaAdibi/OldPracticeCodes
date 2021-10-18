#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const long long At_least= 1;
const long long MAX_N= 1e17-At_least+ 1;

int main(){
	srand( time(NULL) );
	long long n= rand()% MAX_N+ At_least;
	cout << n << endl;
	return 0;
}
