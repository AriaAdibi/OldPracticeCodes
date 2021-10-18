#include <iostream>
#include <algorithm>
#include <complex>
#include <vector>

using namespace std;

const double eps= 1e-7;
typedef complex<double> pnt;
#define X real()
#define Y imag()

bool D_eq( const double &x, const double &val ){
	if( val-eps <= x && x <= val+eps ) return 1;
	return 0;
}

double operator ^ ( const pnt &A, const pnt &B ){
	return (conj(A)*B).Y;
}

int n;
vector<pnt> pnts;

void Out_put( vector<pnt> &CH );
void Input(){
	cin >> n;
	for( int i=0; i<n; i++ ){
		double x, y;  cin >> x >> y;
		pnts.push_back( pnt(x,y) );
	}
}

bool Comp( const pnt &A, const pnt &B ){
	if( (A^B) > 0+eps ) return 1;
	return 0;
}

void Graham_Scan(){
	for( int i=1; i<n; i++ )						//Find_Start
		if( pnts[i].Y < pnts[0].Y-eps ) swap( pnts[i], pnts[0] );
		else if( D_eq( pnts[i].Y, pnts[0].Y ) )
			if( pnts[i].X < pnts[0].X-eps ) swap( pnts[i], pnts[0] );

	pnt move= pnts[0];
	for( int i=0; i<n; i++ ) pnts[i]-= move;	//Move

	sort( pnts.begin()+1, pnts.end(), Comp );
	for( int i=2; i<(int)pnts.size(); i++ ){
		pnt A= pnts[i];
		if( D_eq( ((pnts[1]-pnts[0]) ^ (A-pnts[0])), 0 ) )
		{ pnts.erase( pnts.begin()+1 ); i--; }
		else break;
	}
	n= (int)pnts.size();

	vector<pnt> myStack( pnts.begin(), pnts.begin()+3 );  int top= 2;
	for( int i=3; i<n; i++ ){
		bool removed= false;
		do{
			removed= false;
			pnt A= myStack[ top-1 ];  pnt B= myStack[ top ];  pnt C= pnts[i];
			if( ( (B-A)^(C-B) )< 0-eps || D_eq(( (B-A)^(C-B) ), 0) )
			{ myStack.pop_back();  top--;  removed=true; }
		}while( removed == true );
		myStack.push_back( pnts[i] );	top++;
	}
	
	for( int i=0; i<(int)myStack.size(); i++ ) myStack[i]+= move;
	Out_put( myStack );
}

bool Complex_Comp( const pnt &A, const pnt &B ){
	if( A.X < B.X-eps ) return 1;
	if( D_eq( A.X, B.X ) && A.Y < B.Y-eps ) return 1;
	return 0;
}

void Out_put( vector<pnt> &CH ){
	sort( CH.begin(), CH.end(), Complex_Comp );
	cout << CH.size() << endl;
	for( int i=0; i<(int)CH.size(); i++ )
		cout << CH[i].X << " " << CH[i].Y << endl;
}

int main(){
	Input();
	Graham_Scan();
	return 0;
}
