#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

int n, m;
const int MAX_N= 100* 1000;
vector<pii> Adj_list[ MAX_N ];

int Min_edge[ MAX_N ];
pii Rep_edge[ MAX_N ];
const int inf= 1000* 1000* 1000;
set< pii > Q;
bool Is_in_Q[ MAX_N ];

int min_weight= 0;
vector<pii> MST;

void Input(){
	cin >> n >> m;
	for( int i=0, v, u, w; i<m; i++ ){
		cin >> v >> u >> w;
		v--;	u--;
		Adj_list[v].push_back( pii(u,w) );
		Adj_list[u].push_back( pii(v,w) );
	}
}

void MST_Prim(){
	Min_edge[ 0 ] = 0;	//!!
	fill( Min_edge+1, Min_edge+n, inf );
	Q.insert( pii(0,0) );
	for( int i=1; i<n; i++ ){
		Q.insert( pii(inf, i) );
	}
	fill( Is_in_Q, Is_in_Q+n, 1 );

	while( !Q.empty() ){
		int min_edge= Q.begin()->X; int v= Q.begin()->Y;	//Extract Min
		Q.erase( Q.begin() );	Is_in_Q[v]= 0;
	
		min_weight+= min_edge;
		MST.push_back( Rep_edge[v] );				//first element must not consider

		for( int i=0; i<(int)Adj_list[v].size(); i++ ){
			int u=Adj_list[v][i].X; int w= Adj_list[v][i].Y;
			if( Is_in_Q[u] && w < Min_edge[u] ){
				Q.erase( pii(Min_edge[u], u) );
				Min_edge[u]= w;
				Rep_edge[u]= pii(v,u);
				Q.insert( pii(Min_edge[u], u) );
			}
		}
	}
}

void Out_put(){
	cerr << "Here is your MST ... " << endl;
	cerr << "Here is min_weight ... " << endl;
	cout << min_weight << endl;
	cerr << "Now, Here is tree ... " << endl;
	for( int i=1; i<n; i++ ){
		cout << MST[i].X << " " << MST[i].Y << endl;
	}
}

int main(){
	Input();
	MST_Prim();
	Out_put();
	return 0;
}
