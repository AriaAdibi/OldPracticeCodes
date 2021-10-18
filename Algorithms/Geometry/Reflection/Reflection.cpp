#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#include "myClass.hpp"

pdd p1, p2, p3;
Line l1, pl1;

void Input(){
	double x, y;
	cin >> x >> y; p1= pdd(x, y);
	cin >> x >> y; p2= pdd(x, y);
	cin >> x >> y; p3= pdd(x, y );
}

void Create_line( Line &l, const pdd &p1, const pdd &p2 ){
	l.A= p2.Y- p1.Y;    l.B= p1.X- p2.X;    l.C= p1.X*l.A + p1.Y*l.B;
}

void Create_lPerpendicular( Line &pl1, const Line &l, const pdd &p1 ){
	pl1.A= -l.B;    pl1.B= l.A;    pl1.C= p1.X*pl1.A + p1.Y*pl1.B;	
}

pdd Find_Intersection( const Line &l1, const Line &l2 ){
	//they are line not segment
	pdd I;
	double det= l1.A*l2.B - l2.A*l1.B;
	I.X= (l1.C*l2.B - l2.C*l1.B )/ det;
	I.Y= (l2.C*l1.A - l1.C*l2.A )/ det;
	return I;
}

void Find_pReflection(){
	Create_line( l1, p2, p3 );
	Create_lPerpendicular( pl1, l1, p1 );
	pdd H= Find_Intersection( l1, pl1 );

	cout << fixed << setprecision(3);
	cout << "Result of Reflection is: " << H.X- (p1.X- H.X) << " " << H.Y- (p1.Y- H.Y) << endl;
}

int main(){
	Input();
	Find_pReflection();
	return 0;
}
