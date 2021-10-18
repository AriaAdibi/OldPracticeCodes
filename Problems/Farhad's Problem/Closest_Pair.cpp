#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;

int n;
const double inf = 1e+9;
//input()
vector < pii > X;

#define fr first
#define sc second

void input()
{
	cin >> n;
	for( int i = 0, x, y; i < n; i ++ )
	{
		cin >> x >> y;
		X.push_back( pii( x, y ) );
	}
}

double DV ( vector < pii > X )
{
	if( X.size() < 2 )
		return inf;
	sort( X.begin(), X.end() );
	int mid = (X[0].fr+ X[X.size() - 1].fr)/ 2;
	//insert()
	vector < pii > b;
	vector < pii > c;
	int k = 0;
	while( X[k].fr < mid )
		b.push_back( X[k++] );
	//have equal x
	int eq = 0;
	for( int i = k; i <(int)X.size(); i ++ )
		if( X[i].fr == mid )
			eq++;
		else
			break;
	int l = k + (eq + 1)/2;
	for( int i = k; i < l; i ++ )
		b.push_back( X[k++] );

	for( int i = k; i < (int)X.size(); i ++ )
		c.push_back( X[i] );
	//divide
	double f = DV( b );
	double g = DV( c );
	double r = min( f, g );
	//conqure:
	//pick good dots
	vector < pii > box;//(y, x)
	for( int i = k - 1; i > -1; i -- )
		if( mid - X[i].fr <= r )
			box.push_back( pii( X[i].sc, X[i].fr ) );
		else
			break;
	for( int i = k; i < (int)X.size(); i ++ )
		if( X[i].fr - mid <= r )
			box.push_back( pii( X[i].sc, X[i].fr ) );
		else
			break;
	//check each point in good interval
	sort( box.begin(), box.end() );
	for( int i = 0, st = 0, sav = 0; i < box.size(); i ++ )
	{
		while(box[i].fr- box[st].fr > r)
			st++;
		for( int j = i-1; j >= st && j < box.size(); j-- )
			r = min( r, sqrt( pow( abs(box[i].sc- box[j].sc), 2)+ pow( box[i].fr- box[j].fr, 2 ) ) );
	}
	return r;
}

int main()
{
	input();
	//divide and conqure solution:
	cout << fixed << setprecision(4) << DV( X ) << endl;
	return 0;
}
