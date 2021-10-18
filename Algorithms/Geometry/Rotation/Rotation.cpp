#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

typedef pair<double, double> pdd;
#define X first
#define Y second

pdd O, P;
const double PI= 3.1415;
double teta;

void Input(){
	double x, y;
	cin >> x >> y; P= pdd(x, y);
	cin >> x >> y; O= pdd(x, y);
	cin >> teta; //CounterClockWise
}

void Rotate(){
	pdd move= O;    O= pdd(0, 0);
	P= pdd( P.X- move.X, P.Y- move.Y );

	pdd result; 
	result.X= P.X* cos(teta*PI/180) - P.Y* sin(teta*PI/180);
	result.Y= P.X* sin(teta*PI/180) + P.Y* cos(teta*PI/180);
	
	P= pdd( P.X+ move.X, P.Y+ move.Y );	O= move;
	result= pdd( result.X+ move.X, result.Y+ move.Y );

	cout << fixed << setprecision(3);
	cout << "Result is: " << result.X << " " << result.Y << endl;
}

int main(){
	Input();
	Rotate();
	return 0;
}
