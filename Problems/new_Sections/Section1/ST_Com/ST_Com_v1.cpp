#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, e;
const int MAX_N= 1000* 1000+ 1000;
vector<int> pAdj_list[ MAX_N ];
vector<int> nAdj_list[ MAX_N ];

bool Mark_V[ MAX_N ];
vector<int> Tp;
vector<int> Com[ MAX_N ];

void Input(){
	cin >> n >> e;
	for( int i=0, v, u; i<e; i++ ){
		cin >> v >> u;
		v--; u--;
		pAdj_list[v].push_back( u );
		nAdj_list[u].push_back( v );
	}
	/**
	for( int i=0; i<n; i++ ){
		cerr << "i= " << i << ":: ";
		for( int j=0; j<(int)pAdj_list[i].size(); j++ )
			cerr << pAdj_list[i][j] << " ";
		cerr << endl;
	}/**/
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

void Find_Com( const int &v, const int &C ){
	Mark_V[v]= 1;
	for( int j=0; j<(int)nAdj_list[v].size(); j++ ){
		int u= nAdj_list[v][j];
		if( !Mark_V[u] )
			Find_Com( u, C );
	}
	Com[C].push_back( v );
}

bool Comp( const int &x, const int &y ){
	if( Com[x][0] < Com[y][0] )
		return 1;
	return 0;
}

void Out_put( const int &nC ){
	for( int i=0; i<nC; i++ )
		sort( Com[i].begin(), Com[i].end() );
	
	vector<int> Order_out;
	for( int i=0; i<nC; i++ ) Order_out.push_back( i );

	sort( Order_out.begin(), Order_out.end(), Comp );

	cout << nC << endl;
	for( int i=0; i<(int)Order_out.size(); i++ ){
		int C= Order_out[i];
		for( int j=0; j<(int)Com[C].size(); j++ )
			cout << Com[C][j]+1 << " ";
		cout << endl;
	}
}

int main(){
	Input();
	for( int i=0; i<n; i++ )
		if( !Mark_V[i] )
			Topological_Sort( i );

	memset( Mark_V, 0, sizeof Mark_V );
	reverse( Tp.begin(), Tp.end() );

	/**
	for( int i=0; i<n; i++ )
		cerr << Tp[i] << " ";
	cerr << endl;/**/

	int nC= 0;
	for( int i=0; i<n; i++ ){
		int v= Tp[i];
		if( !Mark_V[v] ){
			//cerr << "v= " << v << endl;
			Find_Com( v, nC++ );
		}
	}
	
	Out_put( nC );
	return 0;
}
