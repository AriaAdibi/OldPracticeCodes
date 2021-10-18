#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

int n, m, Source;
vector< pair<int, pii> > Edge;

const int MAX_N= 100* 1000;
const int inf= 1000* 1000* 1000;
int dis[ MAX_N ];
int par[ MAX_N ];

void Input(){
	cin >> n >> m;
	for( int i=0, v, u, w; i<m; i++ ){
		cin >> v >> u >> w;
		v--; 	u--;
		Edge.push_back( pair<int,pii>( w, pii(v,u) ) );		//directed Graphs
	}
	cin >> Source;	Source--;
}

bool Bellman_ford(){
	fill( dis, dis+n, inf );
	dis[ Source ]= 0;

	for( int i=1; i<=n-1; i++ ){
		for( int j=0; j<m; j++ ){
			int v= Edge[j].Y.X; int u= Edge[j].Y.Y; int w= Edge[j].X;
			if( dis[u] > dis[v]+w ){
				par[u]= v;
				dis[u]= dis[v]+w;
			}
		}
	}
	//Check for negative Cycle
	for( int j=0; j<m; j++ ){
		int v= Edge[j].Y.X; int u= Edge[j].Y.Y; int w= Edge[j].X;
		if( dis[u] > dis[v]+w ){
			return 1;
		}
	}
	return 0;
}

void Show_dis(){
	for( int i=0; i<n; i++ ){
		cerr << i+1 << "th:: " << endl;
		cout << dis[i] << endl;
	}
}

int main(){
	Input();
	if( !Bellman_ford() ){
		cout << "We don't have negative Cycle" << endl;
		cerr << "Here is distances..." << endl;
		Show_dis();
	}
	else{
		cout << "Sorry, But we have negative Cycle" << endl;
	}
	return 0;
}
