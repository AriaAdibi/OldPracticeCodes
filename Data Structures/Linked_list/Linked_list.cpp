#include <iostream>

using namespace std;

struct node{
	int key;
	node *next;
	node(){ key=-1; next= NULL; }
	~node(){};
};
struct Head{
	int count;
	node *next;
	Head(){ count= 0; next= NULL; }
	~Head(){}
};

class Linked_list{
	public:
		void Display_AllNodes();
		void Add_front( int val );
		//Add_back( int val );
		void Remove_front();
		//Remove_back();
		///Add_ith( int val, int x );
		///remove_ith( int val, int x );
		Head head;
};

void Linked_list::Display_AllNodes(){
	if( head.count == 0 )
	{ cout << "error: there is nothing to show" << endl; }
	else{
		node *Cur_node= head.next;
		for( int i=0; i<head.count; i++ ){
			//cout << "node::" << i+1 << ": " << Cur_node->key << endl;
			cout << Cur_node->key << " ";
			Cur_node= Cur_node->next;
		}
		cout << endl;
	}
}

void Linked_list::Add_front( int val ){
	node *new_node;
	new_node= new node;
	head.count++;
	new_node->key= val; 
	new_node->next= head.next;
	head.next= new_node;
}

void Linked_list::Remove_front(){
	node *rem_node= head.next;
	head.count--;
	head.next= rem_node->next;
	delete rem_node;	
}

void Create_Linked_list(){
	Linked_list A;
	cerr << "Now display empty linked_list... " << endl;
	A.Display_AllNodes();
	cerr << "Now must have 10, 9, .., 1 ..." << endl;
	for( int i=1; i<=10; i++ ){
		A.Add_front( i );
	}
	cerr << "Now display linked_list... " << endl;
	A.Display_AllNodes();
	cerr << "Now remove 3first node... " << endl;
	for( int i=1; i<=3; i++ ){
		A.Remove_front();
	}
	cerr << "Now display linked_list... " << endl;
	A.Display_AllNodes();
	cerr << "Remain is easy :D I learnt it..." << endl;
}

int main(){
	Create_Linked_list();
	return 0;
}
