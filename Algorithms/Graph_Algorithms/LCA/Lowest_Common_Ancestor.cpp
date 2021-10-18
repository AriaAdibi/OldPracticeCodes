#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

int n, nQ;
const int MAX_N= 100* 1000;
vector<int> Adj_list[ MAX_N ];
vector<pii> Quary;

const int MAX_B= 30;
bool Mark[ MAX_N ];
int H[ MAX_N ];
int B[ MAX_B ];
int Par[ MAX_B ][ MAX_N ];

void Input(){
	cin >> n;
	for( int i=0, v, u; i<n-1; i++ ){	//1base
		cin >> v >> u;
		Adj_list[v].push_back( u );
		Adj_list[u].push_back( v );
	}
	cin >> nQ;
	for( int i=0, v, u; i<nQ; i++ ){
		cin >> v >> u;
		Quary.push_back( pii(v, u) );
	}
}

void Preprocess( const int &v, const int &h ){
	Mark[v]= 1;
	H[v]= h;
	
	for( int i=1; B[i] <= H[v]; i++ )
		Par[i][v]= Par[i-1][ Par[i-1][v] ];

	for( int j=0; j<(int)Adj_list[v].size(); j++ ){
		int u= Adj_list[v][j];
		if( !Mark[u] ){
			Par[0][u]= v;
			Preprocess( u, h+1 );
		}
	}
}

void Find_LCA( int &v, int &u ){
	if( H[v] < H[u] ) swap( v, u );
	
	int dif_h= H[v]- H[u];
	for( int b= 25; b>=0; b-- )	//same level
		if( B[b] <= dif_h ){
			v= Par[b][v];
			dif_h-= B[b];
		}
	
	if( v == u ) cout << v << endl;
	else{
		for( int b= 25; b>=0; b-- )
			if( Par[b][v] != Par[b][u] )
			{ v= Par[b][v];  u= Par[b][u]; }

		if( Par[0][v] != Par[0][u] )		//TODO
			cerr << "error" << endl;
		cout << Par[0][v] << endl;
	}
}

int main(){
	Input();

	B[0]= 1;
	for( int i=1; i<MAX_B; i++ ) B[i]= B[i-1]*2;

	for( int i=1; i<=n; i++ )
		if( !Mark[i] )
			Preprocess( i, 0 );

	for( int i=0; i<nQ; i++ )
		Find_LCA( Quary[i].X, Quary[i].Y );
	return 0;
}
