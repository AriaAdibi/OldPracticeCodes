#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
const int MAX_N= 5* 1000* 2+ 100;
vector<int> pAdj_list[ MAX_N ];
vector<int> nAdj_list[ MAX_N ];

bool Mark[ MAX_N ];
vector<int> Tp;
int Com[ MAX_N ];

int f( const int &x ){
	if( x < 0 ) return n+(-x);
	else return x;
}

int f_nt( const int &x ){
	if( x < 0 ) return (-x);
	else return n+x;
}

void Input(){
	cin >> n >> m;
	for( int i=1, x, y; i<=m; i++ ){
		cin >> x >> y;
		pAdj_list[ f_nt(x) ].push_back( f(y) );
		nAdj_list[ f(y) ].push_back( f_nt(x) );

		pAdj_list[ f_nt(y) ].push_back( f(x) );
		nAdj_list[ f(x) ].push_back( f_nt(y) );
	}
}

void Topological_Sort( const int &v ){
	Mark[v]= 1;
	for( int j=0; j<(int)pAdj_list[v].size(); j++ ){
		int u= pAdj_list[v][j];
		if( !Mark[u] )
			Topological_Sort( u );
	}
	Tp.push_back( v );
}

void Find_STComponent( const int &v, const int &C ){
	Mark[v]= 1;
	for( int j=0; j<(int)nAdj_list[v].size(); j++ ){
		int u= nAdj_list[v][j];
		if( !Mark[u] )
			Find_STComponent( u, C );
	}
	Com[v]= C;
}

void Out_put(){
	bool is_OK= true;
	for( int i=1; i<=n; i++ )
		if( Com[i] == Com[ n+i ] )
		{ is_OK= false; break; }
	if( is_OK )
		cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main(){
	Input();
	for( int v=1; v<=2*n; v++ )
		if( !Mark[v] )
			Topological_Sort( v );

	reverse( Tp.begin(), Tp.end() );
	memset( Mark, 0, sizeof Mark );

	int nC= 0;
	fill( Com, Com+MAX_N, -1 );
	for( int i=0; i<2*n; i++ ){
		int v= Tp[i];
		if( !Mark[v] )
			Find_STComponent( v, nC++ );
	}

	Out_put();
	return 0;
}
