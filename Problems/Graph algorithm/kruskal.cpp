#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_n = 1000;
const int MAX_e = 100000;
int n, ne;
int W[ MAX_e ];
bool mark[ MAX_n ];
int col[ MAX_n ];
int col_s[ MAX_n ];
vector < int > col_l[ MAX_n ];
pair < int, pair < int, int > > e[ MAX_e ];
vector < int > a_l[ MAX_n ];
vector < pair < int, int > > mst;

#define f first
#define s second
#define v e[i].s.f
#define u e[i].s.s

void input()
{
	cin >> n >> ne;
	char ch;
	for ( int i = 0, x, y, w; i < ne; i ++ )
	{
		cin >> x >> ch >> y >> ch >> w;
		a_l[x].push_back( y );
		a_l[y].push_back( x );
		e[i] = make_pair( w, make_pair( x, y ) );
	}
	//initial value:
	for( int i = 0; i < n; i ++ )
	{
		col[i] = i;
		col_s[i] = 1;
		col_l[i].push_back( i );
	}
}

void DFS( int x )
{
	mark[x] = 1;
	for( unsigned int i = 0; i < a_l[x].size(); i++ )
		if( !mark[ a_l[x][i] ] )
		{
			mark[ a_l[x][i] ] = 1;
			DFS( a_l[x][i] );
		}
}

bool checker()
{
	DFS( 0 );
	for( int i = 0; i < n; i ++ )
		if( !mark[i] )
			return 0;
	return 1;
}

void find_mst()
{
	int R, B;
	long long ans = 0;
	sort( e, e + ne );
	for ( int i = 0; i < ne; i ++ )
		if( col[v] != col[u] )
		{
			mst.push_back( e[i].s );
			ans += e[i].f;
			//combine:
			if( col_s[ col[v] ] > col_s[ col[u] ] )
				swap( v, u );
			R = col[v];
			B = col[u];
			//merge:
			for( int j = 0; j < col_s[R]; j ++ )
			{
				col[ col_l[R][j] ] = B;
				col_l[B].push_back( col_l[R][j] );
			}
			//set size
			col_s[B] += col_s[R];
			col_s[R] = 0;
			col_l[R].clear();
		}
	cout << ans << endl;
}

int main()
{
	input();
	//check for connection
	if( !checker() )
		cout << -1 << endl;
	else
		find_mst();
	return 0;
}
