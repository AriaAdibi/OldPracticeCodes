#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int n;
const int MAX_N= 10* 1000;
bool Mark[ MAX_N ];

void Find_rand_Seq(){
	srand( time(NULL) );
	vector<int> Rand;
	int till_now= 0;
	do{
		int x= rand()%n+ 1;
		if( !Mark[x] ){
			Mark[x]= 1;
			till_now++;
			Rand.push_back( x );
		}
	}while( till_now < n );
	for( int i=0; i<n; i++ )
		cout << Rand[i] << " ";
	cout << endl;
}

int main(){
	cin >> n;
	Find_rand_Seq();
	return 0;
}
