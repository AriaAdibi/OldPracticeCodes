#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int n;
const int MAX_N= 10* 1000;
bool Mark[ MAX_N ];
vector<int> Random;

bool Checker(){
	for( int i=1; i<=n; i++ ){
		if( !Mark[i] )
			return 1;
	}
	return 0;
}

int main(){
	srand( time(NULL) );
	cin >> n;
	do{
		int R= rand()%n+1;
		if( !Mark[R] ){
			Mark[R]= 1;
			Random.push_back( R );
		}
	}while( Checker() );
	for( int i=0; i<(int)Random.size(); i++ ){
		cout << Random[i] << " ";
	}
	cout << endl;
	return 0;
}
