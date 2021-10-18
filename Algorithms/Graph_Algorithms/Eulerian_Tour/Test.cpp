#include <iostream>
#include <string>

using namespace std;

int main(){
	char mychar[]= {'a', 'b', 'c', 'f', 'g' };
	string Circuit( mychar, mychar+ 5 );
	string Extend; 
	Extend.push_back( 'd' ); Extend.push_back( 'e' );

	string a( Circuit.begin(), Circuit.begin()+2+1 );
	string b( Circuit.begin()+2+1, Circuit.end() );
	Circuit= a+ Extend+ b;	Extend.clear();

	cerr << Circuit << endl;

	return 0;
}
