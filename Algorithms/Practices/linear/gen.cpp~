#include<iostream>
#include<cstdlib>
using namespace std;
const int H=1010;
int a[H][H],n,m,p,counter;
int main(){
	srand(time(0));
	n=rand()%490+10;m=rand()%490+10,p=rand()%100+4;
	int check=0;
	for(int i=0;i<5000;i++){
		check=0;
		for(int j=2;j*j<=i;j++){
			if(i%j==0){
				check=1;
				break;
			}
		}
		if(check==0){
			counter++;
			if(counter==p){
				p=i;
				break;
			}
		}
	}
	cout<<n<<" "<<m<<" "<<p<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<rand()%p<<" ";
		}
		cout<<endl;
	}
	return 0;
}
