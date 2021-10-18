#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n, e;
const int MAX_N= 1* 1000;
vector<int> Adj_list[ MAX_N ];

string Circuit;
string Extend;
bool Mark_V[ MAX_N ];
int Mark_e[ MAX_N ][ MAX_N ];

void Input(){
	cin >> n >> e;
	for( int i=0, v, u; i<e; i++ ){
		cin >> v >> u;	v--;  u--;

		Mark_e[v][u]++;  Mark_e[u][v]++;
		Adj_list[v].push_back( u );
		Adj_list[u].push_back( v );
	}
}

bool Degree_Condition( bool &Semi ){
	int nOddV= 0;
	for( int i=0; i<n; i++ ) if( Adj_list[i].size() % 2 ) nOddV++;

	if( nOddV == 2 ) Semi= true;
	if( nOddV == 0 || nOddV == 2 ) return 1;
	return 0;
}

void Extend_Trail( const int &v ){
	Mark_V[v]= 1;
	for( int j=0; j<(int)Adj_list[v].size(); j++ ){
		int u= Adj_list[v][j];
		if( Mark_e[v][u] > 0 ){
			Mark_e[v][u]--;
			Mark_e[u][v]--;
			Extend_Trail( u );
		}
	}
	Extend.push_back( v+ '0' );
}

int main(){
	Input();
	bool Semi= false;
	if( Degree_Condition( Semi ) ){
		int v= 0;
		if( Semi )
			for( int i=0; i<n; i++ ) 
				if( Adj_list[i].size() % 2 )
				{  v= i;  break;  }

		Circuit.push_back( char(v+ '0') );
		for( int i=0; i<(int)Circuit.size(); i++ ){
			char w= Circuit[i];
			Extend_Trail( w- '0' );

			Extend.resize( Extend.size()-1 );
			reverse( Extend.begin(), Extend.end() );
			string a( Circuit.begin(), Circuit.begin()+i+1 );
			string b( Circuit.begin()+i+1, Circuit.end() );
			Circuit= a+ Extend+ b;	Extend.clear();
		}

		bool isConnected= true;
		for( int i=0; i<n; i++ ) 
			if( !Mark_V[i] )
			{ isConnected= false; break; }
		if( !isConnected )
			cout << "Your Graph is not Connected." << endl;
		else{
			for( int i=0; i<(int)Circuit.size(); i++ ) Circuit[i]++;
			cout << Circuit << endl;
		}
	}
	else cout << "Your Graph is not eulerian"
		" and not semi_eulerian either." << endl;
	return 0;
}
