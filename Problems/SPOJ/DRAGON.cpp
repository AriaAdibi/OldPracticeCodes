#include <iostream>
#include <vector>

using namespace std;

int n, m, l;
const int MAX = 320;
const int inf = 1e+9;
//tree:
int W[ MAX ];
int CW[ MAX ];
vector < pair < int, int > > a_l[ MAX ];
//DFS:
int par[ MAX ];
bool mark[ MAX ];
//dynamic:
bool t;
pair < int, int > r;
int d[ MAX ][ MAX ][ 2 ];
int c[ MAX ][ MAX ][ 2 ];

typedef pair < int, int > pii;

#define f first
#define s second
#define u a_l[v][i]

void zero()
{
	for( int i = 0; i < n; i ++ )
	{
		a_l[i].clear();
		W[i] = CW[i] = 0;
		mark[i] = 0;
		par[i] = 0;
	}
}

void input()
{
	ios::sync_with_stdio( 0 );
	cin >> n >> m >> l;
	for( int i = 0, x, y, w; i < n - 1; i ++ )
	{
		cin >> x >> y >> w;
		a_l[x - 1].push_back( make_pair( y - 1, i ) );
		a_l[y - 1].push_back( make_pair( x - 1, i ) );
		CW[i] = W[i] = w;
	}
	//make_inf
	for( int i = 0; i < n + 10; i ++ )
		for( int j = 0; j <= l + 10; j ++ )
			for( int k = 0; k < 2; k ++ )
				d[i][j][k] = c[i][j][k] = inf;
}

pii find_ith_kid( int v, int i )
{
	if( u.f != par[v] )
		return u;
	else
	{
		t = 1;
		return a_l[v][i + 1];
	}
}

void update_c( int v, int i )
{
	if( !i )
		return;
	r = find_ith_kid( v, i + t );
	for( int j = 0; j <= l; j ++ )
	{
		//k = 0:
		c[i][j][0] = c[i - 1][j][0] + d[r.f][0][0] + CW[r.s];
		c[i][j][1] = c[i - 1][j][1] + d[r.f][0][0];
		for( int k = 1; k <= j; k ++ )
		{
			c[i][j][0] = min( c[i][j][0], c[i - 1][j - k][0] + min( d[r.f][k][0] + CW[r.s], d[r.f][k - 1][1] ) );
			c[i][j][1] = min( c[i][j][1], c[i - 1][j - k][1] + min( d[r.f][k][0], d[r.f][k - 1][1] + W[ r.s ] ) );
		}
	}
}

void update_d( int v )
{
	//****root does not have parent****
	//r = ith_kid
	t = 0;
	r = find_ith_kid( v, 0 + t );
	//initial_value_c
	c[0][0][0] = d[r.f][0][0] + CW[r.s];
	c[0][0][1] = d[r.f][0][0];
	for( int i = 1; i <= l; i ++ )
	{
		c[0][i][0] = min( d[r.f][i][0] + CW[r.s], d[r.f][i - 1][1] );
		c[0][i][1] = min( d[r.f][i][0], d[r.f][i - 1][1] + W[ r.s ] );
	}
	//update_c:
	for( unsigned int i = 1; i < a_l[v].size() - 1; i ++ )
		update_c( v, i );
	if( !v )
		update_c( v, a_l[v].size() - 1 );
	//update_d:
	for( int i = 0; i <= l; i ++ )
		for( int j = 0; j < 2; j ++ )
			if( !v )
				d[v][i][j] = c[a_l[v].size() - 1][i][j];
			else
				d[v][i][j] = c[a_l[v].size() - 2][i][j];
	//make_inf
	for( unsigned int i = 0; i < a_l[v].size(); i++ )
		for( int j = 0; j <= l; j ++ )
			for( int k = 0; k < 2; k ++ )
				c[i][j][k] = inf;
}

void DFS( int v )
{
	mark[ v ] = 1;
	bool flag = 0;
	for( unsigned int i = 0; i < a_l[v].size(); i ++ )
		if( !mark[ u.f ] )
		{
			flag = 1;
			par[ u.f ] = v;
			DFS( u.f );
		}
	//2 * dynamic_solution:
	//initial_value_d
	if( !flag )
	{
		d[v][0][0] = 0;
		d[v][0][1] = 0;
	}
	else
		update_d( v );
}

int main()
{
	for( int i = 0; i < 10; i ++ )
	{
		input();
		//DFS + 2*dynamic:
		if( l + m - 1 > n )
			cout << -1 << endl;
		else
		{
			//0, 0 does not matter
			if( m > 2 )
				for( int i = 0; i < n - 1; i ++ )
					CW[i] = 0;
			par[0] = -1;
			DFS( 0 );
			cout << d[0][l - 1][1] << endl;
		}
		zero();
	}
	return 0;
}
