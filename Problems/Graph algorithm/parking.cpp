#include <iostream>
#include <cstdio>

using namespace std;

int n;
const int MAX = 60;
int p[ MAX ];
int op[ MAX ];
int d[ MAX ][ MAX ][ MAX ];

#define bug( x ) cerr << "Here " << #x << endl;
#define show(x ) cerr << #x << " = " << x << endl;
#define partition cerr << endl << "*************************" << endl;

void input()
{
	cin >> n;
	for ( int i = 0; i < n; i ++ )
	{
		cin >> p[i];
		op[ p[i] ] = i;
	}
	op[n] = MAX;
}

void dynamic_solution()
{
	int b, c, j2, k2;
	//dynamic_programming:
	for ( int i = n - 1; i > - 1; i -- )
		for ( int j = 0; j <= n; j++ )
			for ( int k = 0; k <= n; k++ )
			{
				b = c = 0;
				k2 = k;
				j2 = j;
				if ( op[i] > op[j] )
					b = 1;
				else
					j2 = i;
				if( op[i] > op[k] )
					c = 1;
				else
					k2 = i;
				d[i][j][k] += min( d[i + 1][j2][k] + b, d[ i + 1 ][j][k2] + c );
			}
}

int main()
{
	input();
	dynamic_solution();
	/*
	for ( int i = 0; i < n; i ++ )
	{
		show( i );
		for ( int j = 0; j < n; j ++ )
		{
			cerr << "j = " << j << ": ";
			for ( int k = 0; k < n; k ++ )
				printf( "%d ", d[i][j][k] );
			printf( "\n" );
		}
		partition;
	}
	*/
	cout << d[0][n][n] << endl;
}
