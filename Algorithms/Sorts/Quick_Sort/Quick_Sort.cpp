#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int n;
const int MAX_N= 10 * 1000;
int Arr[ MAX_N ];

void Input(){
	cin >> n;
	for( int i=0; i<n; i++ ){
		cin >> Arr[i];
	}
	srand( time(NULL) );
}

int Partition( const int &from, const int &to ){
	int pivot= rand()%(to-from+1)+ from;
	int pivot_val= Arr[ pivot ];
	swap( Arr[ pivot ], Arr[ to ] );

	int store_ind= from;
	for( int i=from; i<=to; i++ ){
		if( Arr[i] < pivot_val ){
			swap( Arr[i], Arr[store_ind] );
			store_ind++;
		}
	}

	swap( Arr[to], Arr[store_ind] );
	return store_ind;
}

void Quick_Sort( const int &from, const int &to ){
	if( to-from+1 <= 1 ){
		return;
	}
	else{
		int pivot= Partition( from, to );
		Quick_Sort( from, pivot-1 );
		Quick_Sort( pivot+1, to );
	}
}

void Out_put(){
	cerr << "Here is your Soreted sequence..." << endl;
	for( int i=0; i<n; i++ ){
		cout << Arr[i] << " ";
	}
	cout << endl;
}

int main(){
	Input();
	Quick_Sort( 0, n-1 );
	Out_put();
	return 0;
}
