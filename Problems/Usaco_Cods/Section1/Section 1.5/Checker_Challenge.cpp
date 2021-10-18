/*
ID: aria.a11
PROG: checker
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin ( "checker.in" );
ofstream fout ( "checker.out" );

typedef pair< int, int > pii;
#define X first
#define Y second

int n;
const int MAX_N= 15;
int pl_checkers[ MAX_N ];
bool mark[ MAX_N ][ MAX_N ];
int num_av_ith[ MAX_N ];
int num_ans= 0;
int tmp_num_ans= 0, jth_num_ans= 0;
bool flag;  vector<pii> changed;

#define show( X ) cerr << #X << "= " << X << " "

void input(){
	fin >> n;
}

void Out_put(){
	for( int i=1; i<=n; i++ ){
		fout << pl_checkers[i];
		if( i< n ) fout << " ";
	}
	fout << endl;
}

void mark_threated_pl( const int &x, const int &y ){		//in loop below dont need if condition we have 0 and n+1
	for( int i=x+1; i<=n; i++ ){				//go down
		if( !mark[i][y] ){
			changed.push_back( pii(i,y) );
			mark[i][y]= 1;
			num_av_ith[i]--;
		}
	}
	for( int i=x+1, j=y+1; i<=n && j<=n; i++, j++ ){	//go diagonally right
		if( !mark[i][j] ){
			changed.push_back( pii(i,j) );
			mark[i][j]= 1;
			num_av_ith[i]--;
		}
	}
	for( int i=x+1, j=y-1; i<=n && j>=1; i++, j-- ){	//go diagonally left
		if( !mark[i][j] ){
			changed.push_back( pii(i,j) );
			mark[i][j]= 1;
			num_av_ith[i]--;
		}
	}
}

void DFS_Solution( const int &x, const int &y ){
	pl_checkers[x]= y;
	changed.clear();
	mark_threated_pl( x, y );
	vector<pii> tmp_changed= changed;

	if( x==n ){
		tmp_num_ans++;	jth_num_ans++;
		if( tmp_num_ans <= 3 ){
			Out_put();
		}
	}
	else{
		flag= 1;
		if( x> 6 ){					//check that we have choise in next rows
			for( int i=x+1; i<=n; i++ ){
				if( num_av_ith[i] == 0 )
				{ flag= 0; break; }
			}
		}
		if( x <= 6 || flag ){
			for( int j=1; j<=n; j++ ){
				if( !mark[x+1][j] ){
					DFS_Solution( x+1, j );
				}
			}
		}
	}

	for( int i=0; i<(int)tmp_changed.size(); i++ ){
		num_av_ith[ tmp_changed[i].X ]++;
		mark[ tmp_changed[i].X ][ tmp_changed[i].Y ]= 0;	
	}
}

int main(){
	input();
	fill( num_av_ith, num_av_ith+MAX_N, n );
	num_av_ith[1]= n-1;

	for( int j=1; j<=(n/2); j++ ){
		DFS_Solution( 1, j );
		num_ans+= (jth_num_ans*2);
		jth_num_ans= 0;
	}
	if( n%2 ){
		int j=(n+1)/2;
		DFS_Solution( 1, j );
		num_ans+= ( jth_num_ans );
		jth_num_ans= 0;
	}
	int j= (n%2)? (n+1/2)+1: (n/2)+1;
	for( ;j<=n; j++ ){
		if( tmp_num_ans<= 3 ){
			DFS_Solution( 1, j );
		}
		else{ break; }
	}
	fout << num_ans << endl;

	return 0;
}
