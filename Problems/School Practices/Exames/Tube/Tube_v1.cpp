#include <iostream>

using namespace std;

int n, k;
const int MAX_N= 1000+ 10;
long long A[ MAX_N ][ MAX_N ];

const int MAX_B= 11+ 1;
int B[ MAX_B ];

long long brSum[ MAX_B ][ MAX_N ][ MAX_N ];
long long One_qSum[ MAX_N ][ MAX_N ];

long long bqcSum[ MAX_B ][ MAX_N ][ MAX_N ];
long long q_qSum[ MAX_N ][ MAX_N ];

long long Ans[ MAX_N ][ MAX_N ];

void Input(){
	cin >> n >> k;
	for( int i=0; i<n; i++ )
		for( int j=0; j<n; j++ )
			cin >> A[i][j];
}

void Find_brSum(){
	int q= 2*k+ 1;
	for( int i=0; i<n; i++ )		//initialize
		for( int j=0; j<n; j++ )
			brSum[0][i][j]= A[i][j];
	for( int b=1; b<MAX_B; b++ )
		if( B[b] <= q )
			for( int i=0; i<n; i++ )
				for( int j=0; j<n; j++ )
					brSum[b][i][j]= brSum[b-1][i][j] +brSum[b-1][i][ (j +B[b-1])% n ];
}

void Find_One_qSum(){
	Find_brSum();
	for( int i=0; i<n; i++ )
		for( int j=0; j<n; j++ ){
			int q= 2*k +1; int tj= j;
			for( int b=MAX_B-1; b>=0; b-- )
				if( q >= B[b] ){
					One_qSum[i][j]+= brSum[b][i][tj];
					tj= (tj +B[b]) %n;
					q-= B[b];
				}
					
		}
}

void Find_bqcSum(){
	int q= 2*k+ 1;
	for( int i=0; i<n; i++ )		//initialize
		for( int j=0; j<n; j++ )
			bqcSum[0][i][j]= One_qSum[i][j];
	for( int b=1; b<MAX_B; b++ )
		if( B[b] <= q )
			for( int i=0; i<n; i++ )
				for( int j=0; j<n; j++ )
					bqcSum[b][i][j]= bqcSum[b-1][i][j]+ bqcSum[b-1][ (i+B[b-1])%n ][j];
}

void Find_q_qSum(){
	Find_bqcSum();
	for( int i=0; i<n; i++ )
		for( int j=0; j<n; j++ ){
			int q= 2*k+ 1; int ti= i;
			for( int b= MAX_B- 1; b>=0; b-- )
				if( q >= B[b] ){
					q_qSum[i][j]+= bqcSum[b][ti][j];
					ti= (ti+ B[b])%n;
					q-= B[b];
				}
		}
}

void mybSolution(){
	B[0]= 1;
	for( int i=1; i<MAX_B; i++ ) B[i]= 2*B[i-1];
	Find_One_qSum();
	Find_q_qSum();
}

void Out_put(){
	for( int i=0; i<n; i++ )
		for( int j=0; j<n; j++ )
			Ans[ (i+k)%n ][ (j+k)%n ]= q_qSum[i][j];
	for( int i=0; i<n; i++ ){
		for( int j=0; j<n; j++ )
			cout << Ans[i][j] << " ";
		cout << endl;
	}
}

int main(){
	Input();
	mybSolution();
	Out_put();
	return 0;
}
