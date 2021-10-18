#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector< vector<bool> > Message;
vector< vector<bool> > Key_Word;

struct Node{
	Node *L, *R;
	int is_end;
	int nEnd;
	Node(){ L= NULL; R= NULL; is_end= 0; nEnd= 0; }
	~Node(){}
};

Node *root= new Node;
vector<int> Ans;

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
	Ans.resize( m, 0 );
}

void Create_Tries(){
	for( int i=0; i<(int)Message.size(); i++ ){
		int k=0; Node *x= root;
		while( k< (int)Message[i].size() ){
			if( Message[i][k]==0 )
				if( x->L == NULL ) break;
				else { x= x->L; k++; }
			else
				if( x->R == NULL ) break;
				else { x= x->R; k++; }
		}

		for( int j=k; j<(int)Message[i].size(); j++ )
			if( Message[i][j] == 0 )
			{ x->L= new Node; x= x->L; }
			else
			{ x->R= new Node; x= x->R; }
		x->is_end++;
	}
}

int nEnd_under_X( Node *x ){
	if( x->is_end ) x->nEnd+= x->is_end;
	if( x->L != NULL ) x->nEnd+= nEnd_under_X( x->L );
	if( x->R != NULL ) x->nEnd+= nEnd_under_X( x->R );
	return x->nEnd;
}

void Delete_Tries( Node *x ){
	if( x->L != NULL ) Delete_Tries( x->L );
	if( x->R != NULL ) Delete_Tries( x->R );
	delete x;
}

void myTries_Solution(){
	Create_Tries();
	nEnd_under_X( root );
	for( int i=0; i<(int)Key_Word.size(); i++ ){
		int k=0; Node *x= root; bool are_we_still_in= 1;
		while( k< (int)Key_Word[i].size() ){
			if( Key_Word[i][k] == 0 )
				if( x->L == NULL ) 
				{ are_we_still_in= 0; break; }
				else
				{ x= x->L; k++; if( x->is_end ) Ans[i]+= x->is_end; }
			else
				if( x->R == NULL )
				{ are_we_still_in= 0; break; }
				else
				{ x= x->R; k++; if( x->is_end ) Ans[i]+= x->is_end; }	
		}
		if( are_we_still_in ){
			Ans[i]+= x->nEnd;
			if( x->is_end ) Ans[i]-= x->is_end;
		}
	}
	Delete_Tries( root );
}

void Out_put(){
	for( int i=0; i<m; i++ )
		cout << Ans[i] << endl;
}

int main(){
	Input();
	myTries_Solution();
	Out_put();
	return 0;
}
