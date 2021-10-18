#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 50 + 1;

int n, m;
int a[maxN][maxN];
int d[maxN][maxN][maxN][maxN];

int dyn (int x1, int y1, int x2, int y2, int dir) {
	if (d[x1][y1][x2][y2] != -1)
		return d[x1][y1][x2][y2];

	int ans = 0, temp = 0;
	if (dir == 0) 
		for (int i = x1; i >= x2; i--)
			temp += a[i][y1],
			     ans = max (ans, temp + (y1 < y2 ? dyn(i, y1 + 1, x1, y2, 1): 0));
	if (dir == 1) 
		for (int i = y1; i <= y2; i++)
			temp += a[x1][i],
			     ans = max (ans, temp + (x1 < x2 ? dyn(x1 + 1, i, x2, y1, 2): 0));
	if (dir == 2) 
		for (int i = x1; i <= x2; i++)
			temp += a[i][y1],
			     ans = max (ans, temp + (y2 < y1 ? dyn(i, y1 - 1, x1, y2, 3): 0));
	if (dir == 3) 
		for (int i = y1; i >= y2; i--)
			temp += a[x1][i],
			     ans = max (ans, temp + (x2 < x1 ? dyn(x1 - 1, i, x2, y1, 0): 0));


	return d[x1][y1][x2][y2] = ans;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j= 0; j < m; j++)
			cin >> a[i][j];

	memset (d, -1, sizeof d);

	int best = 0;
	for (int i = 0; i < n; i++)
		best = max (best, dyn (i,     0, n - 1, m - 1, 1)),
		     best = max (best, dyn (i, m - 1,     0,     0, 3));
	for (int i = 0; i < m; i++)
		best = max (best, dyn (    0, i, n - 1,     0, 2)),
		     best = max (best, dyn (n - 1, i,     0, m - 1, 0));

	cout << best << endl;

	return 0;
}
