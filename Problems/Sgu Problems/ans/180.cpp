//what the fuck
#include <iostream>

using namespace std;

const int MAX = 70000;
int a [ MAX ];
int p, k, q;
long long l = 0;
bool flag = 0;

void input( int n )
{
	for ( int i = 0; i < n; i ++ )
		cin >> a[i];
}

void merge_sort( int n, int a[] )
{
	if( n > 1 )
	{
		//use merge to find insertion
		int l1 = (n + 1) / 2;
		int l2 = n / 2;
		int b[ l1 ];
		int c[ l2 ];
		//insert:
		p = 0;
		while ( p < l1 )
			b[p] = a[p++];
		for ( int i = 0; p < n; i ++, p ++ )
			c[i] = a[p];
		////
		merge_sort ( l1, b );
		merge_sort ( l2, c );
		//merge:
		p = 0;
		k = 0;
		q = 0;
		while ( k < l1 && q < l2 )
		{
			if ( c[q] < b[k] )
			{
				a[p++] = c[q++];
				l += ( l1 - k );
			}
			else
				a[p++] = b[k++];
		}
		while( q < l2 )
			a[p++] = c[q++];
		while( k < l1 )
			a[p++] = b[k++];
	}
}

int main()
{
	int n;
	cin >> n;
	input ( n );
	merge_sort( n, a );
	cout << l << endl;
}
