#include <iostream>
#include <cstdio>

using namespace std;

long long find_distance( long long l, int n )
{
	long long ans = 0;
	//input
	long long x,y;
	for( int i = 0; i < n; i ++ )
	{
		cin >> x >> y;
		ans += x * y * 1e+4;
		ans %= l;
	}

	if( ans <= l/2 )
		return ans;
	else
		return l - ans;
}

void output( long long ans )
{
	double p = ans;
	p += 1e-8;
	p /= 1e+4;
	printf( "%0.4lf \n", p );
}

int main()
{
	double q;
	int n;
	cin >> q >> n;
	q += 1e-8;
	q *= 1e+4;
	long long l = q;

	long long ans = find_distance ( l, n );
	
	output( ans );
}
