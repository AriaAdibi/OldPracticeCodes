/*
ID: aria.a11
PROG: hamming
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin ( "hamming.in" );
ofstream fout ( "hamming.out" );

int N, B, D;

const int MAX_num= (1<<8)+ 10;
bool Selected[ MAX_num ];
vector<int> Avalable;

vector<int> Bad_codes;
vector<int> ans;

void input(){
	fin >> N >> B >> D;
}

void Save_ans(){
	int lim= 1<<B;
	for( int i=0; i<lim; i++ ){
		if( Selected[i] ){
			ans.push_back( i );
		}
	}
}

void delete_bad_codes( const int &x , const int &ind ){
	Bad_codes.clear();
	for( int i=ind+1; i<(int)Avalable.size(); i++ ){
		int H_dif= 0;
		int res= x ^ Avalable[i];
		for( int j=0; j<B; j++ ){
			if( res & (1<<j) ){
				H_dif++;
			}
		}
		if( H_dif < D ){
			Bad_codes.push_back( Avalable[i] );
			Avalable.erase( Avalable.begin()+ i-- );
		}
	}
}

bool DFS( const int &chosen, const int &v, const int &ind ){
	Selected[v]= 1;

	if( chosen == N ){
		Save_ans();
		Selected[v]= 0;
		return 1;
	}

	delete_bad_codes( v, ind );
	vector<int> deleted= Bad_codes;

	bool is_pos= 0;
	for( int i= ind+1; i<(int)Avalable.size(); i++ ){
		int u= Avalable[i];
		is_pos= DFS( chosen+1, u, i );
		if( is_pos ) break;
	}

	Selected[v]= 0;
	for( int i=0; i<(int)deleted.size(); i++ ){
		Avalable.push_back( deleted[i] );
	}

	return is_pos;
}

void find_desire_codeword(){
	int lim= 1<<B;
	for( int i=0; i<lim; i++ )
	{ Avalable.push_back( i ); }

	DFS( 1, 0, 0 );
}

void Out_put(){
	int len= (int)ans.size();
	for( int i=1; i<=len; i++ ){
		fout << ans[i-1];
		if( i%10 == 0 && i< len ){
			fout << endl;
		}
		else if( i<len ) fout << " ";
	}
	fout << endl;
}

int main(){
	input();
	find_desire_codeword();
	Out_put();
	return 0;
}
