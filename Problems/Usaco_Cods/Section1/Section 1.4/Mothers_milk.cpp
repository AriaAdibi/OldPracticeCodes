/*
ID: aria.a11
PROG: milk3
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

ifstream fin ( "milk3.in" );
ofstream fout ( "milk3.out" );

class buckets{			//Keep amount of water in each of them
	public:
		int its_C[ 5 ]; //0=A, 1=B, 2=C;
		buckets(){ memset( its_C, 0, sizeof its_C ); }
		~buckets(){};
};

int Cap[ 5 ]; 			//Capacity_bucket_A to C
bool ans_mark[ 30 ];
vector< int > ans;

void input(){
	fin >> Cap[0] >> Cap[1] >> Cap[2];
}

buckets apply_pour( int x, int y, buckets &v ){
	buckets u;
	for( int i=0; i<3; i++ ){
		if( (i != x) && (i != y) )
			u.its_C[i]= v.its_C[i];
	}
	if( v.its_C[x]+ v.its_C[y] >= Cap[y] ){
		u.its_C[y]= Cap[y];
		u.its_C[x]= v.its_C[x]- (Cap[y]- v.its_C[y]);
	}
	else{
		u.its_C[x]= 0;
		u.its_C[y]= v.its_C[y]+ v.its_C[x];
	}
	return u;
}

void check_for_ans( buckets &u ){
	if( u.its_C[0] == 0 ){
		if( ans_mark[ u.its_C[2] ] == 0 ){
			ans_mark[ u.its_C[2] ]= 1;
			ans.push_back( u.its_C[2] );
		}
	}
}

void BFS_on_num_of_mov(){
	bool checked[30][30][30]= {false};
	vector< buckets > que;

	buckets root;
	root.its_C[0]= root.its_C[1]= 0; root.its_C[2]= Cap[2];
	checked[ root.its_C[0] ][ root.its_C[1] ][ root.its_C[2] ]= true;
	que.push_back( root );
	ans_mark[ Cap[2] ]= true; ans.push_back( Cap[2] );
	
	int st= 0; int en= 1;
	while( st < en ){
		buckets v= que[ st ];
		for( int i=0; i<3; i++ ){
			for( int j=0; j<3; j++ ){
				if( i != j ){
					buckets u= apply_pour( i, j, v );
					if( checked[ u.its_C[0] ][ u.its_C[1] ][ u.its_C[2] ] == 0 ){
						checked[ u.its_C[0] ][ u.its_C[1] ][ u.its_C[2] ]= 1;
						que.push_back( u ); en++;
						check_for_ans( u );
					}
				}
			}
		}
		st++;
	}
}

void Out_put(){
	sort( ans.begin(), ans.end() );
	for( int i=0; i<(int)ans.size(); i++ ){
		fout << ans[i];
		if( i<(int)ans.size()-1 ) fout << " ";
	}
	fout << endl;
}

int main(){
	input();
	BFS_on_num_of_mov();
	Out_put();
	return 0;
}
