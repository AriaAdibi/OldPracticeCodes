#include <iostream>
#include <cstring>

using namespace std;

const int inf= 1000* 1000* 1000;

int n;
const int MAX_N= 10* 1000;
int A[ MAX_N ];

void Input(){
	cin >> n;
	A[0]= -inf;
	for( int i=1; i<=n; i++ ){ 		//1base
		cin >> A[i];
	}
}

class Heap{
	public:
		Heap();
		~Heap(){};
		bool Is_empty() const{ return nNode==0; }
		void Add_Node( const int &val );
		int Extract_min();
		void Extend( const int &from, const int &to );
		void Show() const;
	private:
		int Parent( const int &ind ) const;
		int Left( const int &ind ) const;
		int Rigth( const int &ind ) const;
		void Bubble_up( int ind );
		void Bubble_down( const int &ind );
		int nNode;
		int arr[ MAX_N ];
};

Heap::Heap(){
	nNode= 0;
	memset( arr, 0, sizeof arr ); arr[0]= -inf;
}

int Heap::Parent( const int &ind ) const{
	return ind/2;
}

int Heap::Left( const int &ind ) const{
	return ind*2;
}

int Heap::Rigth( const int &ind ) const{
	return ind*2+1;
}

void Heap::Bubble_up( int ind ){
	while( arr[ Parent(ind) ] > arr[ ind ] ){
		swap( arr[ Parent(ind) ], arr[ ind ] );
		ind= Parent( ind );
	}
}

void Heap::Bubble_down( const int &ind ){
	int min_ind= ind; 
	int l_ind= Left( ind ); int r_ind= Rigth( ind );

	if( l_ind <= nNode && arr[ l_ind ] < arr[ min_ind ] ){
		min_ind= l_ind;
	}
	if( r_ind <= nNode && arr[ r_ind ] < arr[ min_ind ] ){
		min_ind= r_ind;
	}
	
	if( min_ind != ind ){
		swap( arr[ min_ind ], arr[ ind ] );
		Bubble_down( min_ind );
	}
}

void Heap::Add_Node( const int &val ){
	nNode++;
	arr[ nNode ]= val;
	Bubble_up( nNode );
}

int Heap::Extract_min(){
	int minimum= arr[1];
	arr[ 1 ]= arr[ nNode ];
	arr[ nNode-- ]= 0;
	Bubble_down( 1 );
	return minimum;
}

void Heap::Extend( const int &from, const int &to ){
	for( int i=from; i<=to; i++ ){
		Add_Node( A[i] );
	}
}

void Heap::Show() const{
	cerr << "Here is your Heap..." << endl;
	for( int i=1; i<=nNode; i++ ){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Heap_Sort(){
	Heap my_Heap;
	my_Heap.Extend( 1, n );
	my_Heap.Show();
	int i=1;
	while( !my_Heap.Is_empty() ){
		int minimum= my_Heap.Extract_min();
		A[ i++ ]= minimum;
	}
}

void Out_put(){
	cerr << "Here is your Sorted Sequence..." << endl;
	for( int i=1; i<=n; i++ ){
		cout << A[i] << " ";
	}
	cout << endl;
}

int main(){
	Input();
	Heap_Sort();
	Out_put();
	return 0;
}
