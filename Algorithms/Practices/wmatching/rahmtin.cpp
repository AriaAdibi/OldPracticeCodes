#include<iostream>
using namespace std;
const int H=1010;
int a[H][H],mark[H],match[H],u[H],v[H];
int counter=0,eps,n,nn,e;
int dfs(int x){
	mark[x]=1;
	for(int i=n+1;i<=nn;i++){
		if(mark[i]==0){
			if((u[x]+v[i-n]==a[x][i])){
				mark[i]=1;
				if(match[i]==0){
					match[x]=i;
					match[i]=x;
					return 1;
				}else{
					if(mark[match[i]]==0){
						if(dfs(match[i])==1){
							match[x]=i;
							match[i]=x;
							return 1;
						}
					}
				}
			}
		}
	}
	return 0;
}

int main(){
	scanf("%d%d",&n,&e);
	nn=2*n;
	for(int i=0;i<e;i++){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		y+=n;
		a[x][y]=w;
		a[y][x]=w;
	}
	int maxi;
	for(int i=1;i<=n;i++){
		maxi=0;
		for(int j=n+1;j<=nn;j++){
			maxi=max(maxi,a[i][j]);
		}
		u[i]=maxi;
	}
	while(counter<n){
		memset(mark,0,sizeof mark);
		for(int i=1;i<=n;i++){
			if(match[i]==0){
				if(dfs(i)){
					counter++;
					memset(mark,0,sizeof mark);
				}
			}
		}
		memset(mark,0,sizeof mark);
		for(int i=1;i<=n;i++){
			if(match[i]==0){
				dfs(i);
			}
		}
		eps=1000000000;
		for(int i=1;i<=n;i++){
			if(mark[i]==0){
				continue;
			}
			for(int j=n+1;j<=nn;j++){
				if(mark[j]==1){
					continue;
				}
				if(u[i]+v[j-n]-a[i][j]<eps){
					eps=u[i]+v[j-n]-a[i][j];
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(mark[i]==1){
				u[i]-=eps;
			}
		}
		for(int j=n+1;j<=nn;j++){
			if(mark[j]==1){
				v[j-n]+=eps;
			}
		}
	}
	int sum=0;
	counter=0;
	for(int i=1;i<=n;i++){
		if(a[i][match[i]]!=0){
			counter++;
			sum+=a[i][match[i]];
		}
	}
	cout<<counter<<endl;
	cout<<sum<<endl;
/*	for(int i=1;i<=n;i++){
		if(a[i][match[i]]!=0){
			cout<<i<<" "<<match[i]-n<<endl;
		}
	}*/
	return 0;
}
