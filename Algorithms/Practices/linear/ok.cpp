#include<iostream>
using namespace std;
const int H=510;
int n,m,mod[H*10],p,row,col;
int paye[H],counter;
int a[H][H];
void myswap(int x,int y){
	int z;
	for(int i=0;i<m+1;i++){
		z=a[x][i];
		a[x][i]=a[y][i];
		a[y][i]=z;
	}	
}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for(int i=0;i<n;i++){
		for(int j=0;j<m+1;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<p;i++){
		for(int j=0;j<p;j++){
			if((i*j)%p==1){
				mod[i]=j;
				break;
			}
		}
	}
	for (;col < m ;++col){
		for(int i=row;i<=n;i++){
			if(a[i][col]>0){
				myswap(row,i);
				int x=mod[a[row][col]];
				for(int j=0;j<m+1;j++){
					a[row][j]*=x;
					a[row][j]%=p;
				}
				for(int j=0;j<n;j++){
					if(j==row){
						continue;
					}
					int x=a[j][col];
					for(int k=0;k<m+1;k++){
						a[j][k]-=((x*a[row][k])%p);
						a[j][k]=a[j][k]+10*p;
						a[j][k]%=p;
					}
				}
				paye[counter++]=col;
				row++;
				break;
			}
		}
	}
	for(int i=row;i<n;i++){
		if(a[i][m]!=0){
			cout<<"bad"<<endl;
			for(int i=0;i<counter;i++){
				cout<<paye[i]+1<<" ";
			}
			cout<<endl;
			return 0;
		}
	}	
	cout<<"good "<<endl;
	for(int i=0;i<m;i++){
		cout<<a[i][m]<<" ";
	}
	cout<<endl;
	for(int i=0;i<counter;i++){
		cout<<paye[i]+1<<" ";
	}
	cout<<endl;
	return 0;
}

