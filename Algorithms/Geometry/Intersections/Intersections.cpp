#include <iostream>
#include <iomanip>
#include <algorithm>
#include <complex>
#include <vector>
#include <cmath>

using namespace std;

const double inf= 1e9;
const double eps= 1e-7;
typedef complex<double> pnt;
typedef pair<pnt, pnt> Line;
typedef pair<pnt, double> Circule;
#define F first
#define S second
#define X real()
#define Y imag()

bool D_eq( const double &x, const double &val ){
	if( val-eps <= x  &&  x <= val+eps ) return 1;
	return 0;
}

bool P_eq( const pnt &p, const pnt &q ){
	if( q.X-eps <= p.X && p.X <= q.X+eps )
		if( q.Y-eps <= p.Y && p.Y <= q.Y+eps )
			return 1;
	return 0;
}

double P_dist( const pnt &p, const pnt &q ){
	return sqrt( (q.X-p.X)*(q.X-p.X) + (q.Y-p.Y)*(q.Y-p.Y) );
}

struct TheLine{
	double A, B, C;
	TheLine(){ A= B= C= 0; }
	~TheLine(){}
};

TheLine Line_to_TheLine( const Line &L ){
	TheLine l;    pnt p= L.F;    pnt q= L.S;
	l.A= q.Y- p.Y;    l.B= p.X- q.X;    l.C= p.X*l.A + p.Y*l.B;
	return l;
}

int nq;
vector<char>    Which;
vector<Line>    myLines;
vector<Circule> myCircules; 

vector<pnt> Intersections;

void Input(){
	cin >> nq;
	for( int i=0; i<nq; i++ ){
		char ch;  cin >> ch;
		if( ch == 'L' ){
			Which.push_back( 'L' );
			double A, B, C, D;
			cin >> A >> B >> C >> D;
			myLines.push_back( Line( pnt(A,B), pnt(C,D) ) );
		}
		else if( ch == 'C' ){
			Which.push_back( 'C' );
			double OX, OY, R;
			cin >> OX >> OY >> R;
			myCircules.push_back( Circule( pnt(OX, OY), R ) );
		}
	}
}

void Line_Line_Intersection( const int  &ind1, const int &ind2 ){
	Line L1= myLines[ ind1 ];  TheLine l1= Line_to_TheLine( L1 );
	Line L2= myLines[ ind2 ];  TheLine l2= Line_to_TheLine( L2 );

	double det= l1.A*l2.B - l2.A*l1.B;
	if( D_eq( det, 0 ) ) return;  //they are parallel
	pnt I= pnt( inf, inf );
	I.X= (l1.C*l2.B - l2.C*l1.B) / det;
	I.Y= (l2.C*l1.A - l1.C*l2.A) / det;

	Intersections.push_back( I );
}

void Circule_Circule_Intersection( const int &ind1, const int &ind2 ){
	Circule C1= myCircules[ ind1 ];    Circule C2= myCircules[ ind2 ];
	pnt O1= C1.F;  double r1= C1.S;    pnt O2= C2.F;  double r2= C2.S;

	if( P_eq( O1, O2 ) ) return;
	pnt sav_O1= O1;  pnt sav_O2= O2;		 //Save
	O2-= O1;  O1-=O1; 				 //Move
	O1/= O2;  r1/= abs(O2);  r2/= abs(O2);  O2/=O2;  //Scale && Rotate

	if( abs(r1-r2)-eps > 1 || 1 > (r1+r2)+eps ) return;	 //Have no Intersection
	pnt I[2]; I[0]= I[1]= pnt( inf, inf );
	I[0].X= ( (r1*r1)-(r2*r2)+ 1 )/ 2;
	I[0].Y= sqrt( (r1*r1)- (I[0].X*I[0].X) );
	I[1]= pnt( I[0].X, -I[0].Y );

	O2= sav_O2;  O1= sav_O1;
	for( int i=0; i<2; i++ ){
		I[i]*= (O2-O1);  I[i]+= O1;
		Intersections.push_back( I[i] );
	}
}

void Circule_Line_Intersection( const int &ind1, const int &ind2 ){
	Circule C= myCircules[ ind1 ];    Line L= myLines[ ind2 ];
	pnt O= C.F;  double r= C.S;      pnt A= L.F;  pnt B= L.S;

	pnt sav_A= A;  pnt sav_B= B;	   //Save
	O-= A;  B-= A;  A-= A;		   //Move
	r/= abs(B);  O/=B;  A/=B;  B/=B;   //Scale && Rotate
	double diffX= sqrt( (r*r)-(O.Y*O.Y) );

	pnt I[ 2 ];  I[0]= I[1]= pnt(inf, inf);
	I[0]= pnt( O.X- diffX, 0 );  I[1]= pnt( O.X+diffX, 0 );
	A= sav_A;  B= sav_B;
	for( int i=0; i<2; i++ )
		if( D_eq( P_dist( I[i], pnt(0,0) ) + P_dist( I[i], pnt(1,0) ), 1 ) ){
			I[i]*= (B-A);  I[i]+= A;
			Intersections.push_back( I[i] );
		}
}

bool Comp( const pnt &p, const pnt &q ){
	if( p.X < q.X-eps ) return 1;
	else if( D_eq( p.X, q.X ) )
		if( p.Y < q.Y-eps ) return 1;
	return 0;
}

void Out_put(){
	sort( Intersections.begin(), Intersections.end(), Comp );
	for( int i=0; i<(int)Intersections.size()- 1; i++ ){
		pnt p= Intersections[i];  pnt q= Intersections[i+1];
		if( P_eq( p, q ) )
		{  Intersections.erase( Intersections.begin()+i+1 );  i--;  }
	}

	cout << fixed << setprecision(3);
	for( int i=0; i<(int)Intersections.size(); i++ ){
		if( D_eq( Intersections[i].X, -0 ) )
			cout << 0.000 << " ";
		else cout << Intersections[i].X << " ";
		if( D_eq( Intersections[i].Y, -0 ) )
			cout << 0.000 << endl;
		else cout << Intersections[i].Y << endl;
	}
}

int main(){
	Input();
	for( int i=0; i<(int)myLines.size(); i++ )
		for( int j=i+1; j<(int)myLines.size(); j++ )
			Line_Line_Intersection( i, j );

	for( int i=0; i<(int)myCircules.size(); i++ )
		for( int j=i+1; j<(int)myCircules.size(); j++ )
			Circule_Circule_Intersection( i, j );

	for( int i=0; i<(int)myCircules.size(); i++ )
		for( int j=0; j<(int)myLines.size(); j++ )
			Circule_Line_Intersection( i, j );
	Out_put();
	return 0;
}
