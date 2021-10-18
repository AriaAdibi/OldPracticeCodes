#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin ( "cowrun.in" );
ofstream fout ( "cowrun.out" );

int n, m;
const int MAX = 1e+4+10;
const int inf = 1e+9;
//input()
vector<int> D_i;
//mems
int d[ MAX ][ MAX ];
bool mark[ MAX ][ MAX ];

void input()
{
	fin >> n >> m;
	D_i.push_back( inf );
	for( int i = 0, x; i < n; i ++ )
	{
		fin >> x;
		D_i.push_back( x );
	}
}

int f( int x, int p )
{
	int sum = 0;
	for( int i = x; i < p; i ++ )
		sum += D_i[i];
	return sum;
}

int mems( int x, int y )
{
	if( x > y )
		return 0;
	else
		if( mark[x][y] )
			return d[x][y];
		else
		{
			mark[x][y] = 1;
			int l = (x+ y)/ 2;
			l = min( l, x+m );
			//i is inx first rest after s_rest is 0:
			for( int i = x; i <= l; i ++ )
				d[x][y] = max( d[x][y], f(x, i)+ mems(x+( (i-x)*2 ), y) );
			return d[x][y];
		}
}

int main()
{
	input();
	//use dynamic solution first min to choose rest
	fout << mems( 1, n+1 ) << endl;
	return 0;
}
