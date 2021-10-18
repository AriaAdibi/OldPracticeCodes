#include <iostream>
#include <cmath>

using namespace std;

typedef pair<double, double> pdd;
#define X first
#define Y second

class myVec{
	public:
		myVec(){ itsVec= pdd(0, 0); }
		myVec( const pdd &a ){ itsVec= a; }
		~myVec(){}
		double Get_x() const{ return itsVec.X; }
		double Get_y() const{ return itsVec.Y; }
		void SetVal( const pdd &a ){ itsVec= a; }
		double Mag() const{ return sqrt( itsVec.X* itsVec.X + itsVec.Y*itsVec.Y ); }
		const myVec operator + ( const myVec &b ) const;
		const myVec operator - ( const myVec &b ) const;
		double operator * ( const myVec &b ) const;
		double operator ^ ( const myVec &b ) const;
	private:
		pdd itsVec;
};

const myVec myVec::operator + ( const myVec &b ) const{
	myVec r( pdd( itsVec.X + b.Get_x(), itsVec.Y + b.Get_y() ) );
	return r;
}

const myVec myVec::operator - ( const myVec &b ) const{
	myVec r( pdd( itsVec.X - b.Get_x(), itsVec.Y - b.Get_y() ) );
	return r;
}

double myVec::operator * ( const myVec &b ) const{
	return ( itsVec.X* b.Get_x() + itsVec.Y*b.Get_y() );
}

double myVec::operator ^ ( const myVec &b ) const{
	return ( itsVec.X* b.Get_y() - itsVec.Y* b.Get_x() );
}

class myPoint{
	public:
		myPoint(){ itsPoint= pdd(0,0); };
		myPoint( const pdd &A ){ itsPoint= A; }
		~myPoint(){}
		double Get_x() const{ return itsPoint.X; }
		double Get_y() const{ return itsPoint.Y; }
		void SetVal( const pdd &A ){ itsPoint= A; }
		pdd operator + ( const myPoint &B ) const;
		pdd operator - ( const myPoint &B ) const;
	private:
		pdd itsPoint;
};

pdd myPoint::operator + ( const myPoint &B ) const{
	return pdd( itsPoint.X+ B.Get_x(), itsPoint.Y+ B.Get_y() );
}

pdd myPoint::operator - ( const myPoint &B ) const{
	return pdd( itsPoint.X- B.Get_x(), itsPoint.Y- B.Get_y() );
}

myPoint A, B, C;

void Input(){
	pdd myIn[ 5 ];
	double x, y;
	for( int i=0; i<3; i++ ){
		cin >> x >> y;
		myIn[i]= pdd( x, y );
	}
	A.SetVal( myIn[0] ); B.SetVal( myIn[1] ); C.SetVal( myIn[2] );
}

int main(){
	Input();
	myVec AB( B-A ); myVec BA( A-B );
	myVec AC( C-A ); myVec CA( A-C );
	myVec BC( C-B ); myVec CB( B-C );

	double dist;
	if( (AB*BC) >= 0 ) dist= CB.Mag();
	else if( (BA*AC) >= 0 ) dist= CA.Mag();
	else{
		dist=( ( (AB^AC)/2 )/ AB.Mag() ) *2;
	}
	cout << abs(dist) << endl;
	
	return 0;
}
