#include <iostream>

using namespace std;

int n, m;
const int MAX_N= 50+ 2;
int M[ MAX_N ][ MAX_N ];

int vrow[ MAX_N ][ MAX_N ][ MAX_N ];
int vcol[ MAX_N ][ MAX_N ][ MAX_N ];

const int inf= 1000* 1000* 1000;
int d[ MAX_N ][ MAX_N ][ MAX_N ][ MAX_N ][ 4 ];

void Input(){
	cin >> n >> m;
	for( int i=0; i<n; i++ )
		for( int j=0; j<m; j++ )
			cin >> M[i][j];
}

void Preprocess(){
	for( int i=0; i<n; i++ )
		for( int j1=0; j1<m; j1++ )
			for( int j2= j1; j2<m; j2++ )
				if( j1==j2 )
					vrow[i][j1][j2]= M[i][j2];
				else vrow[i][j1][j2]= vrow[i][j1][j2-1]+ M[i][j2];
	for( int j=0; j<m; j++ )
		for( int i1=0; i1<n; i1++ )
			for( int i2=i1; i2<n; i2++ )
				if( i1==i2 )
					vcol[j][i1][i2]= M[i2][j];
				else vcol[j][i1][i2]= vcol[j][i1][i2-1]+ M[i2][j];
}

void Find_d( const int &i1, const int &i2, const int &j1, const int &j2, const int &r ){
	d[i1][i2][j1][j2][r]= -inf;	//no intial for j needed!!!!
	if( r==0 )
		for( int j=j1; j<=j2; j++ )
			d[i1][i2][j1][j2][r]= 
				max( d[i1][i2][j1][j2][r], max( vrow[i1][j1][j], vrow[i1][j1][j]+ d[i1+1][i2][j1][j][ (r+1)%4 ] ) );
	if( r==1 )
		for( int i=i1; i<=i2; i++ )
			d[i1][i2][j1][j2][r]=
				max( d[i1][i2][j1][j2][r], max( vcol[j2][i1][i], vcol[j2][i1][i]+ d[i1][i][j1][j2-1][ (r+1)%4 ] ) );
	if( r==2 )
		for( int j=j2; j>=j1; j-- )
			d[i1][i2][j1][j2][r]=
				max( d[i1][i2][j1][j2][r], max( vrow[i2][j][j2], vrow[i2][j][j2]+ d[i1][i2-1][j][j2][ (r+1)%4 ] ) );
	if( r==3 )
		for( int i=i2; i>=i1; i-- )
			d[i1][i2][j1][j2][r]=
				max( d[i1][i2][j1][j2][r], max( vcol[j1][i][i2], vcol[j1][i][i2]+ d[i][i2][j1+1][j2][ (r+1)%4 ] ) );
}

void Dynamic_Solution(){
	Preprocess();
	for( int i=0; i<n; i++ )
		for( int j=0; j<m; j++ )
			for( int r=0; r<4; r++ )
				d[i][i][j][j][r] = M[i][j];	//initialize
	for( int leni= 0; leni<n; leni++ )
		for( int i1=0; i1<n-leni; i1++ )
			for( int lenj=0; lenj<m; lenj++ )
				for( int j1=0; j1<m-lenj; j1++ )
					for( int r=0; r<4; r++ )
						if( leni != 0 || lenj != 0 )
							Find_d( i1, i1+leni, j1, j1+lenj, r );
}

void Out_put(){
	int ans= 0;
	for( int i=0; i<n; i++ ) //r= 0
		ans= max( ans, d[i][n-1][0][m-1][0] );
	for( int j=0; j<m; j++ ) //r= 1
		ans= max( ans, d[0][n-1][0][j][1] );
	for( int i=0; i<n; i++ ) //r= 2
		ans= max( ans, d[0][i][0][m-1][2] );
	for( int j=0; j<m; j++ ) //r= 3
		ans= max( ans, d[0][n-1][j][m-1][3] );

	if( ans < 0 ) cout << 0 << endl;
	else cout << ans << endl;
}	

int main(){
	Input();
	Dynamic_Solution();
	Out_put();
	return 0;
}
