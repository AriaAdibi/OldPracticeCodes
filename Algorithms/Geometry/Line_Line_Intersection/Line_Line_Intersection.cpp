#include <iostream>

using namespace std;

#include "myClass.hpp"
struct Line{
	double A, B, C;
	Line(){ A= B= C= 0; }
	~Line(){}
};

Line l1, l2;
double x0, x1, x2, x3;
double y0, y1, y2, y3;

void Input(){
	double x, y;		
	myPoint P[ 4 ];
	for( int i=0; i<4; i++ ){
		cin >> x >> y;
		P[i].SetVal( pdd(x,y) );
	}

	x0= P[0].Get_x(); y0= P[0].Get_y();
	x1= P[1].Get_x(); y1= P[1].Get_y();
	x2= P[2].Get_x(); y2= P[2].Get_y();
	x3= P[3].Get_x(); y3= P[3].Get_y();
	//P[0], P[1]
	l1.A= y1- y0;	l1.B= -(x1- x0);    l1.C= x0*l1.A + y0*l1.B;
	//P[2], P[3]
	l2.A= y3- y2;	l2.B= -(x3- x2);    l2.C= x2*l2.A + y2*l2.B;
}

bool Is_between( pdd p1, pdd p2, pdd I ){
	if( min( p1.X, p2.X ) <= I.X && I.X <= max( p1.X, p2.X ) )
		if( min( p1.Y, p2.Y ) <= I.Y && I.Y <= max( p1.Y, p2.Y ) )
			return 1;
	return 0;
}

void Find_Intersection(){
	double det= l1.A*l2.B - l2.A*l1.B;
	double x= (l1.C*l2.B - l2.C*l1.B)/ det;
	double y= -(l1.C*l2.A - l2.C*l1.A)/ det;
	
	if( Is_between( pdd(x0, y0), pdd(x1, y1), pdd(x,y) ) && Is_between( pdd(x2,y2), pdd(x3,y3), pdd(x,y) ) )
		cout << x << " " << y << endl;
	else cout << "NONE" << endl;
}

int main(){
	Input();
	Find_Intersection();
	return 0;
}
