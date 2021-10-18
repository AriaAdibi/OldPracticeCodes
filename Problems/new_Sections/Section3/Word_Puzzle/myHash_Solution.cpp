#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef unsigned long long ULL;

int nW;
vector<int> S;
vector< vector<int> > Word;

ULL ans= 0;
vector<ULL> myHashT;

void Convert_to_vector( const string &W ){
	vector<int> new_W;
	for( int j=0; j<(int)W.size(); j++ )
		new_W.push_back( W[j]-'a' );
	Word.push_back( new_W );
}

void Input(){
	ios::sync_with_stdio( false );
	cin >> nW;
	for( int i=0; i<nW; i++ ){
		string W;  cin >> W;
		Convert_to_vector( W );
	}
	string T;  cin >> T;
	for( int j=0; j<(int)T.size(); j++ )
		S.push_back( T[j]- 'a' );
}

void Find_myHashT( const ULL &b, const ULL &prime ){
	for( int i=0; i<nW; i++ ){
		ULL h= 0;
		for( int j=0; j<(int)Word[i].size(); j++ )
			h= ( (h*b) + Word[i][j] );
		myHashT.push_back( h%prime );
	}
}

void myHash_Solution(){
	ULL b= 97;  ULL prime= 1000* 1000* 1000* 10+ 97;
	Find_myHashT( b, prime );

	for( int i=0; i<nW; i++ ){
		int lenW= (int)Word[i].size();

		ULL Pb= 1;
		for( int j=0; j<lenW-1; j++ )
		{  Pb*= b; }

		ULL g= 0;
		for( int j=0; j<lenW; j++ )
			g= ( (g*b) + S[j] );
		if( (g%prime) == myHashT[i] ) ans++;

		for( int j=lenW; j<(int)S.size(); j++ ){
			ULL pg= g- (Pb*S[j-lenW]);
			g= ( (pg*b)+ S[j] );

			if( (g%prime) == myHashT[i] ) ans++;
		}
	}
}

void Out_put(){
	cout << ans << endl;
}

int main(){
	Input();
	myHash_Solution();
	Out_put();
	return 0;
}
