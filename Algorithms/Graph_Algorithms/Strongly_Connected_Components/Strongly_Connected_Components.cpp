#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
const int MAX_N= 100* 1000;
vector< int > Adj_list[ MAX_N ];
vector< int > rAdj_list[ MAX_N ];

bool Mark_Tp[ MAX_N ];
vector< int > Tp;

bool Mark_SC_Comp[ MAX_N ];
int nSC_Component= 0;
vector< int > SC_Component[ MAX_N ];

void Input(){
	cin >> n >> m;
	for( int i=0, v, u; i<m; i++ ){
		cin >> v >> u;
		v--;	u--;
		Adj_list[v].push_back( u );
		rAdj_list[u].push_back( v );
	}
}

void Tp_DFS( const int &v ){
	Mark_Tp[v]= 1;
	for( int i=0; i<(int)Adj_list[v].size(); i++ ){
		int u= Adj_list[v][i];
		if( !Mark_Tp[u] ){
			Tp_DFS( u );
		}
	}
	Tp.push_back( v );
}

void Topological_Sort(){
	for( int i=0; i<n; i++ ){
		if( !Mark_Tp[i] ){
			Tp_DFS( i );
		}
	}
	reverse( Tp.begin(), Tp.end() );
}

void SC_Comp( const int &v, const int &color ){
	Mark_SC_Comp[v]= 1;
	for( int i=0; i<(int)rAdj_list[v].size(); i++ ){
		int u= rAdj_list[v][i];
		if( !Mark_SC_Comp[u] ){
			SC_Comp( u, color );
		}
	}
	SC_Component[color].push_back( v );
}

void Find_SC_Component(){
	Topological_Sort();

	for( int i=0; i<n; i++ ){
		int v= Tp[i];
		if( !Mark_SC_Comp[v] ){
			SC_Comp( v, ++nSC_Component );
		}
	}
}

void Out_put(){
	cerr << endl;
	cerr << "Here is your Strongly Connected Components ..." << endl << endl;
	cerr << "Number of Strongly Connected Components ..." << endl;
	cout << nSC_Component << endl;
	cerr << "Here is Components ..." << endl;
	for( int i=1; i<=nSC_Component; i++ ){
		cerr << i << "th:" << endl;
		sort( SC_Component[i].begin(), SC_Component[i].end() );
		for( int j=0; j<(int)SC_Component[i].size(); j++ ){
			cout << SC_Component[i][j]+1 << " ";
		}
		cout << endl;
	}
}

int main(){
	Input();
	Find_SC_Component();
	Out_put();
	return 0;
}
