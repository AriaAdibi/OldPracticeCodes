#include<iostream>
#include<cstdlib>
using namespace std;
const int H=1010;
int a[H][H],n,m;
int main(){
	srand(time(0));
	int n=200;
	int m=rand()%((n*n)/3);
	int x,y,z;
	cout<<n<<" "<<m<<endl;
	while(m>0){
		x=rand()%n+1;
		y=rand()%n+1;
		z=rand()%1000+2;
		if(x!=y){			
			cout<<x<<" "<<y<<" "<<z<<endl;
			m--;
		}
	}
	return 0;
}
