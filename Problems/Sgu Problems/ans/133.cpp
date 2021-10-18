#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

vector < pair < long long, long long > > a;

void input( int n )
{
	long long x,y;
	for( int i = 0; i < n; i ++ )
	{
		cin >> x >> y;
		a.push_back ( make_pair( x, y ) );
	}
}

int find_redundant_outposts( int n )
{
	sort( a.begin(), a.end() );
	int max = a[0].second;
	int ans = 0;
	for( int i = 1; i < n; i ++ )
	{
		if( a[i].second > max )
			max = a[i].second;
		else
			ans++;
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	input( n );
	cout << find_redundant_outposts( n ) << endl;
}
