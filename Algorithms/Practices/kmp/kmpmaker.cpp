#include<iostream>
#include<cstdlib>
using namespace std;
#define show(x) cerr<<#x<<" = "<<x<<endl;

int main(){
	srand(time(0));
	int n=1999999,m=3;
	cout<<n<<" "<<m<<endl;
	for(int i=0;i<n;i++){
		int x=rand()%10;
		char ch=x+'a';
		cout<<ch;
	}
	cout<<endl;
	for(int i=0;i<m;i++){
		int x=rand()%10;
		char ch=x+'a';
		cout<<ch;
	}
	cout<<endl;
	return 0;
}

