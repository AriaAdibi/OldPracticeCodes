#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print( vector< int > A ){
	cerr << "**************" << endl;
	for( int i=0; i<(int)A.size(); i++ )
		cerr << A[i] << " ";
	cerr << endl;
}

bool cmp( const int &x, const int &y ){
	return x > y;
}

int main(){
	int myints[]= { 10, 20, 20, 30, 40, 80, 70, 70, 70, 50, 50, 100 };
	vector< int > myvector( myints, myints+ 12);
	vector< int >::iterator it;
	print( myvector );

	vector< int > Sav_my_vector= myvector;
	it= unique( myvector.begin(), myvector.end() );
	print( myvector );
	myvector.resize( it- myvector.begin() );
	print( myvector );
	cerr << "NOW: " << endl;
	print( Sav_my_vector );
	it= unique( Sav_my_vector.begin(), Sav_my_vector.end(), cmp );
	Sav_my_vector.resize( it- Sav_my_vector.begin() );
	print( Sav_my_vector );
	return 0;
}
