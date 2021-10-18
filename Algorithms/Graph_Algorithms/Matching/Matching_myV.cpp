#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int X_size, Y_size, nEdge;
const int MAX_N= 100* 1000;
vector<int> Adj_list[ MAX_N ];

int Mate[ MAX_N ];
int match_size= 0;
bool Mark_FAugPath[ MAX_N ];

void Input(){
	cin >> X_size >> Y_size >> nEdge;	
	for( int i=0, x, y; i<nEdge; i++ ){
		cin >> x >> y;	x--; y--;
		Adj_list[x].push_back( y );
		Adj_list[y].push_back( x );
	}
}

bool Find_AugPath( const int &x ){
	Mark_FAugPath[x]= 1;

	for( int j=0; j<(int)Adj_list[x].size(); j++ ){
		int y= Adj_list[x][j];
		if( Mate[y] == -1 )
		{ Mate[x]= y; Mate[y]= x; return true; }
	}

	for( int j=0; j<(int)Adj_list[x].size(); j++ ){
		int y= Adj_list[x][j];
		if( !Mark_FAugPath[ Mate[y] ] && Find_AugPath( Mate[y] ) ) 		//Mate[u]!= -1
		{ Mate[x]= y; Mate[y]= x; return true; }
	}

	return false;
}

void Find_Maximum_Matching(){
	memset( Mate, -1, sizeof Mate );
	for( int v=0; v<X_size+Y_size; v++ )
		if( Mate[v]==-1 && Find_AugPath( v ) ){
			match_size++;
			memset( Mark_FAugPath, 0, sizeof Mark_FAugPath );	//if Find_AugPath(V)==0 then Mark dosent need to reset
		}
}

void Out_put(){
	cerr << "Number of Maximum Matching..." << endl;
	cout << match_size << endl;
	cerr << "Now, the Maximum Matching..." << endl;
	for( int i=0; i<X_size+Y_size; i++ ){
		if( Mate[i] != -1 )
			cout << i+1 << "th::" << Mate[i]+1 << endl;
		else cout << i+1 << "th::" << "dont have mate" << endl;
	}
}

int main(){
	Input();
	Find_Maximum_Matching();
	Out_put();
	return 0;
}
