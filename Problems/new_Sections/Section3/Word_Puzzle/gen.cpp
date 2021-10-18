#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ofstream fout ( "INPUT" );

int main(){
	fout << 500 << endl;
	for( int i=0; i<500; i++ )
		fout << string( 200, 'a' ) << endl;
	fout << string( 1000* 1000, 'a' ) << endl;
	return 0;
}
