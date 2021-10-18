#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000;
int G[ MAX ] [ MAX ];
vector < int > c;
bool mark [ MAX ];
int parent[ MAX ];
int dis [ MAX ];
int b [ MAX ];
int min_l = MAX;
int n;

void input()
{
	for ( int i = 0; i < n; i ++ )
		for ( int j = 0; j < n; j ++ )
			cin >> G[i][j];
}

void zero()
{
	for ( int i = 0; i < n; i ++ )
	{
		mark[i] = 0;
		parent [i] = 0;
		dis[i] = 0;
		b[i] = 0;
	}
}

void reverse( int st, int ed )
{
	int  m = ( ed - st + 1 )/ 2;
	for ( int i = st, j = ed - 1; i < st + m; i++, j-- ) 
		swap( c[i], c[j] );
}

void create_cycle( pair < int, int > p )
{
	c.clear();
	int x = p.first;
	while ( parent [ x ] != -1 )
	{
		c.push_back( x );
		x = parent [ x ];
	}
	c.push_back( x );
	int st = c.size();

	int y = p.second;
	while ( parent [ y ] != - 1 )
	{
		c.push_back( y );
		y = parent[y];
	}
	reverse( st, c.size() );
}

bool check_for_cycle( int x, int ed )
{
	bool t = 0;
	int minimal_l = MAX;
	pair < int, int > p;
	for ( int i = x; i < ed; i ++ )
		for ( int j = 0; j < n; j ++ )
			if ( mark[j] && G[ b[i] ][j] > 0 && parent [ b[i] ] != j )
			{
				t = 1;
				if ( minimal_l > dis[ b[i] ] + dis[j] + 1 )
				{
					p = make_pair ( b[i], j );
					minimal_l = dis[ b[i] ] + dis[j] + 1;
				}
			}
	if ( minimal_l < min_l )
	{
		min_l = minimal_l;
		create_cycle( p );
	}
	return t;
}

void BFS ( int root )
{
	mark [ root ] = 1;
	int st = 0;
	int ed = 0;
	bool t = 0;
	dis[ root ] = 0;
	b [ ed ++ ] = root;
	parent [ root ] = -1;
	while ( st < ed && !t )
	{
		int q = b[ st ++ ];
		int x = ed;
		for ( int i = 0; i < n; i ++ )
			if ( !mark [ i ] && G[q][i] > 0 )
			{
				mark [i] = 1;
				parent [ i ] = q;
				b[ ed ++ ] = i;
				dis [ i ] = dis [ q ] + 1;
			}
		t = check_for_cycle( x, ed );
	}
}

void output()
{
	if ( min_l == MAX )
		cout << 0 << endl;
	else
	{
		cout << min_l << endl;
		int l = c.size();
		for ( int i = 0; i < l; i ++ )
			cout << c[i] << " ";
		cout << endl;
	}
}

int main()
{
	cin >> n;
	input();
	for ( int i = 0; i < n; i ++ )
	{
		zero ();
		BFS ( i );
	}
	output();
	return 0;
}
