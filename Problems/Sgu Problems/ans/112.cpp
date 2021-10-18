/* a^b-b^a =? */
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 250;
int a [MAX];
int b [MAX];
int c [MAX];
int c2 [MAX];
int multiply [MAX];
int c3 [MAX];

void insert ( int a[], int n )
{
	int i = 0; 
	while ( n > 0 )
	{
		a[i++] = n % 10;
		n /= 10;
	}
}

int find_size ( int a[] )
{
	int i = MAX - 1;
	while ( a[i] == 0 && i > -1 )
		i--;
	i++;
	return i;
}

void zero ( int t[], int l )
{
	for(int i = 0; i < l; i++)
		t[i] = 0;
}

void output ( int a[], int l )
{
	for(int i = l-1; i > -1; i-- )
		cout << a[i];
	cout << endl;
}

void trans ( int multiply[], int ans[] )
{
	for(int i = 0; i < MAX; i++ )
	{
		ans [i] = 0;
		ans [i] = multiply[i];
		multiply [i] = 0;
	}
}

void normalize ( int ans[], int l )
{
	for(int i = 0; i < l; i++ )
	{
		while ( ans[i] > 9 )
		{
			ans[i] -= 10;
			ans[i+1]++;
		}
		if( ans[l] > 0 )
			l++;
	}
}

void multiplier( int p[], int p2[], int ans[] )
{
	int l = find_size( p );
	int l2 = find_size( p2 );

	for(int i = 0; i < l; i++)
		for(int j = 0; j < l2; j++)
			multiply[i+j] += p[i] * p2[j];
	
	trans ( multiply, ans );

	normalize( ans, l+l2-1 );
}

void power( int a[], int m, int c[] )
{
	if( m == 0 )
		c[0] = 1;
	else
	{
		if( m % 2 == 0 )
		{
			int t [MAX];
			zero ( t, MAX );
			power( a, m/2, t );
			multiplier( t, t, c );
		}
		else
		{
			int t [MAX];
			zero ( t, MAX );
			power( a, m/2, t );
			multiplier( t, t, c );
			multiplier( a, c, c );
		}
	}
}

bool find_max( int c[], int c2[], int l )
{
	for( int i = l-1; i > -1; i--)
	{
		if( c[i] > c2[i] )
			return 1;
		if( c2[i] > c[i] )
			return 0;
	}
	return 1;
}

void normalize_p ( int c3[] )
{
	int l = find_size( c3 );

	for(int i = 0; i < l; i++)
	{
		while( c3[i] < 0 )
		{
			c3[i] += 10;
			c3[i+1]--;
		}
	}
}

bool MINUS( int c[], int c2[], int c3[] )
{
	int l = find_size( c );
	int l2 = find_size( c2 );

	bool t = 0;

	if( l > l2 )
		t = 1;
	if( l == l2 )
		t = find_max( c, c2, l );

	if( t == 1)
	{
		int l3 = max( l, l2);
		for(int i = 0; i < l3; i++)
			c3[i] = c[i] - c2[i];

		normalize_p( c3 );
		return 1;
	}
	else
	{
		int l3 = max ( l, l2 );
		for(int i = 0; i < l3; i++)
			c3[i] = c2[i] - c[i];

		normalize_p( c3 );
		return 0;
	}
}

int main()
{
	int n,m;
	cin >> n >> m;

	insert ( a, n );
	insert ( b, m );

	power( a, m, c );
	power( b, n, c2 );

	bool t = MINUS ( c, c2, c3 );

	if( t == 0)
		cout << "-"; 

	int l = find_size( c3 );
	output( c3, l );
}
