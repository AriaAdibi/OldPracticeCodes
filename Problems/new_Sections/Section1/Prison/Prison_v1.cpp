#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> Ppp;
#define X first
#define Y second

int n;
const int MAX_N= 100+ 10;
vector< pii > Adj_list[ MAX_N ][ MAX_N ];
vector< long long > W [ MAX_N ][ MAX_N ];

pii Move[5];

vector< pair<long long, Ppp> > E;
long long W_MST= 0;
pii Par [ MAX_N ][ MAX_N ];
int Rank[ MAX_N ][ MAX_N ];

#define Show(X) cerr << #X << "= " << X << " "

void Set_Moves(){
	Move[0]= pii( 0, -1);  Move[1]= pii( -1, 0);
	Move[2]= pii( 0,  1);  Move[3]= pii(  1, 0);
}

void Input(){
	cin >> n;
	for( int i=1; i<=n; i++ ) //1base
		for( int j=1; j<=n; j++ ){
			pii Cur= pii(i, j);
			long long w;
			for( int k=0; k<4; k++ ){
				cin >> w;
				pii adj= pii( Cur.X+ Move[k].X, Cur.Y+ Move[k].Y );
				if( 1<=adj.X && adj.X<=n && 1<=adj.Y && adj.Y<=n ){
					Adj_list[ Cur.X ][ Cur.Y ].push_back( adj );
					W[ Cur.X ][ Cur.Y ].push_back( w );		
				}
				else if( adj.X == 0 || adj.X == n+1 || adj.Y == 0 || adj.Y == n+1 ){
					Adj_list[ Cur.X ][ Cur.Y ].push_back( pii(0,0) );
					W[ Cur.X ][ Cur.Y ].push_back( w );
					Adj_list[0][0].push_back( Cur );
					W[0][0].push_back( w );
				}
			}
		}
}

void Insert_e( const int &i, const int &j, const int &k ){
	long long w= W[i][j][k];
	pii v= pii(i, j);   pii u= Adj_list[i][j][k];
	E.push_back( pair<long long, Ppp>( w, Ppp(v, u) ) );
}

void Set_edges(){
	for( int i=1; i<=n; i++ )
		for( int j=1; j<=n; j++ ){
			for( int k=0; k<2; k++ )
				Insert_e( i, j, k );
			if( j == n )
				Insert_e( i, j, 2 );
			if( i == n )
				Insert_e( i, j, 3 );
		}
}

pii Find_Par( const pii &v ){
	if( Par[v.X][v.Y] == v )
		return v;
	else return( Par[v.X][v.Y]= Find_Par( Par[v.X][v.Y] ) );
}

void Union( pii &v, pii &u ){
	v= Find_Par( v );   u= Find_Par( u );
	if( Rank[v.X][v.Y] > Rank[u.X][u.Y] )
		Par[u.X][u.Y]= v;
	else if( Rank[u.X][u.Y] > Rank[v.X][v.Y] )
		Par[v.X][v.Y]= u;
	else{
		Par[u.X][u.Y]= v;
		Rank[v.X][v.Y] ++;
	}
}

void Kruskal(){
	Par[0][0]= pii(0,0);
	for( int i=1; i<=n; i++ )
		for( int j=1; j<=n; j++ )
			Par[i][j]= pii(i, j);

	sort( E.begin(), E.end() );

	for( int i=0; i<(int)E.size(); i++ ){
		pii v= E[i].Y.X;   pii u= E[i].Y.Y;   long long w= E[i].X;
		if( Find_Par( v ) != Find_Par( u ) ){
			W_MST+= w;
			Union( v, u );
		}
	}
}

void Out_put(){
	cout << W_MST << endl;
}

int main(){
	Set_Moves();
	Input();
	Set_edges();
	Kruskal();
	Out_put();
	return 0;
}
