#include<iostream>
using namespace std;
const int H=510;
int a[H][H],mod[H],n,m,p,b[H][H];

int main(){
	scanf("%d%d%p",&n,&m,&p);
	for(int i=0;i<n;i++){
		b[i][i]=1;
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<p;i++){
		for(int j=1;j<p;j++){
			if((i*j)%p==1){
				mod[i]=j;
				break;
			}
		}
	}
	int col=0,row=0;
	for(;col<m;col++){
		for(int i=row;i<=n;i++){
			if(a[i][col]!=0){
				myswap(i,row);
				int x=mod[a[row][col]];
				for(int j=0;j<=m;j++){
					a[row][j]*=x;
					b[row][j]*=x;
					a[row][j]%=p;
					b[row][j]%=p;
				}
				for(int j=0;j<n;j++){
					if(i==j){
						continue;
					}
					x=mod[a[j][col]];
					for(int k=0;k<=m;k++){
						a[j][k]-=a[row][k]*k;
						b[j][k]-=a[row][k]*k;
						a[j][k]+=100*p;
						b[j][k]+=100*p;
						a[j][k]%=p;
						b[j][k]%=p;
					}
				}
				row++;
				break;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=m;j++){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}	
