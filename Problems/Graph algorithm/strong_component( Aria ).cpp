#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

const int MAX = 1000;
vector < vector < int > > st_com;
vector < int > tp_sort;
vector < int > p;
int G[ MAX ][ MAX ];
bool mark[ MAX ];
string s;
int n;

void input()
{
	getline( cin, s );
	for ( int i = 0, x; i < n; i ++ )
	{
		getline( cin, s );
		stringstream f ( s );
		while ( f >> x )
			G[i][x] = 1;
	}
	
}

void DFS( int x, bool t )
{
	mark[x] = 1;
	for ( int i = 0; i < n; i ++ )
		if ( !mark[i] && ( G[x][i] || t ) && ( G[i][x] || !t ) )
			DFS( i, t );
	if ( !t )
		tp_sort.push_back( x );
	else
		st_com[ st_com.size() - 1].push_back( x );
}

int main()
{
	cin >> n;
	input();
	//create tp_sort:
	for ( int i = 0; i < n; i ++ )
		if ( !mark[ i ] )
			DFS( i, 0 );
	//reverse:
	for ( int i = 0, j = n - 1; i < n / 2; i ++, j -- )
		swap( tp_sort[i], tp_sort[j] );
	//zero:
	for ( int i = 0; i < n ; i ++ )
		mark[i] = 0;
	//find_strong_component:
	for ( int i = 0; i < n; i ++ )
		if ( !mark[ tp_sort[i] ] )
		{
			st_com.push_back( p );
			DFS( tp_sort[i], 1 );
		}
	//sort:
	for ( int i = 0; i < st_com.size(); i++ )
		sort( st_com[i].begin(), st_com[i].end() );

	sort( st_com.begin(), st_com.end() );
	//ouput:
	for ( int i = 0; i < st_com.size(); i++ )
	{
		for ( int j = 0; j < st_com[i].size(); j++ )
			cout << st_com[i][j] << " ";
		cout << endl;
	}
}
