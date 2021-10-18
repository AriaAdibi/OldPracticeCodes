#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

typedef pair<int, long long> pil;

ifstream fin ( "phoneline.in" );
ofstream fout ( "phoneline.out" );

int n, p, k;
const int inf = 1e+9;
const int MAX = 1e+3+10;
//input
vector<pil> a_l[ MAX ];
//mems
bool mark[ MAX ][ MAX ];
long long d[ MAX ][ MAX ];

#define fr first
#define sc second
#define u a_l[v][i]

void input()
{
	fin >> n >> p >> k;
	long long w;
	for( int i = 0, x, y; i < p; i ++ )
	{
		fin >> x >> y >> w;
		a_l[x-1].push_back( pil(y-1, w) );
		a_l[y-1].push_back( pil(x-1, w) );
	}
}

long long mems( int x, int r );

long long f( int v, int r )
{
	long long h = inf;
	for( int i = 0; i < (int)a_l[v].size(); i++ )
		h = min( h, max(mems(u.fr, r), u.sc) );
	return h;
}

long long g( int v, int r )
{
	long long h = inf;
	for( int i = 0; i < (int)a_l[v].size(); i ++ )
		h = min( h, mems(u.fr, r-1) );
	return h;
}

long long mems( int x, int r )
{
	if( r < 0 )
		return inf;
	if( x == 0 )
		return 0;
	else
		if( mark[x][r] )
			return d[x][r];
		else
		{
			mark[x][r] = 1;
			//g for one of r edge that free is adj to x and f otherwise
			d[x][r] = min( d[x][r], min(f(x,r), g(x,r)) );
			return d[x][r];
		}
}

int main()
{
	input();
	//use dynamic solution to determine ans
	//initial val
	for( int i = 0; i < MAX; i++ )
		fill( d[i], d[i]+MAX, inf );
	fout << mems( n-1, k ) << endl;
	return 0;
}
