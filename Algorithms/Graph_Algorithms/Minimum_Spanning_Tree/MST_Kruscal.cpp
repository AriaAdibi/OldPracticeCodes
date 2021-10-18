#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

int n, m;
const int MAX_N= 10* 1000;
vector< pair<int, pii> > Edges;

struct Node{
	int parent;
	int rank;
	Node(){ parent= 0; rank= 0; }
	~Node(){}
};

Node Set[ MAX_N ];

int min_weight= 0;
vector<pii> MST;

void Input(){
	cin >> n >> m;
	for( int i= 1, v, u, w; i<=m; i++ ){
		cin >> v >> u >> w;
		Edges.push_back( pair<int, pii>(w, pii(v,u)) );
	}
}

void Make_Set( const int &ind ){
	Set[ind].parent= ind;
	Set[ind].rank= 0;
}

int Find_Set( const int &ind ){
	if( Set[ind].parent == ind )
		return ind;
	else{
		Set[ind].parent= Find_Set( Set[ind].parent );
		return Set[ind].parent;
	}
}

void Union( const int &ind_x, const int &ind_y ){
	int x_root= Find_Set( ind_x );
	int y_root= Find_Set( ind_y );
	if( Set[ x_root ].rank < Set[ y_root ].rank )
		Set[ x_root ].parent= y_root;
	else if( Set[ y_root ].rank < Set[ x_root ].rank )
		Set[ y_root ].parent= x_root;
	else{
		Set[ y_root ].parent= x_root;
		Set[ x_root ].rank++;
	}
}

void MST_Kruskal(){
	for( int i=1; i<=n; i++ ){
		Make_Set( i );
	}

	sort( Edges.begin(), Edges.end() );

	for( int i=0; i<m; i++ ){
		pii e= Edges[i].Y;	int w= Edges[i].X;
		if( Find_Set(e.X) != Find_Set(e.Y) ){
			min_weight+= w;
			MST.push_back( e );
			Union( e.X, e.Y );
		}
	}
}

void Out_put(){
	cerr << "Here is MST... " << endl;
	cerr << "The minimum weight is ... " << endl;
	cout << min_weight << endl;
	cerr << "Now, The tree is ... " << endl;
	for( int i=0; i<n-1; i++ ){
		cout << MST[i].X << " " << MST[i].Y << endl;
	}
}

int main(){
	Input();
	MST_Kruskal();
	Out_put();
	return 0;
}
