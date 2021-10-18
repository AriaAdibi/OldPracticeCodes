#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int MAX_N= 100 * 1000;
const int MAX_TREE_SIZE= 20 * MAX_N;
const int OO= 1000 * 1000 * 1000 + 1;

int n, m;
int theArray[MAX_N];
int treeLastIndex= 0;
vector<int> theTree[MAX_TREE_SIZE];
vector<int> numLowInTree[MAX_TREE_SIZE];

int posArray[MAX_N];
int L[MAX_N/2+2];
int R[MAX_N/2+2];

void getTheArray(){
	for( int i=0; i<n; i++ )
		scanf("%d", &theArray[i]);
}

int findMedian( vector<int> v ){
	int mid= (v.size()-1)/2;
	nth_element( v.begin(), v.begin()+mid, v.end() );
	return v[mid];
}

void theMerge(int start, int end, int indexInTree){
	int mid= (start+end)/2;
	int i=0, j=0;
	for( ; i<mid-start+1; i++ )
		L[i]= posArray[start+i];
	L[i]= OO;
	for( ; j<end-mid; j++ )
		R[j]= posArray[mid+1+j];
	R[j]= OO;

	i=0; j=0;
	int numLow= 0;
	for( int k=start; k<=end; k++ ){
		if( L[i] <= R[j] ){
			posArray[k]= L[i++];
			numLow++;
		}
		else
			posArray[k]= R[j++];
		numLowInTree[indexInTree].push_back(numLow);
	}
}

void calculateNumLowInTree(int start, int end, int indexInTree){
	if( start==end )
		numLowInTree[indexInTree].push_back(1);
	else if( start < end ){
		int mid= (start+end)/2;
		calculateNumLowInTree(start, mid, 2*indexInTree);
		calculateNumLowInTree(mid+1, end, 2*indexInTree+1);
		theMerge(start, end, indexInTree);
	}
	/**
	else{
		cerr << "error occorred" << endl;
		exit(1);
	}/**/
}

void addTheSatelliteInfo(){
	vector<pii> v;	v.reserve(n);
	for( int i=0; i<n; i++ )
		v.push_back( pii(theArray[i], i) );
	sort(v.begin(), v.end());
	
	for( int i=0; i<n; i++ )
		posArray[i]= v[i].second;

	calculateNumLowInTree(0, n-1, 1);
}

void BuildTheTrees(){
	vector<int> v;
	v.reserve(n);
	//cerr << "entergin 4" << endl;
	for( int i=0; i<n; i++ )
		v.push_back(theArray[i]);
	theTree[1]= v;
	//cerr << "exiting 4" << endl;
	
//	cerr << "entering 3" << endl;
	treeLastIndex= 1;
	int index= 1;
	while( index<=treeLastIndex ){
		if( v.size() > 1 ){
			int median= findMedian(v);
			vector<int> v_low;	v_low.reserve(n);
			vector<int> v_high;	v_high.reserve(n);
			for( int i=0; i<(int)v.size(); i++ )
				if( v[i] <= median )
					v_low.push_back(v[i]);
				else
					v_high.push_back(v[i]);
			theTree[2*index]= v_low;
			theTree[2*index+1]= v_high;
			treeLastIndex= 2*index+1;
		}
		v= theTree[++index];
	}
	//cerr << "exiting 3" << endl;	

	//cerr << "entering 2" << endl;
	addTheSatelliteInfo();
	//cerr << "exiting 2" << endl;
}

void showTrees(){
	for( int i=0; i<=treeLastIndex; i++ ){
		cerr<< i << ":" << endl;
		vector<int> v= theTree[i];
		for( int j=0; j<(int)v.size(); j++ )
			cerr << v[j] << " ";
		cerr << endl;
		v= numLowInTree[i];
		for( int j=0; j<(int)v.size(); j++ )
			cerr << v[j] << " ";
		cerr << endl;
		cerr << "----------------" << endl;
	}
}

int answerTheQuery(int l, int r, int k, int indexInTree){
	if( theTree[indexInTree].size()==1 )
		return theTree[indexInTree][0];

	int left= l-1>-1 ? numLowInTree[indexInTree][l-1] : 0;
	int right= numLowInTree[indexInTree][r];

	int p= right - left;
	if( p >= (k+1) )
		return answerTheQuery(left, right-1, k, 2*indexInTree);
	else
		return answerTheQuery(l-left, r-right, k-p, 2*indexInTree+1);
}

int main(){
	cin >> n >> m;
	getTheArray();
	/**
	for( int i=0; i<n; i++ )
		cerr << theArray[i] << " ";
	cerr << endl;
	/**/
	//cerr << "entering 1" << endl;
	BuildTheTrees();
	//cerr << "exiting 1" << endl;
	//showTrees();
	int l, r, k;
	for( int i=0; i<m; i++ ){
		scanf("%d", &l);
		scanf("%d", &r);
		scanf("%d", &k);
		printf( "%d \n", answerTheQuery(l, r, k, 1) );
	}
	return 0;	
}
