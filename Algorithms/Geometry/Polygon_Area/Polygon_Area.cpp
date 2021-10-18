#include <iostream>
#include <cmath>

using namespace std;

#include "myClass.hpp"

int n;
const int MAX_N= 100;
myPoint P[ MAX_N ];

void Input(){
	cin >> n;
	double x, y;
	for( int i=0; i<n; i++ ){
		cin >> x >> y;
		P[i].SetVal( pdd(x,y) );
	}
}

void Find_PArea(){
	myPoint A= P[0];
	double Area= 0;
	for( int i=1; i<n-1; i++ ){
		myVec AB( P[i]-A );
		myVec AC( P[i+1]-A );
		Area+= (AB ^ AC)/2;
	}
	cout << abs( Area ) << endl;
}

int main(){
	Input();
	Find_PArea();
	return 0;
}
