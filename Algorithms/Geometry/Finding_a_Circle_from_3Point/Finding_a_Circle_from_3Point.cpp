#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#include "myClass.hpp"

pdd p1, p2, p3;
Line l1, l2;
Line pl1, pl2;

void Input(){
	double x, y;
	cin >> x >> y; p1= pdd(x,y);
	cin >> x >> y; p2= pdd(x,y);
	cin >> x >> y; p3= pdd(x,y);
}

void Create_line( Line &l, const pdd &p1, const pdd &p2 ){
	l.A= p2.Y- p1.Y;    l.B= -(p2.X- p1.X);    l.C= p1.X*l.A + p1.Y*l.B;
}

void Create_perpendicularl( Line &pl, const Line &l, const pdd &mid_l ){
	pl.A= -l.B;    pl.B= l.A;    pl.C= pl.A*mid_l.X + pl.B*mid_l.Y;
}

myPoint Find_Intersection( const Line &pl1, const Line &pl2 ){
	//pl1, pl2 are line not segment
	pdd I;
	double det= pl1.A* pl2.B - pl2.A* pl1.B;
	I.X= (pl1.C* pl2.B - pl2.C* pl1.B )/ det;
	I.Y= (pl2.C* pl1.A - pl1.C* pl2.A )/ det;
	if( I.X == -0 ) I.X= 0; if( I.Y == -0 ) I.Y= 0;
	return myPoint( I );
}

void Find_theCircle(){
	myPoint P1( p1 ); myPoint P2( p2 ); myPoint P3( p3 );
	if( (myVec( P2- P1 ) ^	myVec( P3- P1)) == 0 )
		cout << "Error: they are in same line" << endl;
	else{
		Create_line( l1, p1, p2 ); 	Create_line( l2, p2, p3 );

		pdd mid_l1= pdd( (p1.X+p2.X)/2, (p1.Y+p2.Y)/2 );
		pdd mid_l2= pdd( (p2.X+p3.X)/2, (p2.Y+p3.Y)/2 );
		Create_perpendicularl( pl1, l1, mid_l1 );
		Create_perpendicularl( pl2, l2, mid_l2 );

		myPoint O= Find_Intersection( pl1, pl2 );
		cout << fixed << setprecision(3);
		cout << "Center of Circle is: " << O.Get_x() << " " << O.Get_y() << endl;
		cout << "And R is: " << myVec( P2- O ).Mag() << endl;
	}
}

int main(){
	Input();
	Find_theCircle();
	return 0;
}
