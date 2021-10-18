#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, e;
const int MAX_N= 50* 1000+ 100;
int nBead[ MAX_N ];
vector<int> pAdj_list[ MAX_N ];

bool Mark_Tp[ MAX_N ];
vector<int> Tp;

int late_B[ MAX_N ];
int rem_B[ MAX_N ];

void Input(){
	cin >> n >> e;
	for( int i=1; i<=n; i++ )
		cin >> nBead[i];
	for( int i=1, v, u; i<=e; i++ ){
		cin >> v >> u;
		pAdj_list[v].push_back( u );
	}
}

void Topological_Sort( const int &v ){
	Mark_Tp[v]= 1;
	for( int j=0; j<(int)pAdj_list[v].size(); j++ ){
		int u= pAdj_list[v][j];
		if( !Mark_Tp[u] ){
			Topological_Sort( u );
		}
	}
	Tp.push_back( v );
}

void mySolution(){
	for( int i=1; i<=n; i++ )
		if( !Mark_Tp[i] )
			Topological_Sort( i );
	reverse( Tp.begin(), Tp.end() );

	for( int i=0; i<n; i++ ){
		int v= Tp[i];
		int dplus= (int)pAdj_list[v].size(); 
		int nB= nBead[v]+ late_B[v];

		if( dplus != 0 ){
			rem_B[v]= nB%( dplus );
			for( int j=0; j<(int)pAdj_list[v].size(); j++ ){
				int u= pAdj_list[v][j];
				late_B[u]+= (nB/dplus);
			}
		}
		else rem_B[v]= nB;
	}
}

void Out_put(){
	for( int i=1; i<=n; i++ )
		cout << rem_B[i] << " ";
	cout << endl;
}

int main(){
	Input();
	mySolution();
	Out_put();
	return 0;
}
