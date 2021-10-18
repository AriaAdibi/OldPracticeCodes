#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX = 500;
vector < int > a[ MAX ];
vector < int > ans;


void input ( int n )
{
	int x;
	int p;
	for ( int i = 0; i < n; i ++ )
	{
		scanf ( "%d" , &x );
		for( int j = 0; j < x; j ++ )
		{
			scanf ( "%d", &p );
			a[i].push_back( p );
		}
	}
}

bool is_friends_of_friends( int x, int t )
{
	int l = a[x].size();
	if ( t == x + 1 )
		return 0;

	for ( int i = 0; i < l; i ++ )
		if ( t == a[x][i] ) 
			return 0;
	for ( int i = 0; i < ans.size(); i ++ )
		if ( t == ans[i] )
			return 0;
	return 1;
}

int find_n_of_friends_of_friends( int n, int x )
{
	int l = a[x].size();
	//r = return.
	int r = 0;
	int k = 0;
	for ( int i = 0; i < l; i ++ )
	{
		k = a[x][i] - 1;
		for ( int j = 0; j < a[k].size(); j++ )
			if ( is_friends_of_friends( x, a[k][j] ) )
			{
				r ++;
				ans.push_back( a[k][j] );
			}
	}
	return r;
}

void output( int r )
{
	printf ( "%d \n", r );
	for ( int i = 0; i < r; i ++ )
		printf ( "%d ", ans[i] );
	printf ( " \n" );
}

int main()
{
	int n, x;
	scanf ( "%d %d", &n , &x );
	input ( n );
	int r = find_n_of_friends_of_friends( n, x - 1 );
	sort( ans.begin(), ans.end() );
	output ( r );
}
