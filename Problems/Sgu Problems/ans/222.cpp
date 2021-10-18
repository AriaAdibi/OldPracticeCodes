#include <iostream>
#include <cstdio>

using namespace std;

long long p1;
long long p2;

long long C( int n, int k )
{
	if ( k == 0 )
		return  1;
	else
	{
		p1 = C ( n-1, k-1 ) * n / k;
		return p1;
	}
}

long long P( int n, int k )
{
	if( k == 0 )
		return 1;
	else
	{
		p2 = P ( n-1, k-1 ) * n;
		return p2;
	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	// p1 = ?
	if ( k > n )
		p1 = 0;
	else
		p1 = C ( n, k );
	// p2 = ?
	if ( k > n )
		p2 = 0;
	else
		p2 = P ( n, k );
	//ans:
	printf ( "%lld \n" , p1 * p2 );
}
