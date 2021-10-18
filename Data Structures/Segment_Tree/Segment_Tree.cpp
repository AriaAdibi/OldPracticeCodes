#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

int n;
const int MAX_N= 10* 1000* 1000;
int Arr[ MAX_N ];

int fSum[ MAX_N ];

void Input(){
	cin >> n;
	for( int i=1; i<=n; i++ ){
		cin >> Arr[i];
	}
}

void Preprocess_for_Sum(){
	for( int i=1; i<=n; i++ ){
		fSum[i]= fSum[i-1]+ Arr[i];
	}
}

struct Node{
	pii interval;
	int total;
	int rem_update;
	Node(){ total= 0; rem_update=0; interval= pii(0,0); }
	~Node(){}
};

Node Tree[ MAX_N ];

class Segment_Tree{
	public:
		Segment_Tree();
		~Segment_Tree();
		void Create_Tree( const int &ind, const int &from, const int &to );
		void Quary_Input();
		int Find_Sum( int ind, const int &from, const int &to );
		void Add( int ind, const int &from, const int &to, int x );
		int nQuary;
		vector< pair<string, pii> > Quary;
	private:
		int nVertex;
		int Parent( const int &ind )const{ return ind/2; }
		int Left( const int &ind )const{ return ind*2; }
		int Rigth( const int &ind )const{ return ind*2+1; }
};

Segment_Tree::Segment_Tree(){
	nVertex= nQuary= 0;
	Quary.clear(); memset( Tree, 0, sizeof Tree );
}

Segment_Tree::~Segment_Tree(){
	Quary.clear(); memset( Tree, 0, sizeof Tree );
}

void Segment_Tree::Create_Tree( const int &ind, const int &from, const int &to ){
	nVertex++;
	Tree[ ind ].total= fSum[to]- fSum[from-1];
	Tree[ ind ].interval= pii( from, to );

	if( from == to )return;
	int mid= (from+to)/2;
	Create_Tree( Left(ind), from, mid );
	Create_Tree( Rigth(ind), mid+1, to );
}

void Segment_Tree::Quary_Input(){
	cerr << "Please, enter number of quary that you want..." << endl;
	cin >> nQuary;
	cerr << "Please, enter your Quarys..." << endl;
	for( int i=0; i<nQuary; i++ ){
		string S; int x, y;
		cin >> S >> x >> y;
		Quary.push_back( pair<string, pii>(S, pii(x,y)) );
	}
}

int Segment_Tree::Find_Sum( int ind, const int &from, const int &to ){
	if( Tree[ind].interval == pii(from, to) )
		return Tree[ind].total;

	pii ind_interval= Tree[ind].interval;
	int mid= (ind_interval.X+ind_interval.Y)/2; int rem= Tree[ind].rem_update;

	Tree[ind].rem_update= 0;
	pii linterval= Tree[ Left(ind) ].interval; pii rinterval= Tree[ Rigth(ind) ].interval;
	Tree[ Left(ind) ].total+= rem*( linterval.Y -linterval.X +1 );
	Tree[ Left(ind) ].rem_update+= rem;
	Tree[ Rigth(ind) ].total+= rem*( rinterval.Y -rinterval.X +1 );
	Tree[ Rigth(ind) ].rem_update+= rem;

	if( to <= mid )
		return Find_Sum( Left(ind), from, to );
	else if( from >= mid+1 )
		return Find_Sum( Rigth(ind), from, to );
	else return (Find_Sum( Left(ind), from, mid )+ Find_Sum( Rigth(ind), mid+1, to ) );
}

void Segment_Tree::Add( int ind, const int &from, const int &to, int x ){
	Tree[ind].total+= x*(to -from +1);
	if( Tree[ind].interval == pii(from, to) ){
		Tree[ind].rem_update+= x;
		return;
	}

	pii ind_interval= Tree[ind].interval;
	int mid= (ind_interval.X+ ind_interval.Y)/2;
	if( to <= mid )
		Add( Left(ind), from, to, x );
	else if( from >= mid+1 )
		Add( Rigth(ind), from, to, x );
	else{
		Add( Left(ind), from, mid, x );
		Add( Rigth(ind), mid+1, to, x );
	}
}

void Begin_Process(){
	
	Segment_Tree my_STree;
	my_STree.Create_Tree( 1, 1, n );

	my_STree.Quary_Input();
	for( int i=0; i<my_STree.nQuary; i++ ){
		string S= my_STree.Quary[i].X;
		pii qinterval= my_STree.Quary[i].Y;
		if( S == "Find" )
			cout << my_STree.Find_Sum( 1, qinterval.X, qinterval.Y ) << endl;
		else	my_STree.Add( 1, qinterval.X, qinterval.Y, 1 );
	}
}

int main(){
	Input();
	Preprocess_for_Sum();
	Begin_Process();
	return 0;
}
