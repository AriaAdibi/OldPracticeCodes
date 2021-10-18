#include <iostream>
#include <algorithm>

using namespace std;

int a[3][3];
int b[3];

void input()
{
	for ( int i = 0; i < 3; i ++ )
		for ( int j = 0; j < 3; j ++ )
			cin >> a[i][j];
}

int main()
{
	input();
	for ( int i = 0; i < 3; i ++ )
		sort ( a[i] + 0, a[i] + 3 );
	for ( int i = 0; i < 3; i ++ )
		b[i] = a[i][1];

	sort ( b + 0, b + 3 );

	cout << b[1] << endl;
}
