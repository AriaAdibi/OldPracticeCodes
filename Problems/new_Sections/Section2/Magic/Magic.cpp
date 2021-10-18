#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef pair< vector<int>, char > pvc;
#define X first
#define Y second

const int MAX_N= 40320+ 100;
vector<int> Goal;

map < vector<int>, pvc > Par;
set< vector<int> > Mark;
vector<int> u; //to avoid copy

void Out_put();
void Input(){
	for( int i=0, x; i<8; i++ ){
		cin >> x;
		Goal.push_back( x );
	}
}

void Apply_Move( const int &r, vector<int> &v ){
	u= v;
	if( r == 0 )
		reverse( u.begin(), u.end() );
	if( r == 1 ){
		for( int i=3; i>=1; i-- ) swap( u[i], u[i-1] );
		for( int i=4; i<=6; i++ ) swap( u[i], u[i+1] );
	}
	if( r == 2 ){
		int el1= u[1],  el2= u[2],  el5= u[5],  el6= u[6];
		u[1]= el6;  u[2]= el1;  u[5]= el2;   u[6]= el5;
	}
}

char Find_Move( const int &i ){
	if( i == 0 ) return 'A';
	if( i == 1 ) return 'B';
	if( i == 2 ) return 'C';
}

bool Checker(){
	for( int i=0; i<8; i++ )
		if( u[i] != Goal[i] )
			return 0;
	return 1;
}

void BFS(){
	int myint[]= {1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> I( myint, myint+8 ); u= I;

	int st= 0, en= 0;
	vector<int> que[ MAX_N ];
	que[en++]= I;	Mark.insert( I );  Par[I]= pvc( I, 'E' );

	if( Checker() )
	{ Out_put(); return; }

	while( st< en ){
		vector<int> v= que[st];
		for( int i=0; i<3; i++ ){
			Apply_Move( i, v );	//u=
			if( Mark.find( u ) == Mark.end() ){
				Mark.insert( u );
				Par[u]= pvc( v, Find_Move(i) );
				que[en++]= u;

				if( Checker() )
				{ Out_put(); return; }
			}
		}
		st++;
	}
}

void Out_put(){
	vector<char> M;

	while( Par[u].Y != 'E' ){
		M.push_back( Par[u].Y );
		u= Par[u].X;	
	}
	
	cout << (int)M.size() << endl;
	for( int i= M.size()-1; i>=0; i-- )
		cout << M[i];
	cout << endl;
}

int main(){
	Input();
	BFS();
	return 0;
}
