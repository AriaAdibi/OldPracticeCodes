#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

#include "myClass.hpp"

int n;
vector<pdd> Q;

void Out_put( const vector<pdd> &CH );
void Input(){
	set<pdd> rQ;
	cin >> n;
	double x, y;
	for( int i=0; i<n; i++ ){
		cin >> x >> y;
		rQ.insert( pdd(y,x) );			//will remove repeated one and find lowest
	}
	for( set<pdd>::iterator it= rQ.begin(); it!= rQ.end(); it++ )
		Q.push_back( pdd(it->Y, it->X) );	//now in correct order
	n= (int)Q.size();
}

inline pdd Minus( const pdd &x, const pdd &y ){
	return pdd(x.X-y.X, x.Y- y.Y);
}

bool Sort_Comp( const pdd &x, const pdd &y ){
	double resCross= myVec( Minus(x, Q[0]) ) ^ myVec( Minus(y, Q[0]) );
	if( resCross >= 0+eps ) return 1;
	return 0;
}

void myUnique( vector<pdd> &Q ){
	for( int i=1; i<n-1; i++ ){
		myVec a( Minus(Q[i], Q[0]) );   myVec b( Minus(Q[i+1], Q[0]) );
		if( (a^b) == 0 ){
			if( a.Mag() >= b.Mag()+eps ) //not happening :D
				swap( Q[i], Q[i+1] );
			Q.erase( Q.begin()+i ); n--; i--;
		}
	}
}

void Graham_Scan(){
	sort( Q.begin()+ 1, Q.end(), Sort_Comp );
	myUnique( Q );

	if( n<=2 )
		cout << "Error: Your input is incorrect." << endl;

	vector<pdd> CH( Q.begin(), Q.begin()+3 );
	for( int i=3; i<n; i++ ){
		bool erased= false;
		do{
			erased= false;
			pdd P= Q[i];
			pdd B= CH.back();/*topCH*/  pdd A= CH[ CH.size()-2 ];/*nx_topCH*/
			myVec AB( Minus(B, A) );  myVec BP( Minus(P, B) );  myVec AP( Minus(P, A) );
			if( (AB ^ BP) < 0-eps )
			{ erased= true; CH.pop_back(); }
			else if( 0-eps<= (AB ^ BP) && (AB ^ BP) <= 0+eps )
				if( AB.Mag() <= AP.Mag()-eps )
				{ erased= true; CH.pop_back(); }
		}while( erased );
		CH.push_back( Q[i] );
	}

	Out_put( CH );
}

void  Out_put( const vector<pdd> &CH ){
	cout << fixed << setprecision(3);
	for( int i=0; i<(int)CH.size(); i++ )
		cout << CH[i].X << "  " << CH[i].Y << endl;
}

int main(){
	Input();
	Graham_Scan();
	return 0;
}
