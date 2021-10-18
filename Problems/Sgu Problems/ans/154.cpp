#include <iostream>

using namespace std;

long long m;
int p, k;

int find_p ( int m )
{
	p = 0;
	int k =5;
	while ( k <= m )
	{
		p += m / k;
		k *= 5;
	}
	return p;
}

int binary_search ( int q, int s, int e )
{
	if ( e > s + 1 )
	{
		m = (s + e) / 2;
		p = find_p( m );
		if ( q == p )
		{
			m -= ( m % 5 );
			return m;
		}
		if ( q < p )
		{
			k = binary_search( q, s, m );
			if ( k == -1 )
				return -1;
			else
				return k;
		}
		if ( q > p )
		{
			k = binary_search( q, m, e );
			if ( k == -1 )
				return -1;
			else
				return k;
		}	
	}
	return -1;
}
/*
int find_ans ( int q )
{
	if ( q <= 3e+7 )
	{
		int l = 0;
		for ( int i = 5; ; i += 5 )
		{
			p = i;
			while ( p % 5 == 0 )
			{
				p /= 5;
				l ++;
			}
			if ( l == q )
				return i;
			if ( l > q )
				return -1;
		}
	}
	if( q > 3e+7 && q <= 6e+7 )
	{
		int l = 3e+7;
		for ( int i = 120000015; ; i += 5 )
		{
			p = i;
			while ( p % 5 == 0 )
			{
				p /= 5;
				l ++;
			}
			if ( l == q )
				return i;
			if ( l > q )
				return -1;
		}
	}
	if ( q > 6e+7 )
	{
		int l = 6e+7;
		for ( int i = 240000025; ;i += 5 )
		{
			p = i;
			while ( p % 5 == 0 )
			{
				p /= 5;
				l ++;
			}
			if ( l == q )
				return i;
			if ( l > q )
				return -1;
		}
	}
}*/

void output( int ans )
{
	if( ans == -1 )
		cout << "No solution" << endl;
	else
		cout << ans << endl;
}

int main()
{
	int q;
	cin >> q;
	if ( q == 0 )
	{
		cout << 1 << endl;
		return 0;
	}
	//int ans2 = find_ans( q );
	//output( ans2 );
	long long s = 0;
	long long e = 1e+10;
	int ans = binary_search ( q, s, e );
	output( ans );
	return 0;
}	
