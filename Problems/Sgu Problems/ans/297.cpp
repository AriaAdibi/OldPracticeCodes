#include <iostream>

using namespace std;

int find_ans ( int n, int m )
{
	int l = 0;
	int x;
	for ( int i = 0, p = 0; i < m; i ++ )
	{
		cin >> x;
		p = x / n;
		l += x - (p * n);
		l %= n;
	}
	return l;
}

int main()
{
	int n, m;
	cin >> n >> m;
	int ans = find_ans( n, m );
	cout << ans << endl;
}
