#include <iostream>
#include <vector>

using namespace std;

typedef pair <int, int> pii;

int n;
const int MAX = 2e+5 + 10;
//input()
int W[ MAX ];
vector< pii > a_l[ MAX ];
//DFS() & BFS()
int par[ MAX ]; //had been updated from input
int que[ MAX ];
bool mark[ MAX ];
//dynamic:
int U[ MAX ]; //MAX path( leaf )
int D[3][ MAX ][2];//MAX1,2,3 path, inx MAX1,2,3 path( first(v is root) -> total )
vector < int > d[ MAX ];

#define fr first
#define sc second
#define u a_l[v][i]

void input()
{
	ios::sync_with_stdio( 0 );
	cin >> n;
	for( int i = 0, x, y, w; i < n-1; i ++ )
	{
		cin >> x >> y >> w;
		a_l[x - 1].push_back( pii(y-1, i ) );
		a_l[y - 1].push_back( pii(x-1, i ) );
		W[i] = w;
	}
}

void update_r( int v, int k, int val )
{
	if( D[0][v][0] < val )
	{
		//update MAX3
		D[2][v][0] = D[1][v][0];
		D[2][v][1] = D[1][v][1];
		//update MAX2
		D[1][v][0] = D[0][v][0];
		D[1][v][1] = D[0][v][1];
		//update MAX3
		D[0][v][1] = k;
		D[0][v][0] = val;
	}
	else
		if( D[1][v][0] < val )
		{
			//update MAX3
			D[2][v][0] = D[1][v][0];
			D[2][v][1] = D[1][v][1];
			//update MAX2
			D[1][v][1] = k;
			D[1][v][0] = val;
		}
		else if( D[2][v][0] < val )
		{
			//update MAX3
			D[2][v][1] = k;
			D[2][v][0] = val;
		}

}

void DFS( int v )
{
	//find_ max path1,2,3 when v is root
	mark[v] = 1;
	for( int i = 0; i < (int)a_l[v].size(); i ++ )
		if( !mark[u.fr] )
		{
			par[u.fr] = v;
			DFS( u.fr );
		}
	//dynamic solution ,, initial value is set:
	for( int i = 0; i < (int)a_l[v].size(); i ++ )
		if( u.fr != par[v] )
		{
			d[v].push_back( D[0][u.fr][0]+ W[u.sc] );
			update_r( v, u.fr, D[0][u.fr][0]+ W[u.sc] );
		}
}

void update_l( int v, pii k )
{
	if( D[0][v][1] != k.fr )
	{
		U[k.fr] = max( U[k.fr], W[k.sc]+ D[0][v][0] );
		U[k.fr] = max( U[k.fr], W[k.sc]+ U[v] );
	}
	else
	{
		if( D[1][v][1] > 0 )
			U[k.fr] = max( U[k.fr], W[k.sc]+ W[D[1][v][1] - 1]+ D[0][ D[1][v][1] ][0] );
		U[k.fr] = max( U[k.fr], W[k.sc]+ U[v] );
	}
}

void BFS()
{
	//find max path when v is leaf
	int st = 0, en = 0, v = 0;
	fill( mark, mark+n, 0 );
	mark[v] = 1;
	que[en++] = v;
	while( st++ < en )
	{
		for( int i = 0; i <(int)a_l[v].size(); i ++ )
			if( !mark[u.fr] )
			{
				mark[u.fr] = 1;
				que[en++] = u.fr;
				update_l( v, u );
			}
		v = que[st];
	}
}

int main() 
{
	input();
	//use DFS & dynamic & BFS to find max_path 
	par[0] = -1;
	DFS( 0 );
	BFS();
	//final_update();
	for( int v = 0; v < n; v ++ )
		update_r( v, par[v], U[v] );
	//ouput()
	int ans = 0;
	for( int v = 0; v < n; v ++ )
		ans = max( ans, D[0][v][0]+ 2*D[1][v][0]+ D[2][v][0] );
	cout << ans << endl;
	return 0;
}
