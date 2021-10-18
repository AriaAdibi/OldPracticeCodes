typedef pair<double, double> pdd;
#define X first
#define Y second

class myPoint{
	public:
		myPoint(){ itsPoint= pdd(0,0); }
		myPoint( const pdd &A ){ itsPoint= A; }
		~myPoint(){}
		void SetVal( const pdd &A ){ itsPoint= A; }
		double Get_x() const{ return itsPoint.X; }
		double Get_y() const{ return itsPoint.Y; }
	private:
		pdd itsPoint;
};
