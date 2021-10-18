#include <iostream>

using namespace std;

int n;
const int MAX_N= 300* 1000;
int A[ MAX_N ];

void Input(){
	cin >> n;
	for( int i=0; i<n; i++ ){
		cin >> A[i];
	}
}

void Insertion_Sort(){
	//A[0] is already sorted
	for( int i=1; i<n; i++ ){
		int j=i;
		while( j>0 && A[j]<A[j-1] ){
			swap( A[j], A[j-1] );
			j--;
		}
	}
}

void Out_put(){
	for( int i=0; i<n; i++ ){
		cout << A[i] << " ";
	}
	cout << endl;
}

int main(){
	Input();
	Insertion_Sort();
	Out_put();
	return 0;
}
