#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	srand(time(0));
	int n=rand()%1000000+1;
//	int n=rand()%10;
	cout<<n<<endl;
	while(n>0){
		n--;
		cout<<rand()%10000<<" ";
	}
	cout<<endl;
	return 0;
}
