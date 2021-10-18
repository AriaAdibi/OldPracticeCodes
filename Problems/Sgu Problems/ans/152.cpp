#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

vector < double > a;
vector < double > b;
vector < bool > t;

double input ( int n )
{
	double x;
	double sum = 0;
	for( int i = 0; i < n; i ++ )
	{	
		cin >> x;
		a.push_back( x );
		sum += x;
	}
	return sum;
}

int find_dif ( int n, double n_of_votes )
{
	double x;
	for ( int i = 0; i < n; i++ )
	{
		x = (a[i] / n_of_votes);
		b.push_back( x * 100 );
	}
	double sum = 0;
	for ( int i = 0; i < n; i ++ )
		sum += floor( b[i] );
	return 100 - sum;
}

void find_int( int n )
{
	t.resize( n, 0 );
	for ( int i = 0; i < n; i ++ )
		if( b[i] - floor ( b[i] ) == 0 )
			t[i] = 1;
}

void output( int dif, int n )
{
	find_int( n );
	int i = 0;
	int l = 0;
	while ( l < dif )
	{
		if( t[i] == 1 )
			printf( "%.0f ", floor( b[i++] ) );
		else
		{
				printf( "%.0f ", floor( b[i++] + 1) );
				l++;
		}					
	}
	while ( i < n )
		printf( "%.0f ", floor( b[i++] ) );
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	double n_of_votes = input( n );
	int dif = find_dif( n, n_of_votes );
	output( dif, n );
	return 0;
}
