#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int n;
const int MAX_N= 10;
bool Mark_row[ MAX_N ][ MAX_N ];
bool Mark_col[ MAX_N ][ MAX_N ];

int G[ MAX_N ][ MAX_N ];
int Goal[ MAX_N ][ MAX_N ];

void Input(){
	cin >> n;
}

bool Generate_random_lSquare( int R[][ MAX_N ], int t ){
	srand( time(NULL)+ t );
	for( int i=0; i<MAX_N; i++ ) memset( Mark_row[i], 0, sizeof Mark_row[i] );
	for( int i=0; i<MAX_N; i++ ) memset( Mark_col[i], 0, sizeof Mark_col[i] );

	for( int i=1; i<=n; i++ )
		for( int j=1; j<=n; j++ ){
			int w= 0;
			bool is_OK= 0;
			while( w< 100* 1000 ){
				w++;
				int x= rand()%n +1;
				if( !Mark_row[i][x] && !Mark_col[j][x] ){
					Mark_row[i][x]= 1;
					Mark_col[j][x]= 1;
					R[i][j]= x;
					is_OK= 1;
					break;
				}
			}
			if( !is_OK ) return 0; // we could not generate it
		}
	return 1;
}

void Out_put(){
	cout << n << endl;
	for( int i=1; i<=n; i++, cout << endl )
		for( int j=1; j<=n; j++ )
			cout << G[i][j] << " ";
	cout << endl;
	for( int i=1; i<=n; i++, cout << endl )
		for( int j=1; j<=n; j++ )
			cout << Goal[i][j] << " ";
}

int main(){
	Input();
	srand( time(NULL) );
	int t= rand()%1000;
	while( !Generate_random_lSquare( G, 0 ) );
	while( !Generate_random_lSquare( Goal, t ) );
	Out_put();
	return 0;
}
