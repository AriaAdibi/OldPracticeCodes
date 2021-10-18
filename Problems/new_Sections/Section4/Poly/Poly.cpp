#include <iostream>
#include <iomanip>
#include <algorithm>
#include <complex>
#include <vector>

using namespace std;

const double eps= 1e-8;
typedef complex<double> pnt;
#define X real()
#define Y imag()

double operator ^ ( const pnt &A, const pnt &B ){
	return (conj(A)*B).Y;
}

bool Not_eq( const pnt &A, const pnt &B ){
	if( A.X-eps <= B.X && B.X <= A.X+eps )
		if( A.Y-eps <= B.Y && B.Y <= A.Y+eps )
			return 0;
	return 1;
}

int n, m;
vector<pnt> P1, P2;

void Get_Polygon( const int &r, vector<pnt> &A ){
	for( int i=0; i<r; i++ ){
		double x, y;  cin >> x >> y;
		A.push_back( pnt(x,y) );
	}
}

void Input(){
	cin >> n;
	Get_Polygon( n, P1 );
	cin >> m;
	Get_Polygon( m, P2 );
}

void Move_to_Origin( const pnt move, vector<pnt> &A ){
	for( int i=0; i<(int)A.size(); i++ ) A[i]-= move;
}

bool CW_Arrangement( const pnt &A, const pnt &B ){
	if( (A^B) > 0+eps ) return 1;
	return 0;
}

void Scale_to_myStandard( vector<pnt> &A ){
	pnt q= A[1];
	for( int i=0; i<(int)A.size(); i++ ) A[i]/= q;
}

int main(){
	Input();
	if( n != m )
	{ cout << "NO" << endl; return 0; }

	Move_to_Origin( P1[0], P1 );		//Arrange in CW Oreder
	/**/
	for( int i=0; i<(int)P1.size(); i++ )
		cerr << P1[i] << " ";
	cerr << endl;/**/
	sort( P1.begin(), P1.end(), CW_Arrangement );
	/**/
	for( int i=0; i<(int)P1.size(); i++ )
		cerr << P1[i] << " ";
	cerr << endl;/**/
	Scale_to_myStandard( P1 );
	/**/
	for( int i=0; i<(int)P1.size(); i++ )
		cerr << P1[i] << " ";
	cerr << endl; /**/

	Move_to_Origin( P2[0], P2 );
	sort( P2.begin(), P2.end(), CW_Arrangement );
	
	bool Is_OK= false;
	for( int i=0; i<n; i++ ){
		vector<pnt> Q;
		for( int j=0; j<n; j++ )
			Q.push_back( P2[(j+i)%n] );
		Move_to_Origin( Q[0], Q );
		Scale_to_myStandard( Q );

		bool Is_Similar= true;
		for( int j=0; j<n; j++ )
			if( Not_eq( P1[j], Q[j] ) )
			{ Is_Similar= false;  break; }
		if( Is_Similar )
		{ cout << "Yes" << endl; Is_OK= true; break;  }
	}
	if( !Is_OK )
		cout << "NO" << endl;
	return 0;
}
