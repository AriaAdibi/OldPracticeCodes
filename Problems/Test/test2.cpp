#include <iostream>

using namespace std;

int main(){
	bool my_mark[ 20 ]= {false};
	for( int i=0; i<20; i++ ){
		cerr << my_mark[i] << " ";
	}
	cerr << endl;
	return 0;
}
