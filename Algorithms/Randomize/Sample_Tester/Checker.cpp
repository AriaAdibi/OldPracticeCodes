#include <iostream>
#include <algorithm>

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

void Sort(){
	sort( A+0, A+n );
}

void Out_put(){
	for( int i=0; i<n; i++ ){
		cout << A[i] << " ";
	}
	cout << endl;
}

int main(){
	Input();
	Sort();
	Out_put();
	return 0;
}
