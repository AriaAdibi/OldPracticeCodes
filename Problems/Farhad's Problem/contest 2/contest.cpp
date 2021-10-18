#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin ( "contest.in" );
ofstream fout ( "contest.out" );

int n, m;
const int MAX = 110;
//input
vector<int> a_l_in[ MAX ];
vector<int> a_l_out[ MAX ];

#define u a_l_out[v][i]
#define w a_l_out[u][j]

void input()
{
	fin >> n >> m;
	for( int i = 0, x, y; i < m; i ++ )
	{
		fin >> x >> y;
		a_l_out[x- 1].push_back( y-1 );
		a_l_in[y- 1].push_back( x-1 );
	}
}

bool find( int x, int y )
{
	for( int i = 0; i < (int)a_l_out[x].size(); i ++ )
		if( a_l_out[x][i] == y )
			return 0;
	return 1;
}

void C_graph()
{
	for( int v = 0; v < n; v ++ )
		for( int i = 0; i < (int)a_l_out[v].size(); i ++ )
			for( int j = 0; j < (int)a_l_out[u].size(); j ++ )
				if( find( v, w ) )
				{
					a_l_out[v].push_back( w );
					a_l_in[w].push_back( v );
				}
}

int main()
{
	input();
	//complete the graph
	C_graph();
	//find_ans
	int ans = 0;
	for( int v = 0; v < n; v ++ )
		if( (int)(a_l_out[v].size()+ a_l_in[v].size()) == n-1 )
			ans++;
	fout << ans << endl;
	return 0;
}
