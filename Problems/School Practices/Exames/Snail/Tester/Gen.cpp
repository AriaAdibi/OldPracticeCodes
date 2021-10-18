#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_N= 50;
const int MAX_V= 200* 1000;
int M[ MAX_N ][ MAX_N ];

void Generate_Matrix(){
	srand( time(NULL) );
	int n= rand()%MAX_N+ 1;
	int m= rand()%MAX_N+ 1;
	for( int i=0; i<n; i++ )
		for( int j=0; j<m; j++ ){
			int x= rand()%(2*MAX_V+1);
			x-= (MAX_V+1);
			M[i][j]= x;
		}
	//Out_put
	cout << n << " " << m << endl;
	for( int i=0; i<n; i++, cout << endl )
		for( int j=0; j<m; j++ )
			cout << M[i][j] << " ";
}

int main(){
	Generate_Matrix();
	return 0;
}
