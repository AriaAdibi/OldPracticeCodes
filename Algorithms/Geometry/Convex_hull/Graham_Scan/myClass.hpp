const double eps= 1e-8;

typedef pair<double, double> pdd;
#define X first
#define Y second

class myVec{
	public:
		myVec(){ itsVec= pdd(0, 0); }
		myVec( const pdd &a ){ itsVec= a; }
		~myVec(){}
		void SetVal( const pdd &a ){ itsVec= a; }
		double Get_x() const{ return itsVec.X; }
		double Get_y() const{ return itsVec.Y; }
		double Mag() const{ return sqrt( itsVec.X*itsVec.X + itsVec.Y*itsVec.Y ); }
		double operator ^ ( const myVec &b ) const;
	private:
		pdd itsVec;
};

double myVec::operator ^ ( const myVec &b ) const{
	return ( itsVec.X* b.Get_y() - itsVec.Y* b.Get_x() );
}
