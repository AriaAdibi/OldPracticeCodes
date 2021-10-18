#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, V, E;
const int MAX_V= 5* 1000+ 100;
vector<int> pAdj_list[ MAX_V ];

vector<int> Per;

void Reset(){
	for( int i=1; i<=V; i++ ) pAdj_list[i].clear();
	Per.clear();
}

void Input(){
	cin >> V >> E;
	for( int i=1, v, u; i<=E; i++ ){
		cin >> v >> u;
		pAdj_list[v].push_back( u );
	}
}

bool Have_Spanning_Path(){
	for( int i=1; i<=V; i++ ) Per.push_back( i );
	bool have_Spath= false;
	do{
		have_Spath= true;
		for( int i=0; i<V-1; i++ ){
			int v= Per[i]; int next_v= Per[i+1];

			bool have_edge= 0;
			for( int j=0; j<(int)pAdj_list[v].size(); j++ ){
				int u= pAdj_list[v][j];
				if( u == next_v )
				{ have_edge= 1; break; }
			}
			if( !have_edge )
			{ have_Spath= false; break; }
		}
		if( have_Spath ) break;
	}while( next_permutation( Per.begin(), Per.end() ) );
	if( !have_Spath )
		return 0;
	return 1;
}

int main(){
	cin >> n;
	for( int i=1; i<=n; i++ ){
		Reset();
		Input();
		if( Have_Spanning_Path() )
			cout << "Good Luck President!" << endl;
		else cout << "Sorry President!" << endl;
	}
	return 0;
}
