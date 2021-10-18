#include <iostream>
#include <vector> 
#include <cstdio>
#include <algorithm>

using namespace std;

vector < vector < int > > seq;
//q = queries
vector < vector < int > > q;
vector < int > h;
vector < int > t;
const int MAX = 100;
int a[ MAX ][ MAX ];
int mid, f;

void input ( int n, int m )
{
	int x;
	int p;
	for ( int i = 0; i < n; i ++ )
	{
		seq.push_back( h );
		cin >> x;
		for ( int j = 0; j < x; j ++ )
		{
			cin >> p;
			seq[i].push_back( p );
		}
	}
	for ( int i = 0; i < m; i ++ )
	{
		q.push_back( h );
		cin >> x;
		for ( int j = 0; j < x; j++ )
		{
			cin >> p;
			q[i].push_back( p );
		}
	}
}

bool binary_search( int r, int s, int e, int flag )
{
	mid = (( e - s ) / 2) + s;
	if ( e - s + 1 > 0 )
	{
		if ( r < 0 )
		{
			f = r - ( 2 * r );
			if ( f == h[mid] )
				return 0;
			if ( f < h[mid] )
				return binary_search( r, s, mid - 1, 0 );
			if ( f > h[mid] )
				return binary_search( r, mid + 1, e, 0 );
		}
		else
		{
			if ( r == h[mid] )
				return 1;
			if ( r < h[mid] )
				return binary_search( r, s, mid - 1, 1 );
			if ( r > h[mid] )
				return binary_search( r, mid + 1, e, 1 );
		}
	}
	else
	{
		if ( flag == 0 )
			return 1;
		else
			return 0;
	}

}

void checker( int p, int k )
{
	int l = q[p].size();
	bool flag = 0;
	int len;
	for ( int i = 0; i < l; i ++ )
	{
		len = h.size() - 1;
		if ( binary_search( q[p][i], 0, len, 0 ) == 0 )
		{
			flag = 1;
			break;
		}
	}
	if ( flag == 0 )
		a[p][k] = 1;
}

void search_seq( int p )
{
	int l = seq.size();
	for ( int i = 0; i < l; i++ )
	{
		h.clear();
		for ( int j = 0; j < seq[i].size(); j++ )
			h.push_back( seq[i][j] );
		sort ( h.begin(), h.end() );
		checker( p, i );
	}

}

void query()
{
	int l = q.size();
	for ( int i = 0; i < l; i ++ )
		search_seq( i );
}

void output( int n, int m )
{
	int l;
	int ans = 0;
	cout << endl;
	for ( int i = 0; i < m; i ++ )
	{
		t.clear();
		ans = 0;
		for ( int j = 0; j < n; j ++ )
		{
			if ( a[i][j] == 1 )
			{
				ans ++;
				t.push_back ( j );
			}
		}
		cout << ans << endl;
		for ( int j = 0; j < t.size(); j++ )
		{
			l = seq[ t[j] ].size();
			cout << l << " ";
			for ( int k = 0; k < l; k ++ )
				cout << seq[ t[j] ][k] << " ";
			cout << endl;
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	input ( n, m );
	query();
	output( n, m );
}
