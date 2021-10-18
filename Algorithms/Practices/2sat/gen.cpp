#include<iostream>
#include<cstdlib>
using namespace std;
const int H=1010;
int a[H][H],n,m;
int main(){
	srand(time(0));
	int n=2000;
	int m=30000;
	int x,y,z;
	cout<<n<<" "<<m<<endl;
	while(m>0){
		x=rand()%n+1;
		y=rand()%n+1;
		z=rand()%4;
		if(z==0){
			cout<<x<<" "<<y<<endl;
		}else if(z==1){
			cout<<-x<<" "<<-y<<endl;
		}else if (z==2){
			cout<<-x<<" "<<y<<endl;
		}else{
			cout<<x<<" "<<-y<<endl;
		}
		m--;
	}
	return 0;
}
