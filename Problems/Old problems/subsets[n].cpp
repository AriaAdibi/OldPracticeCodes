#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 1e+5;
int a[ MAX ];
int n;

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
	if ( x == n + 1 )
	{
		if ( start != 0 )
		{
			int l = find_size( a );
			cout << "{ ";
			for ( int i = 0; i < l; i++ )
				printf ( "%d ", a[i] );
			cout << "}" << endl;
		}
	}
	else
	{
		f( start, x + 1 );
		a[ start ] = x;
		f( start + 1, x + 1 );
		zero( start + 1, find_size( a ) );
	}
}

int main()
{
	cin >> n;
	cout << endl << "subsets[n] = " << endl << "{}" << endl;
	f ( 0, 1 );
}
