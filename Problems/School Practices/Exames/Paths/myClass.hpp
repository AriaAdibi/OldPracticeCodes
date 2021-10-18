const double eps= 1e-10;
const double inf= 1e10;

typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define X first
#define Y second

struct myPoint{
	pdd itsPoint;
	myPoint(){ itsPoint= pdd(0,0); }
	myPoint( const pdd &P ){ itsPoint= P; }
	~myPoint(){}
	void SetVal( const pdd &P ){ itsPoint= P; }
	double Get_X() const{ return itsPoint.X; }
	double Get_Y() const{ return itsPoint.Y; }
	bool operator == ( const myPoint &P ) const { return itsPoint == P.itsPoint; }
	bool operator != ( const myPoint &P ) const { return itsPoint != P.itsPoint; }
	pdd operator + ( const myPoint &P ) const;
	pdd operator - ( const myPoint &P ) const;
};

pdd myPoint::operator + ( const myPoint &P ) const{
	return( pdd(itsPoint.X+P.Get_X(), itsPoint.Y+P.Get_Y() ) );
}
pdd myPoint::operator - ( const myPoint &P ) const{
	return( pdd(itsPoint.X-P.Get_X(), itsPoint.Y-P.Get_Y() ) );
}

struct Line{
	double A, B, C;
	Line(){ A= B= C= 0; }
	~Line(){}
};

class myVec{
	public:
		myVec(){ itsVec= pdd(0,0); }
		myVec( const pdd &a ){ itsVec= a; }
		~myVec(){}
		void SetVal( const pdd &a ){ itsVec= a; }
		double Get_X() const{ return itsVec.X; }
		double Get_Y() const{ return itsVec.Y; }
		double Mag() const{ return sqrt( itsVec.X*itsVec.X + itsVec.Y*itsVec.Y ); }
		double operator ^ ( const myVec &b ) const;
		double operator * ( const myVec &b ) const;
	private:
		pdd itsVec;
};

double myVec::operator ^ ( const myVec &b ) const{
	return ( itsVec.X* b.Get_Y() - itsVec.Y*b.Get_X() );
}

double myVec::operator * ( const myVec &b ) const{
	return ( itsVec.X*b.Get_X() + itsVec.Y*b.Get_Y() );
}

void Create_line( Line &l, const pdd &p1, const pdd &p2 ){
	l.A= p2.Y- p1.Y;    l.B= p1.X- p2.X;    l.C= p1.X*l.A + p1.Y*l.B;
}

pdd Line_Line_Intersection( const Line &l1, const Line &l2 ){
	pdd I= pdd( inf, inf );
	if( l1.A/l1.B == l2.A/l2.B ) return I;//are parallel

	double det= l1.A*l2.B - l2.A*l1.B;
	I.X= (l1.C*l2.B - l2.C*l1.B )/ det;
	I.Y= (l2.C*l1.A - l1.C*l2.A )/ det;
	return I;
}

Line Create_pline( const Line &l, const pdd &P ){
	Line pl;
	pl.A= -l.B;   pl.B= l.A;   pl.C= P.X*pl.A + P.Y*pl.B;
	return pl;
}

double Point_Line_Dist( const myPoint &C,  const myPoint &A, const myPoint &B ){
	myVec AB( B-A );  myVec BC( C-B );   myVec BA( A-B );   myVec  AC( C-A );

	double dist;
	if( (AB*BC) >= 0+eps ) dist= myVec( C-B ).Mag();
	else if( (BA*AC) >= 0+eps ) dist= myVec( C-A ).Mag();
	else{
		Line l; Create_line( l, A.itsPoint, B.itsPoint );
		Line pl= Create_pline( l, C.itsPoint );
		pdd I= Line_Line_Intersection( l, pl );
		dist= myVec( C-I ).Mag();
	}

	return dist;
}
