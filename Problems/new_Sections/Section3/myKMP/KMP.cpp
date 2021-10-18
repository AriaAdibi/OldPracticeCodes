#include <iostream>
#include <vector>

using namespace std;

int n, m;
const int MAX_N= 1000;
const int MAX_M= 1000;
int S[ MAX_N ];
int W[ MAX_M ];

int nMatch= 0;
vector<int> End_W;

int nxt[ MAX_M ];

void Input(){
	cin >> n;   cin >> m;
	for( int i=0; i<n; i++ )
		cin >> S[i];
	for( int i=0; i<m; i++ )
		cin >> W[i];
}

void Find_nxt(){
	nxt[0]= 0;
	for( int i=1; i<m; i++ ){
		int j= nxt[i-1];
		while( W[j] != W[i] && j > 0 )
			j= nxt[j-1];

		if( !(j==0 && W[i] != W[0]) ) nxt[i]= j+1;
	}
	/**/
	for( int i=0; i<m; i++ )
		cerr << nxt[i] << " " ;
	cerr << endl;
	/**/
}

void KMP(){
	int Cur_l= 0;
	for( int i=0; i<n; i++ ){
		while( S[i] != W[ Cur_l ] && Cur_l > 0 )
			Cur_l= nxt[ Cur_l-1 ];
		if( !(Cur_l==0 && S[i]!= W[0]) )
			Cur_l++;
		if( Cur_l == m ){
			nMatch++;
			End_W.push_back( i );
		}
	}
}

void Out_put(){
	cout << nMatch << endl;
	for( int i=0; i<nMatch; i++ )
		cout << End_W[i]+1 << " ";
	cout << endl;
}

int main(){
	Input();
	Find_nxt();
	KMP();
	Out_put();
	return 0;
}
