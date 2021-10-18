#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
const int MAX_n = 1e+4 + 10;
const int MAX_e = 1e+4 + 10;
//Graph:
vector < pair < int, int > > a_l[ MAX_n ];
//dynamic
int O = 0;
pair < int, int > d[ MAX_n ];
vector < pair < int, pair < int, int > > > e_dfs;
//DFS:
bool mark[ MAX_n ];
bool parity[ MAX_n ];
set < int > b_e[ MAX_n ];
set < int > kids[ MAX_n ];
pair < int, int > par[ MAX_n ];
//ans
bool t = 0;
vector < int > C;
vector < int > ans;

#define fr first
#define sc second
#define u a_l[v][i]

void input()
{
	cin >> n >> m;
	for( int i = 0, x, y; i < m; i ++ )
	{
		cin >> x >> y;
		a_l[x - 1].push_back( make_pair( y - 1, i ) );
		a_l[y - 1].push_back( make_pair( x - 1, i ) );
	}
}

void DFS ( int v, int p )
{
	bool flag = 0;
	mark[v] = 1;
	parity[v] = p;
	//find odd & even_Backedges( ! ) />:
	int o = 0, e = 0;
	for( int i = 0; i < (int)a_l[v].size(); i ++ )
		if( mark[u.fr] && u.fr != par[v].fr )
		{
			if( parity[v] == parity[u.fr] )
			{
				o++;
				if( !t )
				{
					t = 1;
					int sav = v;
					while( sav != u.fr )
					{
						C.push_back( par[ sav ].sc );
						sav = par[ sav ].fr;
					}
					C.push_back( u.sc );
				}
			}
			else
				e++;
			b_e[v].insert( u.fr );
		}
	O += o;
	//DFS:
	for( int i = 0; i < (int)a_l[v].size(); i ++ )
		if( !mark[u.fr] )
		{
			flag = 1;
			par[ u.fr ] = make_pair( v, u.sc );
			kids[v].insert( u.fr );
			DFS( u.fr, !p );
		}
	//dynamic:
	//initial_value:
	if( !flag )
		d[v] = make_pair( o, e );
	//update:
	else
	{
		d[v] = make_pair( o, e );
		for( set< int >::iterator it = kids[v].begin(); it != kids[v].end(); it ++ )
		{
			d[v].fr += d[*it].fr;
			d[v].sc += d[*it].sc;
		}
		//find_Backedge_/<( ! )
		o = 0, e = 0;
		for( int i = 0; i < (int)a_l[v].size(); i ++ )
			if( u.fr != par[v].fr && kids[v].find( u.fr ) == kids[v].end() && b_e[v].find( u.fr ) == b_e[v].end() )
				if( parity[v] == parity[ u.fr ] )
					o++;
				else
					e++;
		d[v].fr -= o;
		d[v].sc -= e;
	}
	if( v )
		e_dfs.push_back( make_pair( par[v].sc, d[v] ) );
}

int main()
{
	input();
	//DFS + dynamic:
	for( int i = 0; i < n; i ++ )
		if( !mark[ i ] )
		{
			par[i] = make_pair( -1, -1 );
			DFS( i, 0 );
		}
	//find_ans:
	if( O == 0 )
		for( int i = 0; i < m; i ++ )
			ans.push_back( i + 1 );
	else
	{
		if( O == 1 )
			ans.push_back( C[ C.size() - 1 ] + 1);
		for( int i = 0; i < (int)e_dfs.size(); i ++ )
			if( e_dfs[i].sc.fr == O && e_dfs[i].sc.sc == 0 )
				ans.push_back( e_dfs[i].fr + 1 );
	}
	//ouput()
	sort( ans.begin(), ans.end() );
	cout << ans.size() << endl;
	for( int i = 0; i < (int)ans.size(); i ++ )
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
