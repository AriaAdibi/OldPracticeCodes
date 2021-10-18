#include <iostream>
#include <vector>

using namespace std;

long long n;
vector<int> Dig;

void Input(){
	cin >> n;
}

void Insert_to_Dig(){
	while( n > 0 ){
		Dig.push_back( n % 10 );
		n/= 10;
	}
}

bool rem_17(){
	long long rem= 0; long long k=1;
	for( int i=0; i<(int)Dig.size(); i++ ){
		rem+= (Dig[i]* k)% 17;	rem%=17;
		k*= 10;	   k%= 17;
	}
	if( rem==0 ) return 1;
	else return 0;
}

int main(){
	Input();
	if( n==-1 ){
		cout << 1 << endl;
		return 0;
	}
	Insert_to_Dig();
	cout << rem_17() << endl;
	return 0;
}
