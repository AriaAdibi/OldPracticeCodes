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

class myVec{
	public:
		myVec(){ itsVec= pdd(0, 0); }
		myVec( const pdd &a ){ itsVec= a; }
		~myVec(){}
		void SetVal( const pdd &a ){ itsVec= a; }
		double Get_x() const{ return itsVec.X; }
		double Get_y() const{ return itsVec.Y; }
		double Mag(){ return sqrt( itsVec.X*itsVec.X + itsVec.Y*itsVec.Y ); }
		double operator ^ ( const myVec &b ) const;
	private:
		pdd itsVec;
};

double myVec::operator ^ ( const myVec &b ) const{
	return ( itsVec.X* b.Get_y() - itsVec.Y* b.Get_x() );		
}

struct Line{
	double A, B, C;
	Line(){ A= B= C= 0; }
	~Line(){}
};
