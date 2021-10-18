#include <iostream>

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

void Insertion_Sort(){
	for( int i=1; i<n; i++ ){
		int key= Arr[i];
		int j= i-1;
		while( j>=0 && Arr[j] > key ){
			Arr[j+1]= Arr[j];
			j--;
		}
		Arr[j+1]= key;
	}
}

void Out_put(){
	cerr << "Here is your Sorted sequence..." << endl;
	for( int i=0; i<n; i++ ){
		cout << Arr[i] << " ";
	}
	cout << endl;
}

int main(){
	Input();
	Insertion_Sort();
	Out_put();
	return 0;
}
