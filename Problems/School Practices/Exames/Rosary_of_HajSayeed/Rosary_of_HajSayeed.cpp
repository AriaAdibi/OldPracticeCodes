#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
const int MAX_N= 100* 1000+ 100;

struct Bead_ith{
	int a, b, c;
	Bead_ith(){ a=0; b=0; c=0; }
	~Bead_ith(){}
};

Bead_ith Ros[ MAX_N ];
int nB_B[ MAX_N ];
int nB_C[ MAX_N ];

bool Mark_rm[ MAX_N ];
vector<int> rm;
int ans= 0;

void Input(){
	cin >> n;
	for( int i=0; i<n; i++ ) cin >> Ros[i].a;
	for( int i=0; i<n; i++ ) cin >> Ros[i].b;
	for( int i=0; i<n; i++ ) cin >> Ros[i].c;
}

bool Comp( const Bead_ith &x, const Bead_ith &y ){
	if( x.a < y.a ) return 1;
	return 0;
}

void Find_rm_in( int A[] ){
	for( int i=1; i<=n; i++ )
		if( A[i] == 0 && !Mark_rm[i] ){
			Mark_rm[i]= 1;
			rm.push_back( i );
		}
}

void mySolution(){
	sort( Ros, Ros+n, Comp );
	for( int i=0; i<n; i++ ) nB_B[ Ros[i].b ]++;
	for( int i=0; i<n; i++ ) nB_C[ Ros[i].c ]++;

	Find_rm_in( nB_B );
	Find_rm_in( nB_C );
	
	for( int i=0; i<(int)rm.size(); i++ ){
		int x= rm[i]-1;	//remove x( 0base )

		nB_B[ Ros[x].b ]--; 
		if( nB_B[ Ros[x].b ]==0 && !Mark_rm[ Ros[x].b ] ) 
		{ Mark_rm[ Ros[x].b ]= 1; rm.push_back( Ros[x].b ); }

		nB_C[ Ros[x].c ]--;
		if( nB_C[ Ros[x].c ]==0 && !Mark_rm[ Ros[x].c ] ) 
		{ Mark_rm[ Ros[x].c ]= 1; rm.push_back( Ros[x].c ); }

		ans++;
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
