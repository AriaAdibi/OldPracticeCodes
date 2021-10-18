#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

int n;
const int MAX_N= 200+ 10;
int G[ MAX_N ][ MAX_N ];
int Goal[ MAX_N ][ MAX_N ];

int nCh;
vector<pii> Ch_row;
vector<pii> Ch_col;

bool Input(){
	cin >> n;
	for( int i=1; i<=n; i++ )
		for( int j=1; j<=n; j++ )
			cin >> G[i][j];
	for( int i=1; i<=n; i++ )
		for( int j=1; j<=n; j++ )
			cin >> Goal[i][j];
	cin >> nCh;
	if( nCh == -1 ) return 0;
	string S;
	for( int i=1; i<=nCh; i++ ){
		int x, y;
		cin >> S >> x >> y;
		if( S == "row" ) Ch_row.push_back( pii(x, y) );
		else Ch_col.push_back( pii(x, y) );
	}
	return 1;
}

bool Perform_Changes(){
	for( int i=0; i<(int)Ch_row.size(); i++ ){
		int r1= Ch_row[i].X; int r2= Ch_row[i].Y;
		for( int j=1; j<=n; j++ ) swap( G[r1][j], G[r2][j] );
	}
	for( int j=0; j<(int)Ch_col.size(); j++ ){
		int c1= Ch_col[j].X; int c2= Ch_col[j].Y;
		for( int i=1; i<=n; i++ ) swap( G[i][c1], G[i][c2] );
	}
	//Checker
	for( int i=1; i<=n; i++ )
		for( int j=1; j<=n; j++ )
			if( G[i][j] != Goal[i][j] )
				return 0;
	return 1;
}

int main(){
	if( Input() )
		if( Perform_Changes() )
			cout << 1 << endl;
		else cout << 0 << endl;
	else{ 
		cerr << "-1" << endl;
		cout << 2 << endl;
	}
	return 0;
}
