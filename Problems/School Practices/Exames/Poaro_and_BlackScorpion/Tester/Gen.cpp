#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_N= 5;
const int MAX_l= 10;

void F( const int &r ){
	for( int i=0; i< r; i++ ){
		int length= rand()% MAX_l+ 1;
		cout << length << " ";
		for( int j=0; j<length; j++ )
			cout << rand()% 2 << " ";
		cout << endl;
	}
}

int main(){
	srand( time(NULL) );

	int n, m;
	n= rand()% MAX_N+ 1;
	m= rand()% MAX_N+ 1;
	cout << n << " " << m << endl;
	
	F( n ); F( m );
	return 0;
}
