#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

int n, m, Source;
const int MAX_N= 100* 1000;
vector<pii> Adj_list[ MAX_N ];

const int inf= 1000* 1000* 1000;
int dis[ MAX_N ];
set<pii> Q;

void Input(){
	cin >> n >> m;
	for( int i=0, v, u, w; i<m; i++ ){
		cin >> v >> u >> w;
		v--; 	u--;
		Adj_list[v].push_back( pii(u,w) );	//in directed Graphs
	}
	cin >> Source;	Source--;
}

void Dijkstra(){
	fill( dis, dis+n, inf );
	dis[ Source ]= 0;
	for( int i=0; i<n; i++ ){
		Q.insert( pii(dis[i], i) );
	}

	while( !Q.empty() ){
		int v= Q.begin()->Y;
		Q.erase( Q.begin() );

		for( int i=0; i<(int)Adj_list[v].size(); i++ ){
			int u= Adj_list[v][i].X; int w= Adj_list[v][i].Y;
			if( dis[u] > dis[v]+ w ){
				Q.erase( pii(dis[u], u) );
				dis[u]= dis[v]+w;
				Q.insert( pii(dis[u], u) ); 
			}
		}
	}
}

void Out_put(){
	cerr << "Here is distances..." << endl;
	for( int i=0; i<n; i++ ){
		cerr << i+1 << "th::" << endl;
		cout << dis[i] << endl;
	}
}

int main(){
	Input();
	Dijkstra();
	Out_put();
	return 0;
}
