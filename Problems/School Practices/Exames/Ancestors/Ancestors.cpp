#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, root, k;
const int MAX_N= 5e5+ 100;
vector<int> Adj_list[ MAX_N ];

int Que[ MAX_N ];
bool Mark[ MAX_N ];
long long Sum[ MAX_N ];
int bPar[ 30 ][ MAX_N ];

int b[ 30 ];

void Input(){
	scanf( "%d %d %d", &n, &root, &k );	//1base
	for( int i=1; i<=n-1; i++ ){
		int v, u;
		scanf( "%d %d", &v, &u );
		Adj_list[v].push_back( u );
		Adj_list[u].push_back( v );
	}
}

void Dynamic_BFS_Solution(){
	Mark[root] = 1; Que[ 1 ]= root; Sum[root]= root;
	for( int i=0; i<25; i++ ) bPar[i][root]= root;

	int s= 1, f= 2;
	while( f > s ){
		int v= Que[s];
		for( int j=0; j<(int)Adj_list[v].size(); j++ ){
			int u= Adj_list[v][j];
			if( !Mark[ u ] ){
				Mark[u]= 1;
				Que[f++]= u;
				Sum[u]= Sum[v]+ u;
				bPar[0][u]= v;
				for( int i=1; i<25; i++ ){
					bPar[i][u]= bPar[i-1][ bPar[i-1][u] ];
				}
			}
		}
		s++;
	}
}

void Find_ans(){
	b[0]= 1;
	for( int i=1; i<25; i++ ) b[i]= 2*b[i-1];

	for( int v=1; v<=n; v++ ){
		int sav_k= k; int u=v;
		for( int i=24; i>=0; i-- ){
			if( b[i] <= k ){
				k-=b[i];
				u= bPar[i][u];
			}
		}
		cout << Sum[u] << endl;
		k= sav_k;
	}
}

int main(){
	Input();
	Dynamic_BFS_Solution();
	Find_ans();
	return 0;
}
