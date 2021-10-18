#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
const int MAX_N= 100* 1000;
int Seq[ MAX_N ];

int L= 0;
const int inf= 1000* 1000* 1000;	//inf= NIL
int M[ MAX_N ];				// store ind min number such that we have IS with [] lengh
int Par[ MAX_N ];

#define Show( X ) cerr << #X << "= " << X << " "

void Input(){
	cin >> n;
	Seq[0]= -inf;			//Smallest val
	for( int i=1; i<=n; i++ ){
		cin >> Seq[i];
	}
}

int Binary_Search( const int &len_st, const int &len_en, const int &val ){
	if( len_en- len_st+1 <= 2 ){
		if( Seq[ M[ len_en ] ] <= val )
			return len_en;
		else return len_st;
	}
	else{
		int mid= (len_st+len_en)/2;
		if( Seq[ M[mid] ] <= val )
			return Binary_Search( mid, len_en, val );
		else return Binary_Search( len_st, mid-1, val );
	}
}

void Find_LIS(){
	
	fill( M, M+n, inf );	M[0]= 0;
	for( int i=1; i<=n; i++ ){
		int max_plen= Binary_Search( 0, L, Seq[ i ] );
		Par[i]= M[ max_plen ];
		if( max_plen == L || Seq[i]< Seq[ M[ max_plen+1 ] ] ){
			M[ max_plen+1 ]= i;
			L= max( L, max_plen+1 );
		}
	}
}

void Out_put(){
	cerr << "Here is the length... " << endl;
	cout << L << endl;
	cerr << "Here is the Sequence... " << endl;

	vector<int> ans;
	for( int i=0, ind= M[L]; i<L; i++ ){
		ans.push_back( Seq[ind] ); 
		ind= Par[ind];
	}
	reverse( ans.begin(), ans.end() );
	for( int i=0; i<L; i++ )
		cout << ans[i] << " ";
	cout << endl;
}

int main(){
	Input();
	Find_LIS();
	Out_put();
	return 0;
}
