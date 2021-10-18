#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

int n;
const int MAX_N= 200+ 10;
int G[ MAX_N ][ MAX_N ];
int Goal[ MAX_N ][ MAX_N ];

int H[ MAX_N ][ MAX_N ];
int T[ MAX_N ][ MAX_N ];

vector<pii> tcol;
vector<pii> trow;

void Out_put( bool );
void Input(){
	cin >> n;
	for( int i=1; i<=n; i++ )
		for( int j=1; j<=n; j++ )
			cin >> G[i][j];
	for( int i=1; i<=n; i++ )
		for( int j=1; j<=n; j++ )
			cin >> Goal[i][j];
}

void Move_arr( int A[][ MAX_N ], int B[][ MAX_N ] ){
	for( int i=0; i<MAX_N; i++ ) memset( A[i], 0, sizeof A[i] );
	for( int i=1; i<=n; i++ )
		for( int j=1; j<=n; j++ )
			A[i][j]= B[i][j];
}

void Change_to_H(){
	for( int j=1; j<=n; j++ )
		for( int i=1; i<=n; i++ )
			H[i][ Goal[1][j] ]= Goal[i][j];
}

bool Is_Selection_OK( const int &r ){
	trow.clear();
	Move_arr( T, G );

	if( r!=1 ){
		trow.push_back( pii(1, r) );
		for( int j=1; j<=n; j++ ) swap( T[1][j], T[r][j] );
	}

	int f= T[1][1];
	for( int k=2; k<=n; k++ )
		for( int i=k; i<=n; i++ )
			if( T[i][1] == H[k][f] ){
				if( i!=k ){
					trow.push_back( pii(k, i) );
					for( int j=1; j<=n; j++ ) swap( T[i][j], T[k][j] );
				}
				break;
			}
	//Check cols
	for( int j=1; j<=n; j++ )
		for( int i=1; i<=n; i++ )
			if( T[i][j] != H[i][ T[1][j] ] )
				return 0;
	return 1;
}

void Find_tcol( const int &r ){
	for( int k=1; k<=n; k++ )
		for( int j=k; j<=n; j++ )
			if( Goal[1][k] == G[r][j] ){
				if( j!= k ){
					tcol.push_back( pii(k, j) );
					for( int i=1; i<=n; i++ ) swap( G[i][k], G[i][j] );
				}
				break;
			}
}

void mySolution(){
	Change_to_H();
	bool is_OK= 0;
	for( int i=1; i<=n; i++ )
		if( Is_Selection_OK( i ) )
		{ Find_tcol( i ); Out_put( true ); is_OK= 1; break; }
	if( !is_OK ) Out_put( false );
}

void Out_put( bool is_OK ){
	if( !is_OK )
		cout << -1 << endl;
	else{
		cout << (int)(trow.size()+tcol.size()) << endl;
		for( int i=0; i<(int)trow.size(); i++ )
			cout << "row " << trow[i].X << " " << trow[i].Y << endl;
		for( int i=0; i<(int)tcol.size(); i++ )
			cout << "col " << tcol[i].X << " " << tcol[i].Y << endl;
	}
}

int main(){
	Input();
	mySolution();
	return 0;
}
