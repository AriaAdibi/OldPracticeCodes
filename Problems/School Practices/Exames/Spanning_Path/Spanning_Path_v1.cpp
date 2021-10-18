#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, V, E;
const int MAX_V= 5* 1000+ 100;
vector<int> pAdj_list[ MAX_V ];

bool Mark_V[ MAX_V ];
vector<int> Tp;

void Reset(){
	V= 0; E= 0;
	for( int i=0; i<V; i++ ) pAdj_list[i].clear();
	memset( Mark_V, 0, sizeof Mark_V );
	Tp.clear();
}

void Input(){
	cin >> V >> E;
	for( int i=0, v, u; i<E; i++ ){
		cin >> v >> u;	v--; u--;
		pAdj_list[v].push_back( u );
	}
}

void Topological_Sort( const int &v ){
	Mark_V[v]= 1;
	for( int j=0; j<(int)pAdj_list[v].size(); j++ ){
		int u= pAdj_list[v][j];
		if( !Mark_V[u] )
			Topological_Sort( u );
	}
	Tp.push_back( v );
}

void Out_put(){
	reverse( Tp.begin(), Tp.end() );
	bool have_Spath= 1;
	for( int i=0; i<V-1; i++ ){
		int v= Tp[i]; int next_v= Tp[i+1];

		bool have_edge= 0;
		for( int j=0; j<(int)pAdj_list[v].size(); j++ ){
			int u= pAdj_list[v][j];
			if( u == next_v )
			{ have_edge= 1; break; }
		}
		if( !have_edge )
		{ have_Spath= 0; break; }
	}
	if( have_Spath )
		cout << "Good Luck President!" << endl;
	else cout << "Sorry President!" << endl;
}

int main(){
	cin >> n;
	for( int i=0; i<n; i++ ){
		Reset();
		Input();
		for( int v=0; v<V; v++ )
			if( !Mark_V[v] )
				Topological_Sort( v );
		Out_put();
	}
	return 0;
}
