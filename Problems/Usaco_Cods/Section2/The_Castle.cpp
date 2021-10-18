/*
ID: aria.a11
PROG: castle
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
#define X first
#define Y second

ifstream fin ( "castle.in" );
ofstream fout ( "castle.out" );

int n, m;
const int MAX_N= 60;
bool Walls[ MAX_N ][ MAX_N ][4];

int num_components= 0;
int max_Vcomponents= 0;
int Wcomponent[ MAX_N ][ MAX_N ];
vector<int> num_Vcomponent;

pii Moves[]= { pii(0,-1), pii(-1,0), pii(0,1), pii(1,0) };

int new_max_VC= 0;
pair<pii, int> desire_Wall;

void find_Walls( const int &x, const int &y, int val ){
	for( int i=0; i<4; i++ ){
		if( val%2 )
		{ Walls[x][y][i]= 1; }
		val/=2;
	}
}

void input(){
	fin >> m >> n;
	for( int i=1; i<=n; i++ ){
		for( int j=1, x; j<=m; j++ ){
			fin >> x;
			find_Walls( i, j, x );
		}
	}
}

void flood_fill(){
	int num_V= 0;
	int num_visited= 0;
	do{
		num_visited= 0;
		for( int i=1; i<=n; i++ ){
			for( int j=1; j<=m; j++ ){
				if( Wcomponent[i][j] == -1 ){
					num_V++;
					num_visited++;
					Wcomponent[i][j]= num_components;
					for( int k=0; k<4; k++ ){
						if( (i+Moves[k].X>=1) && (i+Moves[k].X<=n) && (j+Moves[k].Y>=1) && (j+Moves[k].Y<=m) ){
							if( Walls[i][j][k] == 0 && Wcomponent[ i+Moves[k].X ][ j+Moves[k].Y ] == -2 ){
								Wcomponent[ i+Moves[k].X ][ j+Moves[k].Y ]= -1;
							}
						}
					}
				}
			}
		}
	}while( num_visited > 0 );
	num_Vcomponent.push_back( num_V );
	max_Vcomponents= max( max_Vcomponents, num_V );
}

void find_components(){
	for( int i=1; i<=n; i++ )
	{ fill( Wcomponent[i]+1, Wcomponent[i]+m+1, -2 ); }

	num_Vcomponent.push_back( 0 );
	for( int i=1; i<=n; i++ ){
		for( int j=1; j<=m; j++ ){
			if( Wcomponent[i][j] == -2 ){
				num_components++;
				Wcomponent[i][j]= -1;
				flood_fill();	
			}
		}
	}
}

void find_desire_Wall(){
	for( int j=m; j>=1; j-- ){			// farthest from West
		for( int i=1; i<=n; i++ ){		// then farthest from South
			for( int k=2; k>=1; k-- ){ 	// then first N then E
				if( (i+Moves[k].X>=1) && (i+Moves[k].X<=n) && (j+Moves[k].Y>=1) && (j+Moves[k].Y<=m) ){
					if( Walls[i][j][k] == 1 && Wcomponent[i][j] != Wcomponent[ i+Moves[k].X ][ j+Moves[k].Y ] ){

						int C_ij= Wcomponent[i][j]; int C_nij= Wcomponent[ i+Moves[k].X ][ j+Moves[k].Y ];
						if( num_Vcomponent[ C_ij ]+ num_Vcomponent[ C_nij ] >= new_max_VC ){
							new_max_VC= num_Vcomponent[ C_ij ]+ num_Vcomponent[ C_nij ];
							desire_Wall= make_pair( pii(i,j), k );
						}
					}
				}
			}
		}
	}
}

void Out_put(){
	fout << num_components << endl;
	fout << max_Vcomponents << endl;
	fout << new_max_VC << endl;
	fout << desire_Wall.X.X << " " << desire_Wall.X.Y << " ";
	if( desire_Wall.Y == 2 )
	{ fout << "E" << endl; }
	else{ fout << "N" << endl; }
}

int main(){
	input();
	find_components();
	find_desire_Wall();
	Out_put();
	return 0;
}
