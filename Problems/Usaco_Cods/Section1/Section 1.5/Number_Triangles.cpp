/*
ID: aria.a11
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin ( "numtri.in" );
ofstream fout ( "numtri.out" );

int R;
const int MAX_R= 1010;
const long long inf= 1e14;
vector< long long > rows[ MAX_R ];

void input(){
	fin >> R;
	for( int i=1; i<=R; i++ ){
		rows[i].push_back( -inf );
		long long x;
		for( int j=1; j<=i; j++ ){
			fin >> x;
			rows[i].push_back( x );
		}
	}
}

long long left_above( int x, int y ){
	if( y==1 ) return 0;
	return rows[x-1][y-1];
}

long long rigth_above( int x, int y ){
	if( y==x ) return 0;
	return rows[x-1][y];
}

void dynamic_Solution(){
	//the rows is the input & dynamic array at the same time
	for( int i=2; i<=R; i++ ){
		for( int j=1; j<=i; j++ ){
			rows[i][j]+= max( left_above(i, j), rigth_above(i, j) );
		}
	}
}

void Out_put(){
	long long ans= 0;
	for( int j=1; j<=R; j++ ){
		ans= max( ans, rows[R][j] );
	}
	fout << ans << endl;
}

int main(){
	input();
	dynamic_Solution();
	Out_put();
	return 0;
}
