#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int t, inx, n;
//input()
vector<pii> Q;
//Grahams_Scan
pii p, q;
vector<pii> P;
vector<pii> S;

#define fr first
#define sc second
#define cross(x, y) x.fr*y.sc- y.fr*x.sc
#define two( x ) x*x
#define dis( x ) two(p.fr-x.fr)+ two(p.sc-x.sc)
#define v pii(P[i-1].fr-p.fr, P[i-1].sc-p.sc)
#define u pii(P[i].fr-p.fr, P[i].sc-p.sc)

void input()
{
	Q.clear();
	P.clear();
	S.clear();
	cin >> inx >> n;
	for( int i = 0, x, y; i < n; i ++ )
	{
		cin >> x >> y;
		Q.push_back( pii(x, y) );
	}
}

bool f1( pii x, pii y )
{
	if( x.sc > y.sc )
		return 1;
	else if( x.sc == y.sc && x.fr < y.fr )
		return 1;
	return 0;
}

pii find_topest_point()
{
	vector<pii> R = Q;
	sort( R.begin(), R.end(), f1 );
	return R[0];
}

bool f2( pii x, pii y )
{
	x = pii(x.fr-p.fr, x.sc-p.sc);
	y = pii(y.fr-p.fr, y.sc-p.sc);
	if( cross(x, y) > 0 )
		return 1;
	else if( cross(x, y) == 0 )
		if( dis(x) < dis(y) )
			return 1;
	return 0;
}

void sort_by_polar_angle()
{
	P = Q;
	//erase p;
	for( int i = 0; i < (int)P.size(); i ++ )
		if( P[i] == p )
			P.erase( P.begin()+ i );
	//sort
	sort( P.begin(), P.end(), f2 );
	//remove
	for( int i = 1; i < (int)P.size(); i ++ )
		if( cross( v, u ) == 0 )
			if( dis(u) < dis(v) )
				P.erase( P.begin()+i );
			else
				P.erase( P.begin()+i-1 );
}

bool f3( pii r, pii t, pii i )
{
	q= pii( t.fr-r.fr, t.sc-r.sc );
	i= pii( i.fr-t.fr, i.sc-t.sc );
	if( cross(q, i) > 0 )
		return 0;
	else
		return 1;
}

bool special_situation()
{
	if( P.size() < 3 )
	{
		S.push_back( p );
		for( int i = 0; i <(int)P.size(); i ++ )
			S.push_back( P[i] );
		return 0;
	}
	return 1;
}

void Grahams_Scan()
{
	p= find_topest_point();
	//sorted by polar angle in counterclockwise order around p:
	sort_by_polar_angle();
	if( special_situation() )
	{
		S.push_back( p );
		S.push_back( P[0] );
		S.push_back( P[1] );
		for( int i = 3; i <= (int)P.size(); i ++ )
		{

			while( S.size() > 1 && f3(S[S.size()-2], S[S.size()-1], P[i-1])  )
				S.pop_back();
			S.push_back( P[i-1] );
		}
	}
}

int main()
{
	cin >> t;
	for( int i = 0; i < t; i ++ )
	{
		input();
		Grahams_Scan();
		//ouput()
		cout << inx << " " << S.size() << endl;
		for( int i = S.size()-1; i > -1; i-- )
			cout << S[i].fr << " " << S[i].sc << endl;
	}
	return 0;
}
