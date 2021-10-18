#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int t, n;
const int MAX_N= 50* 1000+ 100;
vector<int> pAdj_list[ MAX_N ];

bool Mark_V[ MAX_N ];
vector<int> Tp;

void Reset(){
	Tp.clear();
	for( int i=0; i<MAX_N; i++ ) pAdj_list[i].clear();
	memset( Mark_V, 0, sizeof Mark_V );
}

void Input(){
	int E; cin >> E; n= E+1;
	for( int i=0, v, u; i<n-1; i++ ){
		cin >> v >> u; v--; u--;
		pAdj_list[v].push_back( u );
	}
}

void Topological_Sort( const int &v ){
	Mark_V[v]= true;
	for( int j=0; j<(int)pAdj_list[v].size(); j++ ){
		int u= pAdj_list[v][j];
		if( !Mark_V[u] )
			Topological_Sort( u );
	}
	Tp.push_back( v );
}

bool DFS( const int &v ){
	Mark_V[v]= true;
	for( int j=0; j<(int)pAdj_list[v].size(); j++ ){
		int u= pAdj_list[v][j];
		if( !Mark_V[u] )
			DFS( u );
	}
}

int main(){
	cin >> t;
	for( int i=0; i<t; i++ ){
		Reset();
		Input();

		for( int v=0; v<n; v++ )
			if( !Mark_V[v] )
				Topological_Sort( v );

		reverse( Tp.begin(), Tp.end() );
		memset( Mark_V, 0, sizeof Mark_V );

		DFS( Tp[0] );
		bool Is_rTree= true;
		for( int v=0; v<n; v++ )
			if( !Mark_V[v] )
			{ Is_rTree= false; break; }
		if( Is_rTree )
			cout << Tp[0]+1 << endl;
		else cout << "This is not a tree!" << endl;
	}
	return 0;
}
