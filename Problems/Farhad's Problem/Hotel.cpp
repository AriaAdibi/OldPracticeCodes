#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef pair < int, int > pii;

int n, m, h;
const int inf = 1e+9;
const int MAX = 1e+6;
//input();
int W[ MAX ];
set < int > H;
vector < pii > a_l[ MAX ];
//create_graph:
vector < int > H_l[ MAX ];
//Dijkstra:
set < pii > S;
int dis[ MAX ];//use in BFS too
//BFS:
bool mark[ MAX ];

#define fr first
#define sc second
#define u a_l[v][i]
#define adj H_l[*v][i]

#define show( x ) cerr << #x << " = " << x << endl
#define partition cerr << endl << "******************" << endl

void input()
{
	ios::sync_with_stdio( 0 );
	cin >> n >> h;
	//Hotels
	for( int i = 0, x; i < h; i ++ )
	{
		cin >> x;
		H.insert( x - 1 );
	}
	H.insert( 0 );
	H.insert( n - 1 );
	//roads:
	cin >> m;
	for( int i = 0, x, y, w; i < m; i ++ )
	{
		cin >> x >> y >> w;
		a_l[x - 1].push_back( pii( y-1, i ) );
		a_l[y - 1].push_back( pii( x-1, i ) );
		W[i] = w;
	}

}

void Dijkstra( int st )
{
	fill ( dis, dis+n, inf );
	dis[ st ] = 0;
	//initail value of V-S;
	for( int i = 0; i < n; i ++ )
		S.insert( pii( dis[i], i ) );
	int D, v;
	while( !S.empty() )
	{
		D = S.begin() -> fr, v = S.begin() -> sc;
		S.erase( S.begin() );
		if ( D == inf )
			return;
		for( int i = 0; i < (int)a_l[v].size(); i ++ )
			if( D + W[ u.sc ] < dis[ u.fr ] )
			{
				S.erase( pii( dis[u.fr], u.fr ) );
				dis[ u.fr ] = D + W[u.sc];
				S.insert( pii( dis[u.fr], u.fr ) );
			}
	}
}

void add_edges( int v )
{
	for( set<int>::iterator it = H.begin(); it != H.end(); it ++ )
		if( *it != v && dis[ *it ] <= 600 )
			H_l[v].push_back( *it );
}

void BFS()
{
	int st = 0, en = 0;
	int que[ MAX ];
	fill( dis, dis+n, inf );
	//initial value
	mark[ 0 ] = 1;
	que[ en++ ] = 0;
	dis[0] = 0;
	set< int >::iterator v = H.begin();
	while( st++ < en )
	{
		for( int i = 0; i < (int)H_l[*v].size(); i ++ )
			if( !mark[ adj ] )
			{
				mark[ adj ] = 1;
				que[en++] = adj;
				dis[ adj ] = dis[ *v ] + 1;
			}
		v++;
	}
}

int main()
{
	input();
	//use Dijkstra to find dis between Hotells & create new graph:
	for( set<int>::iterator it = H.begin(); it != H.end(); it ++ )
	{
		Dijkstra( *it );
		add_edges( *it );
	}
	//use BFS to find min days for reach to n-1 in new graph:
	BFS();
	//output
	if( dis[n -1] == inf )
		cout << -1 << endl;
	else
		cout << dis[n - 1] - 1 << endl;
	return 0;
}
