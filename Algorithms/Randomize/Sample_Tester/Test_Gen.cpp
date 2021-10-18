#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int n;
const int MAX_N= 300* 1000;
bool Mark[ MAX_N ];
int Rand[ MAX_N ];

void Generate_Test(){
	srand( time(NULL) );
	n= rand()% MAX_N+ 100000;

	int num_gen= 0;
	do{
		int x= rand()% n+ 1;
		if( !Mark[x] ){
			Mark[x]= 1;
			Rand[ num_gen++ ]= x;
		}
	}while( num_gen < n ); 
}

void Out_put(){
	cout << n << endl;
	for( int i=0; i<n; i++ ){
		cout << Rand[i] << " ";
	}
	cout << endl;
}

int main(){
	Generate_Test();
	Out_put();
	return 0;
}
