#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

const int MAX = 60;
int dead_pos[ 10 ];
bool allo_jungles[ 10 ];
char G [ MAX ] [ MAX ];
bool mark [ MAX ] [ MAX ];
pair < int, int > moves[ 5 ];
double max_survive = -1e+5;
int n, m;

void input()
{
	for ( int i = 0; i < n; i ++ )
		for ( int j = 0; j < m; j ++ )
			cin >> G[i][j];

	for ( int i = 0; i < 7; i ++ )
		cin >> dead_pos[i];
}

void allowable_jungles( int l )
{
	//zero:
	for ( int i = 0; i < 10; i ++ )
		allo_jungles[i] = 0;
	//find_allowable_jungles:
	int checker = 1;
	for ( int i = 0; checker < l; i++, checker <<= 1 )
		if ( checker & l )
			allo_jungles[ i ] = 1;
}

bool permit( int x, int y )
{
	if ( G[x][y] == '.' )
		return 1;
	if ( G[x][y] == '#' )
		return 0;

	int f = G[x][y] - 'A';
	for ( int i = 0; i < 10; i ++ )
		if ( f == i && allo_jungles[i] == 0 )
			return 0;
	return 1;
}

void DFS( pair < int, int > st, pair < int, int > ed )
{
	mark [ st.first ] [ st.second ] = 1;
	cerr << "SEG ";
	for ( int i = 0; i < 4; i++ )
	{
		int x, y;
		x = st.first + moves[i].first;
		show ( st.first );
		show ( i );
		show ( moves[i].first );
		y = st.second + moves[i].second;
		show ( x );
		show ( y );
		if ( x > -1 && x < m && y > -1 && y < n )
		{	//show( permit( x, y ) );
			if ( !mark[x][y] &&  permit ( x, y ) )
			{
				cerr << "WH@ ";
				DFS( make_pair( x, y ), ed );
			}
		}
	}
}

double pos()
{
	double possibility = 1;
	for ( int i = 0; i < 10; i ++ )
		if ( allo_jungles[i] )
		{
			possibility *= ( 100 - dead_pos[i] );
			possibility /= 100;
		}
	return possibility;
}

void find_min_pos()
{
	int l = 1 << 7;
	//moves:
	moves[0] = make_pair ( 0, 1 );
	moves[1] = make_pair ( 0, -1 );
	moves[2] = make_pair ( 1, 0 );
	moves[3] = make_pair ( -1, 0 );
	//find_strart & end:
	pair < int, int > start, end;
	for ( int i = 0; i < n; i ++ )
		for ( int j = 0; j < m; j ++ )
			if ( G[i][j] == '$' || G[i][j] == '!' )
				if ( G[i][j] == '$' )
					start = make_pair( i, j );
				else
					end = make_pair( i, j );
	//DFS;
	for ( int i = 0; i < l; i++ )
	{
		//zero
		for ( int j = 0; j < n; j ++ )
			for ( int k = 0; k < m; k++ )
				mark[j][k] = 0;

		allowable_jungles( i );
		DFS( start, end );

		double possibility = -1e+6;
		if ( mark [ end.first ] [ end.second ] )
			possibility = pos();
		if ( max_survive < possibility )
			max_survive = possibility;
	}
}

int main()
{
	cin >> n >> m;
	input();

	//find_min_pos();
	partition;
	for ( int i = 0; i < n; i ++ )
	{
		for ( int j = 0; j < m; j ++ )
			cerr << mark[i][j] << " ";
		cerr << endl;
	}
	partition;
	DFS ( make_pair ( 0, 0 ), make_pair( 2, 2 ) );
	if ( max_survive < 0 )
		max_survive = 0;
	cout << fixed << setprecision( 6 ) << max_survive << endl;
}
