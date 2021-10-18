/*
ID: aria.a11
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin ( "sprime.in" );
ofstream fout ( "sprime.out" );

int N;
int fth_sprimes[]= { 2, 3, 5, 7 };
vector< int > ith_sprimes( fth_sprimes, fth_sprimes+4 );

void input(){
	fin >> N;
}

bool is_prime( int x ){
	bool is_prime= 1;
	for( int i=2; i*i<=x; i++ ){
		if( x%i == 0 )
		{ is_prime= 0; break; }
	}
	return is_prime;
}

void find_ith_sprimes( int x ){
	if( x==1 ) return;
	else{
		find_ith_sprimes( x-1 );
		vector< int > tmp;
		for( int i=0; i<(int)ith_sprimes.size(); i++ ){
			for( int j=1; j<=9; j+=2 ){
				int pos_sprime= ith_sprimes[i]*10+ j;
				if( is_prime( pos_sprime ) ){
					tmp.push_back( pos_sprime );
				}
			}
		}
		ith_sprimes= tmp;
	}
}

void Out_put(){
	for( int i=0; i<(int)ith_sprimes.size(); i++ ){
		fout << ith_sprimes[i] << endl;
	}
}

int main(){
	input();
	find_ith_sprimes( N );
	Out_put();
	return 0;
}
