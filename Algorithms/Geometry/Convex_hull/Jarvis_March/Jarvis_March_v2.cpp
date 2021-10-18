#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

#include "myClass.hpp"

int n;
vector< myPoint > Q;
vector< myPoint > CH;

void Input(){
	cin >> n;
	double x, y;
	for( int i=0; i<n; i++ ){
		cin >> x >> y;
		Q.push_back( myPoint( pdd(x,y) ) );
	}
}

bool not_Colinear(){
	bool not_Colinear= false;
	myVec a( Q[1]- Q[0] );
	for( int i=2; i<n; i++ ){
		myVec b(Q[i]- Q[0]);
		if( ((a^b) > 0+eps) || ((a^b) < 0-eps ) ) //a^b != 0
		{ not_Colinear= true; break; }
	}
	return not_Colinear;
}

myPoint Find_Start(){
	myPoint start= myPoint( pdd(inf, -inf) );
	for( int i=0; i<n; i++ )
		if( Q[i].itsPoint.X < start.itsPoint.X )
			start= Q[i];
		else if( Q[i].itsPoint.X == start.itsPoint.X )
			if( Q[i].itsPoint.Y > start.itsPoint.Y )
				start= Q[i];
	return start;
}

void Jarvis_March(){
	if( n<=2 || !not_Colinear() )
	{ cout << "Error: Your input is incorrect." << endl; return; };
	myPoint start= Find_Start();

	myPoint P= start;
	do{
		CH.push_back( P );
		myPoint nx_P= myPoint( pdd(inf, inf) );	
		for( int i=0; i<n; i++ ){
			if( Q[i] == P ) continue;
			if( nx_P == myPoint( pdd(inf, inf) ) )
				nx_P= Q[i];
			
			double Cross= myVec( nx_P- P ) ^ myVec( Q[i]- P );
			if( Cross > 0+eps )
				nx_P= Q[i];
			else if( 0-eps <= Cross && Cross <= 0+eps ) //Cross == 0
				if( myVec( nx_P-P ).Mag() < myVec( Q[i]-P ).Mag()-eps )
					nx_P= Q[i];
		}
		P= nx_P;
	}while( P != start );
}

void Out_put(){
	cout << fixed << setprecision(3);
	for( int i=0; i<(int)CH.size(); i++ )
		cout << CH[i].itsPoint.X << " " << CH[i].itsPoint.Y << endl;
}

int main(){
	Input();
	Jarvis_March();
	Out_put();
	return 0;
}
