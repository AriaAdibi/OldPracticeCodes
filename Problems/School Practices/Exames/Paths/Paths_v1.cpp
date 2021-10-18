#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

//#include "myClass.hpp"
const double eps= 1e-10;
const double inf= 1e10;

typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define X first
#define Y second

#define Show(X) cerr << #X << "= " << X << " "

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
	double det= l1.A*l2.B - l2.A*l1.B;
	if( det != 0 ){
		I.X= (l1.C*l2.B - l2.C*l1.B )/ det;
		I.Y= (l2.C*l1.A - l1.C*l2.A )/ det;
	}
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
	if( (AB*BC) >= 0+eps ) dist= myVec( C-B ).Mag();//TODO
	else if( (BA*AC) >= 0+eps ) dist= myVec( C-A ).Mag();//TODO
	else{
		Line l; Create_line( l, A.itsPoint, B.itsPoint );
		Line pl= Create_pline( l, C.itsPoint );
		pdd I= Line_Line_Intersection( l, pl );
		dist= myVec( C-I ).Mag();
	}

	return dist;
}
///////////////////////////////////////////////////////////////////////////////

int n;
const int MAX_N= 1000+ 10;
pdd Village[ MAX_N ][2];
Line Path[ MAX_N ];

int Mark_Com[ MAX_N ];
vector< int > Com[ MAX_N ];

double W_MST= 0;
vector< pair<double, pii> > E;
int Par[ MAX_N ];
int Rank[ MAX_N ];

void Input(){
	cin >> n;
	double x1, y1, x2, y2;
	for( int i=0; i<n; i++ ){
		cin >> x1 >> y1 >> x2 >> y2;
		Village[i][0]= pdd(x1,y1);    Village[i][1]= pdd(x2,y2);			
		Create_line( Path[i], pdd(x1,y1), pdd(x2,y2) );	
	}
}

bool Is_between( const pdd &I, const pdd &p1, const pdd &p2 ){
	if( min(p1.X, p2.X) <= I.X && I.X <= max(p1.X, p2.X) )	//TODO
		if( min( p1.Y, p2.Y ) <= I.Y && I.Y <= max( p1.Y, p2.Y ) )
			return 1;
	return 0;
}

int Find_Components(){
	int nC= 0;
	fill( Mark_Com+0, Mark_Com+MAX_N, -1 );

	for( int i=0; i<n; i++ )
		if( Mark_Com[i] == -1 ){
			Mark_Com[i]= nC;
			Com[nC].push_back( i );

			for( int j=i+1; j<n; j++ ){
				pdd I= Line_Line_Intersection( Path[i], Path[j] );

				if( Is_between( I, Village[i][0], Village[i][1] ) && Is_between( I, Village[j][0], Village[j][1] ) ){
					Mark_Com[j]= nC;
					Com[nC].push_back( j );
				}
			}
			nC++;
		}
	return nC;
}

double Find_min_len( int c1, int c2 ){
	double min_e= inf;
	for( int i=0; i<(int)Com[c1].size(); i++ )
		for( int j=0; j<(int)Com[c2].size(); j++ ){
			myPoint A= myPoint( Village[ Com[c1][i] ][0] );	
			myPoint B= myPoint( Village[ Com[c1][i] ][1] );
			myPoint C= myPoint( Village[ Com[c2][j] ][0] );
			myPoint D= myPoint( Village[ Com[c2][j] ][1] );
			min_e= min( min_e, Point_Line_Dist( A, C, D ) );
			min_e= min( min_e, Point_Line_Dist( B, C, D ) );
			min_e= min( min_e, Point_Line_Dist( C, A, B ) );
			min_e= min( min_e, Point_Line_Dist( D, A, B ) );
		}
	return min_e;
}

void Create_CGraph( const int &nC ){
	for( int i=0; i<nC; i++ )
		for( int j=i+1; j<nC; j++ ){
			double e= Find_min_len( i, j );
			E.push_back( pair<double, pii>( e, pii(i,j) ) );
		}
}

int Find_Par( const int &v ){
	if( Par[v] == v ) 
		return v;
	return ( Par[v]= Find_Par( Par[v] ) );
}

void Union( int &v, int &u ){
	v= Find_Par( v );  u= Find_Par( u );
	if( Rank[v] > Rank[u] )
		Par[u]= v;
	else if( Rank[v] < Rank[u] )
		Par[v]= u;
	else{ Par[v]= u; Rank[u]++; };
}

void Kruskal( const int V ){
	for( int i=0; i<V; i++ )
		Par[i]= i;

	sort( E.begin(), E.end() );
	for( int i=0; i<(int)E.size(); i++ ){
		int v= E[i].Y.X;  int u= E[i].Y.Y;
		if( Find_Par(v) != Find_Par(u) ){
			W_MST+= E[i].X;
			Union( v, u );
		}
	}
}

void Out_put(){
	cout << fixed << setprecision(2);
	cout << W_MST << endl;
}

int main(){
	Input();
	int nC= Find_Components();
	Create_CGraph( nC );
	Kruskal( nC );
	Out_put();
	return 0;
}
