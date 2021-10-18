/*
ID: aria.a11
PROG: clocks
LAll_posNG: C++
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
#include <set>

using namespace std;

ifstream fin ( "clocks.in" );
ofstream fout ( "clocks.out" );

string Original_input;
string Goal= "999999999";
deque< string > All_pos;
vector< string > pos_ans;

#define show( X ) cerr << #X << "= " << X << " "

void input(){
	for( int i=0, x; i<9; i++ ){
		fin >> x;
		Original_input+= ( '0'+( x-3 ) );
	}
}

void find_every_pos_situations(){
	deque< string > que;
	// que[0] is empty
	int limit= 1<<18; //4^9
	que.push_back( string(0, 0) );
	for( int i=1; i<=limit; i+=3 ){
		for( int i=0; i<4; i++ ){
			que.push_back( que[0]+ string(1, '0'+i) );
		}
		que.pop_front();
	}
	int Size= (int)que.size();
	for( int i=Size-1; i>=Size-limit; i-- ){
		All_pos.push_back( que[i] );
	}
}

bool checker( string &S ){
	string result= Original_input;
	for( int i=0; i<(int)S.size(); i++ ){
		int inx= S[i]- 'A';
		if( result[ inx ] < '9' )
			result[ inx ]+= 3;
		else if( result[ inx ] == '9' )
			result[ inx ]= '0';
	}
	if( result == Goal ) return 1;
	return 0;
}

void find_pos_ans(){
	string Moves[ 10 ];
	Moves[0]= "ABDE"; Moves[1]= "ABC"; Moves[2]= "BCEF";
	Moves[3]= "ADG"; Moves[4]= "BDEFH"; Moves[5]= "CFI";
	Moves[6]= "DEGH"; Moves[7]= "GHI"; Moves[8]= "EFHI";
	int limit= 1<<18; //4^ 9
	for( int i=0; i<limit; i++ ){
		string std_one;
		for( int j=0; j<9; j++ ){
			for( int k=0; k<(int)(All_pos[0][j]-'0'); k++ ){
				std_one+= Moves[j];
			}
		}
		if( checker( std_one ) ){
			pos_ans.push_back( All_pos[0] );
		}
		All_pos.pop_front();
	}
}

bool cmp( const string &x, const string &y ){
	if( x.size() == y.size() )
		return (x < y);
	else{
		if( x.size() < y.size() ) return 1;
		else return 0;
	}
}

void find_ans(){
	for( int i=0; i<(int)pos_ans.size(); i++ ){
		string std_one;
		for( int j=0; j<9; j++ ){
			for( int k=0; k<(int)( pos_ans[i][j]- '0' ); k++ ){
				std_one+= string(1, (char)(j) );
			}
		}
		pos_ans[i]= std_one;
	}
	sort( pos_ans.begin(), pos_ans.end(), cmp );
	for( int i=0; i<(int)pos_ans[0].size(); i++ ){
		fout << pos_ans[0][i]+1;
		if( i< (int)pos_ans[0].size()- 1 ) fout << " ";
	}
	fout << endl;
}

int main(){
	input();
	find_every_pos_situations();
	find_pos_ans();
	find_ans();
	return 0;
}
