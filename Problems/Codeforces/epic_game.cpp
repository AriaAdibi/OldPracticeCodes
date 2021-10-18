#include <iostream>

using namespace std;

int a, b, n;
int p, r;

int gcd( int q, int k )
{
	if( !q || !k )
		return k + q;
	else
	{
		if( k == q )
			return k;
		else
		{
			if( k > q )
				return gcd( q, k - q );
			else
				return gcd( q - k, k );
		}
	}
}

bool checker( bool flag )
{
	if( flag )
		p = a;
	else
		p = b;
	r = gcd( p, n );
	n -= r;
	if( n < 0 )
		return 0;
	else
		return 1;
}

int main()
{
	cin >> a >> b >> n;
	bool flag = 1;
	while( checker( flag ) )
		flag = !flag;
	if( !flag )
		cout << 0 << endl;
	else
		cout << 1 << endl;
	return 0;
}
