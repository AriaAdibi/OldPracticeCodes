#include <iostream>

using namespace std;

long long k, p;

int find_ans( long long n, int l )
{
	p = l + 1;
	k = l + 1;
	for ( int i = 0; i < l ; i ++ )
	{
		k *= 2;
		p += k;
	}
	p += l;
	if( n <= p )
		return l;
	else
		return find_ans( n, l + 1 );
}

int main()
{
	long long n;
	cin >> n;
	if ( n == 1 )
	{
		cout << 0 << endl;
		return 0;
	}
	else
		cout << find_ans( n, 1 ) << endl;
	return 0;
}
