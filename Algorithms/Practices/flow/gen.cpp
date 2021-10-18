#include<iostream>
#include<cstdlib>
using namespace std;
const int H=1010;
int a[H][H],n,m;
int main(){
	srand(time(0));
	int n=300;
	int m=(n*n/3);
	int x,y,z;
	cout<<n<<" "<<m<<endl;
	while(m>0){
		x=rand()%n+1;
		y=rand()%n+1;
		z=rand()%99+1;
		if(a[x][y]==0){
			a[x][y]=1;
			a[y][x]=1;
			cout<<x<<" "<<y<<" "<<z<<endl;
			m--;
		}
	}
	return 0;
}
