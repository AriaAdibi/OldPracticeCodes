#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, t;
const int MAX = 1e+3;
const int MAX_T = 1e+5 + 10;
//input()
int G[ MAX ][ MAX ];
int T[ MAX_T ];
//Backward_solution:
/////h, n_of_column
pair < int, int > H[ MAX ][ MAX ];
///////////pointers
int P[ MAX ];
int prev_P[ MAX ];
//direction
int z[4][2];
bool mark[ MAX ][ MAX ];
//disjoinset:
int rank[ MAX ][ MAX ];
pair < int, int > par[ MAX ][ MAX ];
//ans
int ans_t = 0;
vector < int > ans;

typedef pair< int, int > pii;

#define fr first
#define sc second
#define inx_en P[r]
#define inx_st prev_P[r]
#define PAR( x ) par[x.fr][x.sc]

void input()
{
	ios::sync_with_stdio( 0 );
	cin >> n >> m;
	for( int i = 0; i < n; i ++ )
		for( int j = 0; j < m; j ++ )
		{
			cin >> G[i][j];
			H[i][j] = make_pair( G[i][j], j );
		}
	cin >> t;
	for( int i = 0; i < t; i ++ )
		cin >> T[i];
	//directions
	z[0][0] = z[2][1] = 1;
	z[1][0] = z[3][1] = -1;
}

pii find_par( pii r )
{
	if( PAR( r ) == r )
		return r;
	return PAR( r ) = find_par( PAR( r ) );
}

void merge( pii adj, pii c )
{
	if( find_par( adj ) != find_par( c ) )
	{
		ans_t --;
		if( rank[PAR( adj ).fr][PAR( adj ).sc] < rank[PAR( c ).fr][PAR( c ).sc] )
			swap( adj, c );

		if( rank[PAR( adj ).fr][PAR( adj ).sc ] == rank[PAR( c ).fr][PAR( c ).sc] )
			rank[PAR( adj ).fr][PAR( adj ).sc] ++;

		PAR( PAR( c ) ) = PAR( adj );
		find_par( c );
	}
}

void relaxe_free_highs( int h, int r )
{
	//relaxe_them..[X)
	//find_inx
	while( inx_en < m && H[r][ inx_en ].fr > T[h] )
		inx_en++;
	//merge:
	pii c, adj;
	while( inx_st < inx_en )
	{
		ans_t ++;
		mark[r][ H[r][inx_st].sc ] = 1;
		c = make_pair( r, H[r][inx_st].sc );
		for( int j = 0; j < 4; j ++ )
		{
			adj = make_pair( c.fr + z[j][0], c.sc + z[j][1] );
			if( (adj.fr > -1 && adj.fr < n) && (adj.sc > -1 && adj.sc < m) )
				if( mark[ adj.fr ][ adj.sc ] )
					merge( adj, c );
		}
		inx_st++;
	}
}

void Backward_solution()
{
	//sort in decreasing order:
	for ( int i = 0; i < n; i ++ )
	{
		sort( H[i], H[i] + m );
		reverse( H[i], H[i] + m );
	}
	sort( T, T + t );
	reverse( T, T + t );
	//initial_value_of_disjoin set:
	for( int i = 0; i < n; i ++ )
		for( int j = 0; j < m; j ++ )
			par[i][j] = make_pair( i, j );
	//relaxe the next lower high:
	for( int i = 0; i < t; i ++ )
	{
		for( int j = 0; j < n; j ++ )
			relaxe_free_highs( i, j );
		ans.push_back( ans_t );
	}
}

int main()
{
	input();
	//Backward & disjoin set solution:
	Backward_solution();
	//output();
	reverse( ans.begin(), ans.end() );
	for( int i = 0; i < ans.size(); i++ )
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
