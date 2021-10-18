#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int n;
//input()
vector<pii> Q;

void input()
{
	cin >> n;
	for( int i = 0, x, y; i < n; i ++ )
	{
		cin >> x >> y;
		Q.push_back( pii(x, y) );
	}
}

void Grahams_Scan();

int main()
{
	input();
	Grahams_Scan();
	return 0;
}
