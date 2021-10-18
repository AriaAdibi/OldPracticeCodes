#include<iostream>
#include<cstdlib>
using namespace std;
const int H=1010;
int a[H][H],n,m,deg[H];
int main(){
	srand(time(0));
	int n=990;
	int m=rand()%(n*n/3);
	int x,y;
	int outm=m;
	while(m>0){
		x=rand()%n+1;
		y=rand()%n+1;
		if(x==y){
			continue;
		}
		if(x>y){
			swap(x,y);
		}
		if(a[x][y]==0){
			a[x][y]=1;
			deg[x]++;
			deg[y]++;
			m--;
		}
	}
	int first=-1;
	for(int i=1;i<=n;i++){
		if(deg[i]%2==1){
			if(first==-1){
				first=i;
			}else{
				if(a[first][i]==1){
					a[first][i]=0;
					outm--;
				}else{
					outm++;
					a[first][i]=1;
				}
				first=-1;
			}
		}
	}
	cout<<n<<" "<<outm<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==1){
				cout<<i<<" "<<j<<endl;
			}
		}
	}						
	return 0;
}
