#include <iostream>
#include <vector>

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
	vector<int> Left;
	vector<int> Rigth;

	for( int i=from; i<=mid; i++ ){
		Left.push_back( Arr[i] );
	}
	for( int j=mid+1; j<=to; j++ ){
		Rigth.push_back( Arr[j] );
	}
	Left.push_back( inf );
	Rigth.push_back( inf );

	int lLeft= (int)Left.size(), lRigth= (int)Rigth.size();
	for( int i=0, j=0; i<lLeft && j<lRigth; ){
		if( Left[i] <= Rigth[j] ){
			Arr[from-1 +i +j +1]= Left[i];
			i++;
		}
		else{
			Arr[from-1 +i +j +1]= Rigth[j];
			j++;
		}
		if( i==(lLeft-1) && j==(lRigth-1) ) break;
	}
}

void Merge_Sort( const int &from, const int &to ){
	if( to-from+1 <= 1){
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
	cerr << "Here is your Sorted sequence... " << endl;
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
