#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n, e;
const int inf= 1e9;
const int MAX_N= 5000;
vector<int> Adj_list[ MAX_N ];

bool Mark_DFS[ MAX_N ];
int H[ MAX_N ];
int H_ST[ MAX_N ];
set<int> Root;
int Par[ MAX_N ];
vector<int> Child[ MAX_N ];

vector< int > CutV;

void Input(){
	cin >> n >> e;
	for( int i=0, u, v; i<e; i++ ){
		cin >> v >> u;	v--;  u--;
		Adj_list[v].push_back( u );
		Adj_list[u].push_back( v );
	}
}

void DFS( const int &v, const int &h ){
	Mark_DFS[v]= 1;
	H[v]= h;

	for( int j=0; j<(int)Adj_list[v].size(); j++ ){
		int u= Adj_list[v][j];	
		if( !Mark_DFS[u] ){
			Par[u]= v;
			DFS( u, h+1 );
			Child[v].push_back( u );
		}
	}

	for( int j=0; j<(int)Adj_list[v].size(); j++ ){
		int u= Adj_list[v][j];
		if( u != Par[v] )
			H_ST[v]= min( H_ST[v], H[u] );
	}

	for( int j=0; j<(int)Child[v].size(); j++ ){
		int u= Child[v][j];
		H_ST[v]= min( H_ST[v], H_ST[u] );	
	}
}

void Find_Cut_Vertex(){
	for( int v=0; v<n; v++ )
		if( Root.find( v ) == Root.end() )
			for( int j=0; j<(int)Child[v].size(); j++ ){
				int u= Child[v][j];
				if( H_ST[u] >= H[v] ){
					CutV.push_back( v );
					break;
				}
			}
	for( set<int>::iterator it= Root.begin(); it!=Root.end(); it++ ){
		int v= *it;
		if( Child[v].size() > 1 )
			CutV.push_back( v );
	}
}

void Out_put(){
	sort( CutV.begin(), CutV.end() );

	cout << CutV.size() << endl;
	for( int i=0; i<(int)CutV.size(); i++ )
		cout << CutV[i]+1 << endl;
}

int main(){
	Input();

	fill( H_ST+0, H_ST+MAX_N, inf );
	for( int i=0; i<n; i++ )	//my Dynamic_Solution
		if( !Mark_DFS[i] ){
			Root.insert( i );
			Par[i]= -1;
			DFS( i, 0 );
		}
	Find_Cut_Vertex();
	/**
	for( int i=0; i<n; i++ )
		cerr << H[i] << " ";
	cerr << endl;
	for( int i=0; i<n; i++ )
		cerr << H_ST[i] << " ";
	cerr << endl;
	cerr << string( 15, '*' ) << endl;
	for( int i=0; i<n; i++, cerr << endl )
		for( int j=0; j<(int)Child[i].size(); j++ )
			cerr << Child[i][j]+1 << " ";
	/**/
	Out_put();
	return 0;
}
