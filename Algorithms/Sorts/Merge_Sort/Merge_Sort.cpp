#include <iostream>

using namespace std;

int n;
const int MAX_N= 10* 1000;
const int inf= 1000* 1000* 1000;
int Arr[ MAX_N ];

void Input(){
	cin >> n;
	for( int i=0; i<n; i++ ){
		cin >> Arr[i];
	}
}

void Merge( const int &from, const int &mid, const int &to ){
	int Left[ (to -from +1)/2 +10 ];
	int Rigth[ (to -from +1)/2 +10 ];

	for( int i=0; i<(mid -from +1); i++ ){
		Left[i]= Arr[ i+from ];
	}
	for( int j=0; j<(to -mid); j++ ){
		Rigth[j]= Arr[ j +mid +1 ];
	}
	Left[ mid -from +1 ]= inf;
	Rigth[ to- mid ]= inf;
	for( int i=0, j=0; i<=(mid -from +1) && j<=(to -mid); ){
		if( Left[i] <= Rigth[j] ){
			Arr[from-1 +i +j +1]= Left[i];
			i++;
		}
		else{
			Arr[from-1 +i +j +1]= Rigth[j];
			j++;
		}
		if( i==(mid -from +1) && j==(to -mid) ) break;
	}
}

void Merge_Sort( const int &from, const int &to ){
	if( to-from+1 <= 1 ){
		return;
	}
	else{
		int mid= (from+ to)/2;
		Merge_Sort( from, mid );
		Merge_Sort( mid+1, to );
		Merge( from, mid, to );
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
	Merge_Sort( 0, n-1 );
	Out_put();
	return 0;
}
