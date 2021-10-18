#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

const int MAX= 1000* 1000;
const int MAX_V= 12;
bool G[ MAX_V ][ MAX_V ];
bool Mark_to[ MAX_V ][ MAX_V ];

vector< pii > A;

int main(){
	srand( time(NULL) );
	int n= rand()% 4;
	cout << n << endl;

	for( int t=0; t<n; t++ ){
		A.clear();
		for( int i=0; i<MAX_V; i++ ) memset( G[i], 0, sizeof G[i] );
		for( int i=0; i<MAX_V; i++ ) memset( Mark_to[i], 0, sizeof Mark_to[i] );

		int V= rand()% MAX_V; int E= rand()%( (V*(V-1)/2)+ 1 );
		A.push_back( pii( V, E ) );

		for( int i=1; i<=V; i++ ) Mark_to[i][i]= 1;

		int t_in= 0; bool print= true;
		for( int i=0; i<E; i++, t_in++ ){
			int v= rand()%V+ 1; int u= rand()%V+ 1;
			if( v!=u && !G[v][u] && !Mark_to[u][v] ){
				t_in= 0;
				G[v][u]= 1;
				for( int x=1; x<=V; x++ )
					if( Mark_to[x][v] )
						for( int y=1; y<=V; y++ )
							if( Mark_to[u][y] && !Mark_to[x][y] )
								Mark_to[x][y]= 1;
				A.push_back( pii( v, u ) );
			}
			else i--;
			if( t_in > MAX )
			{ print= false; break; }
		}

		if( print )
			for( int i=0; i<(int)A.size(); i++ )
				cout << A[i].X << " " << A[i].Y << endl;
		else t--;
	}
	return 0;
}
