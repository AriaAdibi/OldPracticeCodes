#include<iostream>
#include<cstdlib>
using namespace std;
const int H=1010;
int a[H][H],n,m;
int main(){
	srand(time(0));
	int n=rand()%10000;
	int m=rand()%70000;
	int k=rand()%50+7;
	int x,y,z;
	cout<<n<<" "<<m<<" "<<k<<endl;
	for(int i=0;i<m;i++){
		if(rand()%5==0){
			cout<<"? "<<rand()%n+1<<endl;
		}else{
			x=rand()%n+1;
			if(x%4==0 || x%4==1){
				cout<<"* ";
			}else{
				cout<<"+ ";
			}
			x=rand()%n+1;y=rand()%n+1;
			if(x>y){
				swap(x,y);
			}
			z=rand()%100+1;
			cout<<x<<" "<<y<<" "<<z<<endl;
		}	
	}
	return 0;
}
