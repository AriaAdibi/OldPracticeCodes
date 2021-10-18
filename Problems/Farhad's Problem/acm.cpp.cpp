#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef pair<int, int> pii;

int C, P, D, n;
const int MAX_P = 50;
const int MAX_C = 200;
const int MAX_pen = 200;
//input()
set<int> teams;
vector<pii> sub_ith;
map<int, int> my_map;
//find_first()
vector<pii> p;
//first_dynamic()
int S[ MAX_C ][ MAX_C ];
//second_dynamic()
int d[ MAX_C ][ MAX_P ][ MAX_pen ];

#define fr first
#define sc second

void input()
{
	cin >> C >> P >> D;
	sub_ith.push_back( pii( -1, -1 ) );
	for( int i = 0, j = 1, x, y; i < C; i ++ )
	{
		cin >> x >> y;
		if( teams.find( x ) == teams.end() )
		{
			teams.insert( x );
			my_map[x] = j++;
		}
		sub_ith.push_back( pii(my_map[x], y) );
	}
	n = (int)teams.size();
}

bool f( pii x, pii y )
{
	if( x.fr > y.fr )
		return 1;
	if( y.fr > x.fr )
		return 0;
	if( x.sc <= y.sc )
		return 1;
	if( y.sc < x.sc )
		return 0;
}

pii find_first()
{
	p.resize( n, pii( 0, 0 ) );
	for(int i = 1; i <= C; i ++ )
		p[sub_ith[i].fr-1] = pii( p[sub_ith[i].fr-1].fr+1, p[sub_ith[i].fr-1].sc+sub_ith[i].sc );
	sort( p.begin(), p.end(), f );
	return p[0];
}

void first_dynamic()
{
	for( int i = 1; i <= C; i ++ )
		for( int j = 1; j <= n; j ++ )
		{
			S[j][i] = S[j][i-1];
			if( j == sub_ith[i].fr )
				S[j][i]++;
		}
}

void second_dynamic( pii r )
{
	//initial_val
	d[1][0][0] = 1;
	//update
	for( int i = 1; i <= C; i ++ )
		for( int j = 0; j <= r.fr; j ++ )
			for( int k = 0; k <= MAX_pen; k ++ )
			{
				if( j > S[sub_ith[i].fr][i] )
					d[i+1][j][k] += d[i][j][k]* (j- S[sub_ith[i].fr][i]);
				d[i+1][j+1][k +sub_ith[i].sc+ D] += d[i][j][k]* (r.fr-j); 
			}
}

int main()
{
	input();
	pii r= find_first();
	first_dynamic();
	second_dynamic( r );
	//output()
	int ans = 0;
	for( int i = 1; i <= C; i ++ )
		for( int k = r.sc; k <= MAX_pen; k ++ )
		{
			ans += d[i][r.fr][k];
		}
	cout << ans << endl;
	return 0;
}
