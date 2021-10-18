#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

#include "myClass.hpp"

int n;
const double inf= 1e10;
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

void Jarvis_March(){
	//Standard first
	if( n==0 ) return;
	myPoint start( pdd(inf,-inf) );
	for( int i=0; i<n; i++ )
		if( Q[i].itsPoint.X < start.itsPoint.X )
			start= Q[i];
		else if( Q[i].itsPoint.X == start.itsPoint.X )
			if( Q[i].itsPoint.Y > start.itsPoint.Y )
				start= Q[i];
	myPoint P= start;
	do{
		CH.push_back( P );
		myPoint nx_P( pdd(inf, inf) );
		for( int i=0; i<n; i++ ){
			if( Q[i] == P ) continue;

			if( nx_P.itsPoint == pdd(inf, inf) ) nx_P= Q[i];
			double Cross= myVec( nx_P-P ) ^ myVec( Q[i]-P );
			if( Cross > 0+eps )
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
