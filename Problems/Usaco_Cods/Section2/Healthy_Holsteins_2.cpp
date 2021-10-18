/*
ID: aria.a11
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

ifstream fin ( "holstein.in" );
ofstream fout ( "holstein.out" );

int V, F;
vector<int> req;
const int MAX_F= 17;
vector<int> feed[ MAX_F ];

const int inf= 1e9;
int min_nj= inf, min_fj= -1;
bool tmp_ans[ MAX_F ];

void input(){
	fin >> V;
	for( int i=0, x; i<V; i++ ){
		fin >> x;
		req.push_back( x );
	}
	fin >> F;
	for( int i=0; i<F; i++ ){
		for( int j=0, x; j<V; j++ ){
			fin >> x;
			feed[i].push_back( x );
		}
	}
}

void find_tmp_ans( const int &cont ){
	memset( tmp_ans, 0, sizeof tmp_ans );
	for( int j=0; j<F; j++ ){
		if( cont & (1<<j) ){
			tmp_ans[j]= 1;	
		}
	}
}

void find_min_nScoop(){
	int limit= 1<<F;
	vector<int> tmp; 
	tmp.resize( 30, 0 );
	
	for( int cont= 1; cont < limit; cont++ ){

		int nj= 0; int fj= -1; bool is_fj_filled= 0;
		for( int i=0; i<V; i++ ) tmp[i]= 0;
		
		//check for all j
		for( int j=0; j<F; j++ ){
			if( cont & (1<<j) ){
				if( !is_fj_filled )
				{ fj= j; is_fj_filled= 1; }
				nj++;
				for( int k=0; k<V; k++ ){
					tmp[k]+= feed[j][k];
				}
			}
		}

		//checker
		bool is_satisfy= 1;
		for( int j=0; j<V; j++ ){
			if( tmp[j] < req[j] )
			{ is_satisfy= 0; break; }
		}
		if( is_satisfy ){
			if( min_nj > nj ){
				min_nj= nj;
				find_tmp_ans( cont );
			}
			else if ( min_nj==nj && fj < min_fj ){
				min_fj= fj;
				find_tmp_ans( cont );
			}
		}
	}
}

void Out_put(){
	fout << min_nj;
	for( int i=0; i<F; i++ ){
		if( tmp_ans[i] == 1 ){
			fout << " " << i+1;
		}
	}
	fout << endl;
}

int main(){
	input();
	find_min_nScoop();
	Out_put();
	return 0;
}
