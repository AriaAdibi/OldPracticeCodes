#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int nW;
const int MAX_nW= 500+ 10;
vector<int> S;
vector<int> Word[ MAX_nW ];

const int MAX_Wl= 200+ 10;
int nxt[ MAX_Wl ];
int ans= 0;

vector<int> Convert_to_Vec( const string &W ){
	vector<int> Wp;
	for( int i=0; i<(int)W.size(); i++ )
		Wp.push_back( W[i]- 'a' );
	return Wp;
}

void Input(){
	cin >> nW;
	for( int i=0; i<nW; i++ ){
		string W;  cin >> W;
		Word[i]= Convert_to_Vec( W );
	}
	string T;  cin >> T;
	S= Convert_to_Vec( T );
}

void Find_nxt( const int &r, const vector<int> &W ){
	nxt[0]= 0;
	for( int i=1; i<(int)Word[r].size(); i++ ){
		int j= nxt[i-1]; //j=i; j=nxt[j-1];
		while( W[j] != W[i] && j > 0 )
			j= nxt[j-1];
		if( !(j==0 && W[i] != W[0] ) )  nxt[i]= j+1; //else nxt[i]= 0;
	}
}

void myKMP( const int &r ){
	vector<int> W= Word[r];
	Find_nxt( r, W );
	int Cur_l= 0;
	for( int i=0; i<(int)S.size(); i++ ){
		while( S[i] != W[ Cur_l ] && Cur_l > 0 )
			Cur_l= nxt[ Cur_l-1 ];
		if( !(Cur_l==0 && S[i]!=W[0] ) ) Cur_l++;  //else Cur_l= 0;
		
		if( Cur_l == (int)W.size() )
		{  ans ++;  Cur_l= nxt[ W.size()-1 ]; }
	}
}

void Out_put(){
	cout << ans << endl;
}

int main(){
	Input();

	for( int i=0; i<nW; i++ ){
		memset( nxt, 0, sizeof nxt );	
		myKMP( i );
	}

	Out_put();
	return 0;
}
