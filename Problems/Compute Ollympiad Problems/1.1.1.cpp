#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1e+5;
int a[ MAX ];
int n, m;

int find_size( int a[] )
{
	int l = MAX - 1;
	while ( a[l] == 0 )
		l --;
	return l + 1;
}

void zero ( int start, int l ) 
{
	for ( int i = start; i < l; i ++ )
		a[i] = 0;
}

void f ( int start, int x )
{
	if ( x == n + 1 && start > m - 1 && start < m + 1 )
	{
		int l = find_size( a );
		cout << "{ ";
		for ( int i = 0; i < l; i++ )
			printf ( "%d ", a[i] );
		cout << "}" << endl;
	}
	if ( x < n + 1 )
	{
		f( start, x + 1 );
		a[ start ] = x;
		f( start + 1, x + 1 );
		zero( start + 1, find_size( a ) );
	}
}

int main()
{
	cin >> n >> m;
	cout << endl << "subsets[n] = " << endl;
	if( m == 0 )
		cout << "{ }" << endl;
	else
		if ( m > n ) 
			cout << "No solution" << endl;
		else
			f ( 0, 1 );
}
