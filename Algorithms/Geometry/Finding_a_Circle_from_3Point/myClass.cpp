#include <iostream>
#include <cmath>

using namespace std;

typedef pair<double, double> pdd;
#define X first
#define Y second

class myPoint{
	public:
		myPoint(){ itsPoint= pdd(0, 0); }
		myPoint( const pdd &P ){ itsPoint= P; }
		~myPoint(){}
		void SetVal( const pdd &P ){ itsPoint= P; }
		double Get_x() const{ return itsPoint.X; }
		double Get_y() const{ return itsPoint.Y; }
		pdd operator - ( const myPoint &P ) const;
	private:
		pdd itsPoint;
};

pdd myPoint::operator - ( const myPoint &P ) const{
	return pdd( itsPoint.X- P.Get_x(), itsPoint.Y- P.Get_y() );
}

struct Line{
	double A, B, C;
	Line(){ A= B= C= 0; }
	~Line(){}
};

int main(){
	return 0;
}
