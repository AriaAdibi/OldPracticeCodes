#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

int n, m;
const int MAX_N= 5* 1000;
vector< pii > Adj_list[ MAX_N ];

const int inf= 1000* 1000* 1000;
int dis[ MAX_N ][ MAX_N ];

void Input(){
	cin >> n >> m;
	for( int i=0, v, u, w; i<m; i++ ){
		cin >> v >> u >> w;
		v--;	u--;
		Adj_list[v].push_back( pii(u ,w) );		//in directed Graphs
	}
}

void Floyd_Warshall(){
	for( int i=0; i<n; i++ ){
		fill( dis[i], dis[i]+n, inf );
	}
	for( int v=0; v<n; v++ ){
		for( int j=0; j<(int)Adj_list[v].size(); j++ ){
			int u= Adj_list[v][j].X; int w= Adj_list[v][j].Y;
			dis[v][u]= w;
		}
		dis[v][v]= 0;
	}
	
	for( int k=0; k<n; k++ ){
		for( int i=0; i<n; i++ ){
			for( int j=0; j<n; j++ ){
				dis[i][j]= min( dis[i][j], dis[i][k]+dis[k][j] );
			}
		}
	}
}

void Out_put(){
	int nquary;
	cerr << "Please Enter number of quary that you want..." << endl;
	cin >> nquary;
	cerr << "Now, Please Enter your vertexes..." << endl;
	for( int i=0, v; i<nquary; i++ ){
		cin >> v;
		for( int j=0; j<n; j++ ){
			if( dis[v][j] == inf )
				cout << "no_path" << " ";
			else
			cout << dis[v][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	Input();
	Floyd_Warshall();
	Out_put();
	return 0;
}
