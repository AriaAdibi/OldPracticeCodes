#include <iostream>
#include <vector>

using namespace std;

int n, m;
const int MAX_N= 100* 1000;
vector<int> Adj_list[ MAX_N ];

bool Mark_Tp[ MAX_N ];
vector<int> Tp;

void Input(){
	cin >> n >> m;
	for( int i=0, v, u; i<m; i++ ){
		cin >> v >> u;
		v--;	u--;
		Adj_list[v].push_back( u );
	}
}

void DFS( const int &v ){
	Mark_Tp[ v ]= 1;
	for( int i=0; i<(int)Adj_list[v].size(); i++ ){
		int u= Adj_list[v][i];
		if( !Mark_Tp[u] ){
			DFS( u );
		}
	}
	Tp.push_back( v );
}

void Topological_Sort(){
	for( int i=0; i<n; i++ ){
		if( !Mark_Tp[i] ){
			DFS( i );
		}
	}
}

void Out_put(){
	cerr << "Here is your Tp_Sorted Graph..." << endl;
	for( int i=(int)Tp.size()-1; i>=0; i-- ){
		cout << Tp[i] << " ";
	}
	cout << endl;
}

int main(){
	Input();
	Topological_Sort();
	Out_put();
	return 0;
}
