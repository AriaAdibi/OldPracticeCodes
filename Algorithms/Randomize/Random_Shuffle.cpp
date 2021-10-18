#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int n;
const int MAX_N= 10* 1000;
int Arr[ MAX_N ];

void Input(){
	cin >> n;
	for( int i=0; i<n; i++ ){
		cin >> Arr[i];
	}
}

void Random_Shuffle(){
	srand( time(NULL) );
	for( int i=0; i<n; i++ ){
		int r= rand()% (n-i)+ i;
		swap( Arr[i], Arr[r] );
	}
}

void Out_put(){
	cerr << "Here is randomly input" << endl;
	for( int i=0; i<n; i++ ){
		cout << Arr[i] << " "; 
	}
	cout << endl;
}

int main(){
	Input();
	Random_Shuffle();
	Out_put();
	return 0;
}
