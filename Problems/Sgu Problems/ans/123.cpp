/* 123:
   jame k ta adade aval fibonacci chi mishe?
   voroodi 0 < k < 41;*/
#include <iostream>

using namespace std;

int a[10];

long long find_fibonacci( int n )
{
	a[0] = 1;
	a[1] = 1;
	for ( int i = 2; i <= n; i++ )
		a[(i % 3)] = a[(i - 1) % 3] + a[(i - 2) % 3];
	return a[n % 3];
}

int main()
{
	int k;
	cin >> k;
	
	// hast k+2 vali oon 1 base.

	long long f = find_fibonacci( k+1 );
	cout << f-1 << endl;
}
