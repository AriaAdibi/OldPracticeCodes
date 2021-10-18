typedef pair<double, double> pdd;
#define X first
#define Y second

class myPoint{
	public:
		myPoint(){ itsPoint= pdd(0, 0); }
		myPoint( const pdd &A ){ itsPoint= A; }
		~myPoint(){}
		double Get_x() const{ return itsPoint.X; }
		double Get_y() const{ return itsPoint.Y; }
		void SetVal( const pdd &A ){ itsPoint= A; }
		pdd operator - ( const myPoint &B ) const;
	private:
		pdd itsPoint;
};

pdd myPoint::operator - ( const myPoint &B ) const{
	return pdd(itsPoint.X- B.Get_x(), itsPoint.Y- B.Get_y() );
}

class myVec{
	public:
		myVec(){ itsVec= pdd(0,0); }
		myVec( const pdd &a ){ itsVec= a; }
		~myVec(){}
		double Get_x() const{ return itsVec.X; }
		double Get_y() const{ return itsVec.Y; }
		void SetVal( const pdd &a ){ itsVec= a; }
		double operator ^ ( const myVec &b ) const;
	private:
		pdd itsVec;
};

double myVec::operator ^ ( const myVec &b ) const{
	return ( itsVec.X* b.Get_y() - itsVec.Y* b.Get_x() );
}
