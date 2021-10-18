/*
ID: aria.a11
PROG: sort3
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin ( "sort3.in" );
ofstream fout ( "sort3.out" );

int n;
vector<int> Oinput;

int min_ex= 0;
int n_ith[ 5 ];
vector< int > pl_ith[ 5 ];
int Ter[ 5 ][2];

void input(){
	fin >> n;
	for( int i=0, x; i<n; i++ ){
		fin >> x;
		Oinput.push_back( x );
	}
}

void find_nith(){
	for( int i=0; i<n; i++ ){
		n_ith[ Oinput[i] ]++;
		pl_ith[ Oinput[i] ].push_back( i );
	}
}

void find_Territorys(){
	int st_yth, en_yth;
	for( int y=1; y<=3; y++ ){
		st_yth= 0, en_yth= n_ith[1]+ n_ith[2]+ n_ith[3]-1;

		for( int i=1; i<y; i++ )
		{ st_yth+= n_ith[i]; }
		for( int i=3; i>y; i-- )
		{ en_yth-= n_ith[i]; }

		Ter[y][0]= st_yth; Ter[y][1]= en_yth;
	}
}

bool is_in_Territory_y( const int &pl, const int &y ){
	if( pl >= Ter[y][0] && pl <= Ter[y][1] ) return 1;
	return 0;
}

void do_max_ij_ex( const int &x, const int &y ){
	int xlen= n_ith[x]; int ylen= n_ith[y];
	int i=0, j=0;
	for( ; i<xlen; i++ ){
		if( is_in_Territory_y( pl_ith[x][i], y ) ){
			for( ; j<ylen; j++ ){
				if( is_in_Territory_y( pl_ith[y][j], x ) ){
					min_ex++;
					swap( Oinput[ pl_ith[x][i] ], Oinput[ pl_ith[y][j] ] );
					swap( pl_ith[x][i], pl_ith[y][j] );
					j++; break;
				}
			}
		}
	}
}

void find_min_exchange(){
	find_nith();
	find_Territorys();
	for( int i=1; i<=3; i++ ){
		for( int j=i+1; j<=3; j++ ){
			do_max_ij_ex( i, j );
		}
	}
	for( int i=0; i<n_ith[1]; i++ ){
		if( Oinput[i] == 2 || Oinput[i] == 3 )
		{ min_ex+= 2; }
	}
}

void Out_put(){
	fout << min_ex << endl;
}

int main(){
	input();
	find_min_exchange();
	Out_put();
	return 0;
}
