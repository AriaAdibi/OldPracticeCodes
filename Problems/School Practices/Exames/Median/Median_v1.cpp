#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, x, ind_x;
const int MAX_N= 100 *1000+ 100;
int Per[ MAX_N ];

vector<int> bx, ax;
long long ans= 0;

void Input(){
	cin >> n >> x;
	for( int i=0; i<n; i++ ){
		cin >> Per[i];
		if( Per[i] == x ) ind_x= i;
	}
}

void mySolution(){
	bx.push_back( 0 ); //from ind_x to ind_x
	for( int i=ind_x-1; i>=0; i-- )		//nSmaller- nBigger
		if( Per[i] > x ) bx.push_back( bx.back() -1 );
		else bx.push_back( bx.back() +1 ); //reverse
	if( ind_x+ 1 < n ){
		if( Per[ ind_x+ 1 ] > x ) ax.push_back( -1 );
		else ax.push_back( 1 );
		for( int i= ind_x+2; i<n; i++ )
			if( Per[i] > x ) ax.push_back( ax.back() -1 );
			else ax.push_back( ax.back() +1 );
	}

	sort( ax.begin(), ax.end() );
	for( int i=0; i<(int)bx.size(); i++ ){
		if( bx[i] == 0 ) ans++;
		int from= ( lower_bound( ax.begin(), ax.end(), -bx[i] )- ax.begin() );  //[
		int to= ( upper_bound( ax.begin(), ax.end(), -bx[i] )- ax.begin() );    //)
		ans+= (to- from);
	}
}

void Out_put(){
	cout << ans << endl;
}

int main(){
	Input();
	mySolution();
	Out_put();
	return 0;
}
