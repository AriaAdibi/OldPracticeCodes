/*
ID: aria.a11
PROG: pprime
LANG: C++
 */
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin ( "pprime.in" );
ofstream fout ( "pprime.out" );

int a, b;
vector< int > Pos_ans;
vector< int > Primes;

void input(){
	fin >> a >> b;
}

void find_Primes(){
	const int MAX_N= 1e4+ 10;
	bool prime_mark[ MAX_N ]= {false};

	prime_mark[0]= prime_mark[1]= 1;
	for( int i=2; i<MAX_N; i++ ){
		if( !prime_mark[i] ){
			Primes.push_back( i );
			for( int j=i; j<MAX_N; j+=i ){
				prime_mark[j]= 1;
			}
		}
	}
}

int conv_to_int( const vector<int> &fhpal, const vector<int> &shpal ){
	int fhsize= (int)fhpal.size(); int shsize= (int)shpal.size();

	int result= 0; int k=1;
	for( int i=shsize-1; i>-1; i-- )
	{ result+= (k*shpal[i]); k*=10; }
	for( int i=fhsize-1; i>-1; i-- )
	{ result+= (k*fhpal[i]); k*=10; }

	return result;
}

void checker( const int &the_pal ){
	bool is_Prime= 1;
	int i_limit= (int)Primes.size();

	for( int i=0; Primes[i]*Primes[i]<= the_pal && i<i_limit; i++ ){
		if( the_pal % Primes[i] == 0 )
		{ is_Prime= 0; break; }
	}

	if( is_Prime ){
		Pos_ans.push_back( the_pal );
	}
}

void Create_pos_pal_and_check( const int &i, int j ){
	vector< int > fhpal, shpal; //fhpal= first_half_palindrome

	while( j > 0 )
	{ shpal.push_back( j%10 ); j/=10; }
	fhpal= shpal;
	reverse( fhpal.begin(), fhpal.end() );

	if( i%2 ){
		for( int r=0; r<10; r++ ){
			fhpal.push_back( r );
			int the_pal= conv_to_int( fhpal, shpal );
			checker( the_pal );
			fhpal.pop_back();
		}
	}
	else{
		int the_pal= conv_to_int( fhpal, shpal );
		checker( the_pal );
	}
}

int find_num_of_digit( int x ){
	int nD_x= 0;
	while( x>0 )
	{ x/= 10; nD_x++; }
	return nD_x;
}

int POW10( const int &x ){
	int result= 1;
	for( int i=0; i<x; i++ ){
		result*= 10;
	}
	return result;
}

void try_all_pal(){
	int nD_a= find_num_of_digit( a );
	int nD_b= find_num_of_digit( b );

	if( nD_a == 1 ){			
		Pos_ans.push_back( 5 );
		Pos_ans.push_back( 7 );
		nD_a= 2;
	}

	for( int i=nD_a; i<=nD_b; i++ ){
		int first_h= i/2;
		int from= POW10( first_h-1 ); int to= from * 10;
		for( int j= from; j< to; j++ ){
			Create_pos_pal_and_check( i, j );
		}
	}
}

void Out_put(){
	sort( Pos_ans.begin(), Pos_ans.end() );
	for( int i=0; i<(int)Pos_ans.size(); i++ ){
		if( Pos_ans[i] < a || Pos_ans[i] > b ){
			Pos_ans.erase( Pos_ans.begin()+i );
			i--;
		}
	}

	int i_limit= (int)Pos_ans.size();
	for( int i=0; i<i_limit; i++){
		fout << Pos_ans[i] << endl;
	}
}

int main(){
	input();
	find_Primes();
	try_all_pal();
	Out_put();
	return 0;
}
