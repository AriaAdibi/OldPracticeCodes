#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector< vector<bool> > Message;
vector< vector<bool> > Key_Word;

void Get_V( int r, vector< vector<bool> > &A ){
	bool x;
	for( int i=0, k; i<r; i++ ){
		cin >> k; vector<bool> B;
		for( int j=0; j<k; j++ )
		{ cin >> x; B.push_back( x ); }
		A.push_back( B );
	}
}

void Input(){
	cin >> n >> m;
	Get_V( n, Message );
	Get_V( m, Key_Word );
}

void mySolution(){
	for( int i=0; i<m; i++ ){
		int tans= 0;
		for( int j=0; j<n; j++ ){
			bool is_prefix= 1;
			int len= (int)min( Key_Word[i].size(), Message[j].size() );
			for( int k=0; k<len; k++ )
				if( Key_Word[i][k] != Message[j][k] )
				{ is_prefix= 0; break; }
			if( is_prefix ) tans++;
		}
		cout << tans << endl;
	}
}

int main(){
	Input();
	mySolution();
	return 0;
}
