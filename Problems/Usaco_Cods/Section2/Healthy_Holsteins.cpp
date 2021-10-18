/*
ID: aria.a11
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin ( "holstein.in" );
ofstream fout ( "holstein.out" );

typedef pair< int, vector<int> > piv;
#define X first
#define Y second

int V, G;
const int MAX_G= 17;
vector<int> min_vit;
vector<int> feed[ MAX_G ];

const int inf= 1e9;
vector< piv > tmp;
vector< piv > ith_level;

bool checked[ (1<<17) ];

void input(){
	fin >> V;
	for( int i=0, x; i<V; i++ ){
		fin >> x;
		min_vit.push_back( x );
	}
	fin >> G;
	for( int i=0; i<G; i++ ){
		for( int j=0, x; j<V; j++ ){
			fin >> x;
			feed[i].push_back( x );
		}
	}
}

void Out_put( const int &level ,const int &Which ){
	fout << level;

	int cont= ith_level[ Which ].X;
	for( int k=0; k<G; k++ ){
		if( cont & (1<<k) ){
			fout << " " << k+1;
		}
	}
	fout << endl;
}

void determin_next_level(){
	tmp.clear();
	int len= (int)ith_level.size();

	for( int j=0; j<len; j++ ){
		int cont= ith_level[j].X; 				   // cont= contain
		for( int k=0; k<G; k++ ){
			if( !(cont & (1<<k)) && !checked[ cont+(1<<k) ] ){ //dont have this and not check it before
				checked[ cont+(1<<k) ]= 1;
				vector<int> new_Vcont;
				for( int l=0; l<V; l++ )
				{ new_Vcont.push_back( ith_level[j].Y[l]+ feed[k][l] ); }
				tmp.push_back( piv( cont+(1<<k), new_Vcont ) );
			}
		}
	}
	ith_level= tmp;
}

int Checker(){
	int len= (int)ith_level.size();
	for( int i=0; i<len; i++ ){
		bool is_satisfy= 1;
		for( int j=0; j<V; j++ ){
			if( ith_level[i].Y[j] < min_vit[j] )
			{ is_satisfy= 0; break; }
		}
		if( is_satisfy )
		{ return i; }
	}
	return inf;
}

void find_min_nScoop(){
	for( int i=0; i<G; i++ ){					//initialize first level
		ith_level.push_back( make_pair((1<<i), feed[i]) );	//each feed code to 2^i
	}

	int Which= Checker();
	if( Which != inf ){
		Out_put( 1, Which );
	}
	else{
		for( int level= 2; level<=G; level++ ){
			determin_next_level();
			Which= Checker();
			if( Which != inf )
			{ Out_put( level, Which ); break; }
		}
	}
}

int main(){
	input();
	find_min_nScoop();
	return 0;
}
