#include<iostream>
#include<cstdlib>
using namespace std;
const int H=1010;
int a[H][H],n,m;
int main(){
	srand(time(0));
	int n=rand()%1000000;
	cout<<n<<endl;
	while(n>0){
		cout<<rand()%10000<<" ";
		n--;
		
	}
	cout<<endl;
	return 0;
}
