#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

long long n;
int ndig;
vector<int> Dig;

const int MAX_l= (1<<17)+ 1000;
vector<int> O;
int n1[ MAX_l ];
vector<int> p1[ MAX_l ];

const int MAX_rem= 20;
bool d[MAX_rem][ MAX_l ];
pii Update_by[MAX_rem][ MAX_l ];

void Input(){
	cin >> n;
}

void Insert_to_Dig(){
	long long sav_n= n;
	while( n>0 )
	{ Dig.push_back( n%10 ); n/=10; };
	n= sav_n;
	ndig= (int)Dig.size();
}

void Find_n1(){
	int lim= 1<<ndig;
	for( int l=0; l<lim; l++ ){
		O.push_back( l );
		for( int r=0; r<ndig; r++ ){
			if( (1<<r) & l ){
				n1[l]++;
				p1[l].push_back( r );
			}
		}
	}
}

bool Comp( const int &x, const int &y ){
	if( n1[x]< n1[y] ) return 1;
	else return 0;
}

int mod( const int &prev_rem, const int &tndig, const int &ind ){
	int r= 1;
	for( int i=1; i<tndig; i++ ){ r*=10; r%=17; }

	int dig= Dig[ ind ];
	int rem= prev_rem-( (dig*r)%17 );

	while( rem < 0 ) rem+= 17;
	return rem;
}

void Dynamic_Solution(){
	if( n==1e17 ) return;
	Find_n1();
	sort( O.begin(), O.end(), Comp );
	d[0][0]= 1;	// j=rem, i..bit
	for( int i=1; i<(int)O.size(); i++ ){
		for( int j=0; j<17; j++ ){
			for( int k=0; k<p1[ O[i] ].size(); k++ ){
				int r= p1[ O[i] ][k];
				if( n1[ O[i] ] > 1 || Dig[r] != 0 ){
					int rem= mod( j, n1[ O[i] ], r );
					d[j][ O[i] ]= d[ rem ][ O[i]-(1<<r) ];
					if( d[j][ O[i] ] == 1 )
					{ Update_by[j][ O[i] ]= pii(rem, r); break; }
				}
			}
		}
	}
}

void Out_put(){
	int l= (1<<ndig)-1;
	if( !d[0][l] || n==1e17 )
		cout << -1 << endl;
	else{
		int rem= 0;
		while( l!=0 ){
			int r= Update_by[rem][l].Y;
			rem= Update_by[rem][l].X;
			l-= (1<<r);
			cout << Dig[r];
		}
		cout << endl;
	}
}

int main(){
	Input();
	Insert_to_Dig();
	Dynamic_Solution();
	Out_put();
	return 0;
}
