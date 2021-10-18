#include <iostream>
#include <vector>

using namespace std;

const int MAX = 4950;
vector < pair < int, int > > G[ MAX ];
bool mark[ MAX ];
int dis[ MAX ];
int b[ MAX ];
int n;

void input()
{
	for ( int i = 0, x; i < n; i ++ )
		for ( int j = 0; j < n; j ++ )
		{
			cin >> x;
			if ( x != 0 )
				G[i].push_back( make_pair ( j, x ) );
		}
}

int find( int k, int r )
{
	for ( int i = 0; i < G[k].size(); i++ )
		if ( G[k][i].first == r )
			return i;
	return MAX;
}

void change_matrix()
{
	int p = n;
	for ( int i = 0; i < n; i ++ )
		for ( int j = 0; j < G[i].size(); j ++ )
			if ( G[i][j].second > 1 )
				if ( G[i][j].second == 2 )
				{
					G[p].push_back( make_pair( i, 1 ) );
					G[p].push_back( make_pair( G[i][j].first, 1 ) );
					G[i][j] = make_pair( p, 1);
					G[ G[i][j].first ][ find( G[i][j].first, i ) ] = make_pair( p, 1 );
					p++;
				}
				else
				{
					G[p].push_back( make_pair( i, 1 ) );
					G[p].push_back( make_pair( p+1, 1 ) );
					G[p + 1].push_back( make_pair( p, 1 ) );
					G[p + 1].push_back( make_pair( G[i][j].first, 1) );
					G[i][j] = make_pair( p, 1 );
					G[ G[i][j].first ][ find( G[i][j].first, i ) ] = make_pair( p+1, 1 );
					p += 2;
				}
}

void BFS( int x )
{
	mark [x] = 1;
	int sd = 0;
	int ed = 0;
	dis[x] = 0;
	b[ ed ++ ] = x;
	while ( sd < ed )
	{
		int q = b[ sd ];
		for ( int i = 0; i < G[q].size(); i++ )
			if ( !mark[ G[q][i].first ] )
			{
				mark[ G[q][i].first ] = 1;
				b[ ed ++ ] = G[q][i].first;
				dis[ G[q][i].first ] = dis[q] + 1;
			}
		sd ++;
	}
}

int main()
{
	cin >> n;
	input();
	change_matrix();
	BFS( 0 );
	cout << dis[ n - 1 ] << endl;
}
