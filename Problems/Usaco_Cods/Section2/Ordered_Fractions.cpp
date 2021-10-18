/*
ID: aria.a11
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
#define X first
#define Y second

ifstream fin ( "frac1.in" );
ofstream fout ( "frac1.out" );

int n;
vector<pii> B;

void input(){
	fin >> n;
}

bool is_equal( const pii &x, const pii &y ){
	if( x.X*y.Y == y.X*x.Y ) return 1;
	return 0;
}

void find_all_Dval(){
	for( int i=1; i<=n; i++ ){
		for( int j=0; j<=i; j++ ){
			bool is_new= 1;
			for( int k=(int)B.size()-1; k>=0; k-- ){
				if( is_equal( B[k], pii(j,i) ) )
				{ is_new= 0; break; }
			}
			if( is_new ){
				B.push_back( pii(j,i) ); 
			}
		}
	}
}

bool Cmp( const pii &x, const pii &y ){
	return x.X*y.Y < y.X*x.Y;
}

void Out_put(){
	int len= (int)B.size();
	for( int i=0; i<len; i++ ){
		fout << B[i].X << "/" << B[i].Y << endl;
	}
}

int main(){
	input();
	find_all_Dval();
	sort( B.begin(), B.end(), Cmp );
	Out_put();
	return 0;
}
