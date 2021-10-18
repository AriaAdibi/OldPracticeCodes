#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int nTest;
const int MAX_N= 50+ 10;
const int MAX_VAL= 512;
vector<int> Cart;

bool d[ MAX_VAL ][ MAX_N ];

void Reset(){
	Cart.clear();
	for( int l=0; l<MAX_VAL; l++ ) memset( d[l], 0, sizeof d[l] );
}

void Input(){
	int x;
	do{
		cin >> x;
		Cart.push_back( x );
	}while( x != -1 );
	Cart.pop_back();
}

void myDynamic_Solution(){
	int n= (int)Cart.size();
	d[511][n]= 1;

	for( int i=n-1; i>=0; i-- )
		for( int l=0; l<MAX_VAL; l++ )
			if( l == 511 )
				d[l][i]= 1;
			else{
				int nCandidate= 0;
				for( int j=0; j<n; j++ )
					if( (Cart[j] | l) == l )
						nCandidate++;
					else if( d[ (Cart[j] | l) ][ i+1 ] == 0 )
					{ d[l][i]= 1; break; }

				if( nCandidate- i > 0 && d[l][i+1] == 0 )
					d[l][i]= 1;
			}
}

void Out_put(){
	if( d[0][0] )
		cout << "Fox Ciel" << endl;
	else cout << "Toastman" << endl;
}

int main(){
	cin >> nTest;
	for( int i=0; i<nTest; i++ ){
		Reset();
		Input();
		myDynamic_Solution();
		Out_put();
	}
	return 0;
}
