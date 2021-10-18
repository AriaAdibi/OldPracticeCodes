#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

const int MAX= 500* 1000;
const int MAX_N= 500;
bool G[ MAX_N ][ MAX_N ];
bool hPath[ MAX_N ][ MAX_N ];
vector<pii> Our_DAG;

int main(){
	srand( time(NULL) );
	while( true ){
		Our_DAG.clear();
		for( int i=0; i<MAX_N; i++ ) memset( G[i], 0, sizeof G[i] );
		for( int i=0; i<MAX_N; i++ ) memset( hPath[i], 0, sizeof hPath[i] );

		int V= rand()% MAX_N;
		int E= rand()% ( (V*(V-1)/2)+ 1 );
		Our_DAG.push_back( pii(V-1, E-1) ); //will be +1
	
		for( int i=0; i<V; i++ ) hPath[i][i]= true;
		
		bool have_DAG= true;
		for( int i=0, t_in=0; i<E; i++, t_in++ ){
			int v=rand()% V; int u= rand()% V;

			if( v!=u && !G[v][u] && !hPath[u][v] ){
				t_in= 0;
				G[v][u]= 1;
				for( int x= 0; x<V; x++ )
					if( hPath[x][v] )
						for( int y=0; y<V; y++ )
							if( hPath[u][y] )
								hPath[x][y]= true;
				Our_DAG.push_back( pii(v, u) );
			}
			else i--;

			if( t_in > MAX )
			{ have_DAG= false; break; }
		}

		if( have_DAG ){
			for( int i=0; i<(int)Our_DAG.size(); i++ )
				cout << Our_DAG[i].X+ 1 << " " << Our_DAG[i].Y+ 1 << endl;
			break;
		}
		else continue;
	}
	return 0;
}
