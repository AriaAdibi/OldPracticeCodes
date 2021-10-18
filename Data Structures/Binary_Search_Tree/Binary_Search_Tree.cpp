#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef pair<int, int> pii;

int n;
const int MAX_N= 100* 1000;
vector< pii > Quary;

void Input(){
	cerr << "Please enter number of Quary you want..." << endl;
	cin >> n;
	cerr << "NOW Please enter your quary in following format..." << endl;
	cerr << "1, 0: Show element in sorted order" << endl;
	cerr << "2, k: Search for element k" << endl;
	cerr << "3, 0: Minimum  " << endl;
	cerr << "4, 0: Maximum  " << endl;
	cerr << "5, x: Succesor of element x " << endl;
	cerr << "6, x: Insert x " << endl;
	cerr << "7, x: Delet x " << endl;

	for( int i=0, x, y; i<n; i++ ){
		cin >> x >> y;
		Quary.push_back( pii(x,y) );
	}
}

struct Node{
	int key;
	Node *rigth;
	Node *left;
	Node *par;
	Node();
	~Node(){}
};

Node::Node(){
	key= -1;
	rigth= NULL;
	left= NULL; 
	par= NULL;
}

class BST{
	public:
		BST(){ nNode=0; root= NULL; }
		~BST(){}
		void Inorder_Tree_Walk( Node *X ) const;
		Node * Tree_Search( Node *X, const int &val ) const;
		Node * Iterative_Tree_Search( const int &val ) const;
		Node * Tree_Minimum( Node *X ) const;
		Node * Tree_Maximum( Node *X ) const;
		Node * Tree_Succesor( Node *X ) const;
		void Tree_Insert( const int &val );
		void Tree_Delete( const int &val );
		void Delete_All_Nodes();
		Node *root;
	private:
		void Transplant( Node *X, Node *Y );
		int nNode;
};

void BST::Inorder_Tree_Walk( Node *X ) const{
	if( X != NULL ){
		Inorder_Tree_Walk( X->left );
		cout << X->key << " ";
		Inorder_Tree_Walk( X->rigth );
	}
}

Node * BST::Tree_Search( Node *X, const int &val ) const{
	if( X == NULL || X->key == val )
		return X;
	if( val < X->key )
		return Tree_Search( X->left, val );
	else return Tree_Search( X->rigth, val );
}

Node * BST::Iterative_Tree_Search( const int &val ) const{
	Node *X= root;
	while( X != NULL && X->key != val ){
		if( val < X->key )
			X= X->left;
		else X= X->rigth;
	}
	return X;
}

Node * BST::Tree_Minimum( Node *X ) const{
	while( X->left != NULL )
		X= X->left;
	return X;
}

Node * BST::Tree_Maximum( Node *X ) const{
	while( X->rigth != NULL )
		X= X->rigth;
	return X;
}

Node * BST::Tree_Succesor( Node *X )const{
	if( X->rigth != NULL )
		return Tree_Minimum( X->rigth );
	Node *Y= X->par;
	while( Y != NULL && Y->rigth == X ){
		X= Y;
		Y= X->par;
	}
	return Y;
}

void BST::Tree_Insert( const int &val ){
	nNode++;
	Node *Z= new Node;
	Z->key= val;
	Node *Y= NULL;
	Node *X= root;
	while( X != NULL ){
		Y= X;
		if( Z->key < X->key )
			X= X->left;
		else X= X->rigth;
	}
	Z->par= Y;
	if( Y==NULL )	//Tree was empty
		root= Z;
	else if (Z->key < Y->key)
		Y->left= Z;
	else Y->rigth = Z;
}

void BST::Transplant( Node *X, Node *Y ){
	if( X->par == NULL )
		root= Y;
	else if( X == (X->par)->left )
		(X->par)->left= Y;
	else (X->par)->rigth= Y;
	if( Y!=NULL )
		Y->par= X->par;
}

void BST::Tree_Delete( const int &val ){
	nNode--;
	Node *Z= Iterative_Tree_Search( val );
	if( Z->left == NULL )
		Transplant( Z, Z->rigth );
	else if ( Z->rigth == NULL )
		Transplant( Z, Z->left );
	else{
		Node *Y= Tree_Minimum( Z->rigth );
		if( Y->par != Z ){
			Transplant( Y, Y->rigth );
			Y->rigth = Z->rigth;
			(Y->rigth)->par= Y;
		}
		Transplant( Z, Y );
		Y->left= Z->left;
		(Y->left)->par= Y;
	}
	delete Z;
}

void BST::Delete_All_Nodes(){
	for( int val= 0; val < 100; val++ ){
		if( Iterative_Tree_Search( val ) != NULL )
			Tree_Delete( val );
	}
}

void Procces_Quarys(){
	BST my_BST;
	for( int i=0; i<n; i++ ){
		pii q= Quary[i];
		Node *X= NULL; int val=-1;
		switch( q.first ){
			case 1:		//"Inorder_Tree_Walk":
				my_BST.Inorder_Tree_Walk( my_BST.root );
				cerr << endl;
				break;
			case 2:		//"Tree_Search":
				val= q.second;
				X =my_BST.Iterative_Tree_Search( val );
				if( X != NULL )
					cerr << "your Value:: exist" << endl;
				else cerr << "your Value:: not exist" << endl;
				break;
			case 3:		//"Tree_minimum":
				X= my_BST.Tree_Minimum( my_BST.root );
				cerr << "Minimum is::" << X->key << endl;
				break;
			case 4:		//"Tree_Maximum":
				X= my_BST.Tree_Maximum( my_BST.root );
				cerr << "Maximum is::" << X->key << endl;
				break;
			case 5:		//"Tree_Succesor":
				val= q.second;
				X= my_BST.Iterative_Tree_Search( val );
				if( X == NULL )
					cerr << "error, the value you insert does not exist" << endl;
				X= my_BST.Tree_Succesor( X );
				cerr << "The Succesor of your value is::" << X->key << endl;
				break;
			case 6:		//"Tree_Insert":
				val= q.second;
				if( my_BST.Tree_Search( my_BST.root, val ) == NULL )
					cerr << "Your value is already exist" << endl;
				else{
					my_BST.Tree_Insert( val );
					cerr << "Your value is succesfully insert" << endl;
				}
				break;
			case 7:		//"Tree_Delete":
				val= q.second;
				if( my_BST.Tree_Search( my_BST.root, val ) == NULL )
					cerr << "Your value is already not exist" << endl;
				else {
					my_BST.Tree_Delete( val );
					cerr << "Your value is Succesfully deleted" << endl;
				}
				break;
			default:
				cerr << "Sorry, your quary not avable.." << endl;
				break;
		}
	}
	my_BST.Delete_All_Nodes();
}

int main(){
	Input();
	Procces_Quarys();
	return 0;
}
