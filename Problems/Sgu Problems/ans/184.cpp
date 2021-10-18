#include <iostream>

using namespace std;

int a[ 10 ];
int p1, p2, p3;

int main()
{
	//input:
	for ( int i = 0; i < 6; i ++ )
		cin >> a[i];
	p1 = a[0] / a[3];
	p2 = a[1] / a[4];
	p3 = a[2] / a[5];
	int ans = min( p1, min( p2, p3 ) );
	cout << ans << endl;
}
