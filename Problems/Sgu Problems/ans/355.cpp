#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 20000;
int a [ MAX ];
bool t [ MAX ];
bool p [ MAX ];

void zero( bool t[] )
{
	for ( int i = 1; i < MAX; i++ )
	{
		if ( p[i] != 1 )
			t[i] =0;
	}
}

int paint_numbers_likly( int n )
{
	a[1] = 1;
	p[1] = 1;
	int m = 2;
	int l = 1;
	while ( l < n )
	{
		for ( int i = 2; i <= n; i ++ )
		{
			if ( t[i] == 0 )
			{
				l++;
				a[i] = m;
				t[i] = 1;
				p[i] = 1;
				for ( int j = i + i; j <= n; j += i )
				{
					t[j] = 1;
				}
			}
		}
		m ++;
		zero( t );
	}
	return m - 1;
}

void output( int n, int m )
{
	printf ( "%d \n", m );
	for ( int i = 1; i <= n; i++ )
		printf ( "%d ", a[i] );
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	int m = paint_numbers_likly( n );
	output( n, m );
}
