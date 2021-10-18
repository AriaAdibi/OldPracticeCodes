#include<iostream>

using namespace std;

int n;
const int MAX_val= 100* 1000;
const int MAX_N= 10* 1000;
int Arr[ MAX_N ];

int num_i[ MAX_val ];

void Input(){
	cin >> n;
	for( int i=0; i<n; i++ ){
		cin >> Arr[i];
	}
}

void Count_Sort(){
	for( int i=0; i<n; i++ ){
		num_i[ Arr[i] ]++;
	}
	int ptr= 0;
	for( int i=0; i<MAX_val; i++ ){
		for( int j=0; j<num_i[i]; j++ ){
			Arr[ ptr++ ]= i;
		}
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
	Count_Sort();
	Out_put();
	return 0;
}
