#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int n, e;
int ne = 0;
int nec = 0;
const int MAX = 1e+4 + 10;
const int MAX2 = 8e+5;
bool mark [ MAX ];
bool marke[ MAX2 ];
size_t d[ MAX ];
vector < pair < int, int > > adg_l[ MAX ];
vector < int > ans [ MAX ];

#define f first
#define s second
#define show( x ) cerr << #x << " = " << x << endl;
#define partition cerr << endl << "****************" << endl;

void input()
{
	cin >> n >> e;
	for ( int i = 0, x, y; i < e; i ++ )
	{	
		cin >> x >> y;
		adg_l[x - 1].push_back( make_pair( y - 1, i ) );
		adg_l[y - 1].push_back( make_pair( x - 1, i ) );
	}
}

void DFS( int x )
{
	mark[x] = 1;
	for ( size_t i = 0; i < adg_l[x].size(); i++ )
		if ( !mark[adg_l[x][i].f] )
			DFS(adg_l[x][i].f);
}

void DFSe( int x, int p )
{
	for ( size_t i = d[x]; i < adg_l[x].size(); i++ )
		if ( !marke[ adg_l[x][i].s ] )
		{
			d[x] ++;
			marke[ adg_l[x][i].s ] = 1;
			DFSe( adg_l[x][i].f, p );
		}
	ans[p].push_back( x );
}

void find_ecs()
{
	for ( int i = 0; i < n; i ++ )
	{
		if ( !mark[i] )
		{
			DFS( i );
			DFSe( i, nec++ );
		}
	}
}

int main()
{
	input();
	find_ecs();
	//out_put()
	for ( int i = 0; i < nec; i ++ )
		for ( size_t j = 0; j < ans[i].size() - 1; j ++ )
			printf( "%d %d \n",ans[i][j] + 1, ans[i][j + 1] + 1 );	
}
