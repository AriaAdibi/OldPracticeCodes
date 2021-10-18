/*
ID: aria.a11
PROG: clocks
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

typedef pair< vector<int>, vector<int> > pvv;

ifstream fin( "clocks.in" );
ofstream fout( "clocks.out" );

const int MAX = 27e+4;
//input()
vector< int > G;
map< int, string > mov;
//BFS()
pvv que[ MAX ];
set< vector<int> > mark;
//ans
set< vector<int> > ans;

#define fr first
#define sc second
#define vec que[inx].sc

#define show( x ) cerr << #x << " = " << x << " "
#define partition cerr << endl << "*******************" << endl

void input()
{
	for( int i = 0, x; i < 9; i ++ )
	{
		fin >> x;
		x = (x-3)/ 3;
		G.push_back( x );
	}
	//moves
	mov[0] = "ABDE";
	mov[1] = "ABC";
	mov[2] = "BCEF";
	mov[3] = "ADG";
	mov[4] = "BDEFH";
	mov[5] = "CFI";
	mov[6] = "DEGH";
	mov[7] = "GHI";
	mov[8] = "EFHI";
}

bool checker()
{
	for( int i = 0; i < 9; i ++ )
		if( G[i] != 3 )
			return 0;
	return 1;
}

int BFS()
{
	vector< int > ST = G;
	vector< int > A;
	A.push_back( -1 );
	int st = 0, en = 0;
	mark.insert( ST );
	que[ en++ ] = pvv( ST, A );

	string S;
	while( st < en )
	{
		ST = que[st].fr;
		for( int i = 0; i < 9; i ++ )
		{
			//change
			S = mov[i];
			G = ST;
			for( int j = 0; j < S.size(); j ++ )
				G[ S[j]-'A' ] = (ST[ S[j]-'A' ]+1)%4;
			/*
			//debug
			cerr << "ST = " << endl;
			for( int k = 0; k < ST.size(); k++)
				cerr << ST[k] << " ";
			cerr << endl;
			show( i ) << endl;
			cerr << "G = " << endl;
			for( int k = 0; k < G.size(); k ++ )
				cerr << G[k] << " ";
			partition;
			//check
			if( checker() )
			{
				A = (que[st].sc);
				A.push_back( i );
				sort( A.begin(), A.end() );
				ans.insert( A );
			}
			*/
			//insert
			if( mark.find( G ) == mark.end() )
			{
				mark.insert( G );
				que[en] = pvv( G, que[st].sc );
				(que[ en++ ].sc).push_back( i );
				if( checker() )
					return en-1;
			}
		}
		st++;
	}
}

int main()
{
	input();
	//use BFS to find shortest path:
	if( checker() )
		return 0;
	int inx = BFS();
	vector<int> a;
	while( vec.size() > 1 )
	{
		a.push_back( vec[ vec.size()-1 ]+1 );
		vec.pop_back();
	}
	sort( a.begin(), a.end() );
	for( int i = 0; i < a.size() - 1; i ++ )
		fout << a[i] << " ";
	fout << a[ a.size()-1 ] << endl;
	/*
	set< vector<int> >::iterator it = ans.begin();
	for( int i = 0; i < (*it).size(); i++ )
		cout << (*it)[i]+1 << " ";
	cout << endl;
	*/
	return 0;
}
