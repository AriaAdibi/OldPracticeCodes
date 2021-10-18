/*
ID:aria.a11
PROG: ariprog
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef pair< int, int > pii;
#define X first
#define Y second

ifstream fin ( "ariprog.in" );
ofstream fout ( "ariprog.out" );

int n, m;
vector< int > S;
const int MAX_num_S= 250*250*2+ 260; 
bool exist_S[ MAX_num_S ]; //is_exist_i_in_S
bool checked_d[ MAX_num_S ];
int MAX_NUM;
vector< pii > ans;

void Input(){
	fin >> n >> m;
}

void Create_S(){
	for( int i=0; i<=m; i++ ){
		for( int j=0; j<=m; j++ ){
			S.push_back( (i*i+ j*j) );
		}
	}
	sort( S.begin(), S.end() );
	vector< int > :: iterator it;
	it= unique( S.begin(), S.end() );
	S.resize( it- S.begin() );
	for( int i=0; i<(int)S.size(); i++ ){
		exist_S[ S[i] ]= 1;
	}
	MAX_NUM= S.back();
}

bool checker( const int a, const int d ){
	if( a <= MAX_NUM )
		checked_d[a]= 1;
	if( a <= MAX_NUM && exist_S[a] == 1 ){
		if( checker( a+d, d ) ){
			ans.push_back( pii(a, d) );
			return 1;
		}
		else{
			bool is_pos= true;
			for( int i=0, num= a; i<n; i++, num+= d ){
				if( num > MAX_NUM || !exist_S[num] )
				{ is_pos= false; break; }
			}
			if( is_pos ){
				ans.push_back( pii(a, d) );
				return 1;
			}
		}
	}
	return 0;
}

void Find_all_Ari_Pro_in_S(){
	Create_S();
	int limit_d= 2*m*m/ (n-1);
	for( int d= 1; d <= limit_d; d++ ){
		memset( checked_d, 0, sizeof checked_d );
		int limit_j= (int)S.size()-n<0? (int)S.size()-1: (int)S.size()-n;
		for( int j=0; j<= limit_j; j++ ){ 	/////
			if( !checked_d[ S[j] ] )
				checker( S[j], d );
		}
	}
}

bool cmd( const pii &x, const pii &y ){
	if( x.Y == y.Y ) return x.X < y.X;
	else
		return x.Y < y.Y;
}

void Out_put(){
	if( ans.size() == 0 ){
		fout << "NONE" << endl;
	}
	else{
		sort( ans.begin(), ans.end(), cmd );
		for( int i=0; i<(int)ans.size(); i++ ){
			fout << ans[i].X << " " << ans[i].Y << endl;
		}
	}
}

int main(){
	Input();
	Find_all_Ari_Pro_in_S();
	Out_put();
	return 0;
}
