#include<iostream>
using namespace std;
const int H=500,inf=100000*10000;
int a[H][H],markb[H],markp[H],matchb[H],matchp[H],u[H],v[H],n,m;

int dfs(int x){
	markb[x]=1;
	for(int i=1;i<=n;i++){
		if(a[x][i]!=u[x]+v[i]){
			continue;
		}
		markp[i]=1;
		if(matchp[i]==0){
			matchp[i]=x;
			matchb[x]=i;
			return 1;
		}
		if(markb[matchp[i]]==1){
			continue;
		}
		if(dfs(matchp[i])==1){
			matchp[i]=x;
			matchb[x]=i;
			return 1;
		}
	}
	return 0;
}	


int main(){
	scanf("%d%d",&n,&m);
	int v1,v2,v3;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&v1,&v2,&v3);
		a[v1][v2]=v3;
		u[v1]=max(u[v1],v3);
	}	
	int counter=0;
	while(counter<n){
		memset(markb,0,sizeof markb);	
		memset(markp,0,sizeof markp);
		for(int i=1;i<=n;i++){
			if(matchb[i]!=0){
				continue;
			}
			if(dfs(i)==1){
				counter++;
				memset(markb,0,sizeof markb);
			}
		}
		memset(markb,0,sizeof markb);
		memset(markp,0,sizeof markp);
		for(int i=1;i<=n;i++){
			if(matchb[i]==0){
				dfs(i);
			}
		}
		int eps=inf;
		for(int i=1;i<=n;i++){
			if(markb[i]==0){
				continue;
			}
			for(int j=1;j<=n;j++){
				if(markp[j]==1){
					continue;
				}
				if(u[i]+v[j]-a[i][j]<eps){
					eps=u[i]+v[j]-a[i][j];
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(markb[i]==1){
				u[i]-=eps;
			}
		}
		for(int j=1;j<=n;j++){
			if(markp[j]==1){
				v[j]+=eps;
			}
		}
	}
	counter=0;
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i][matchb[i]];
		if(a[i][matchb[i]]!=0){
			counter++;
		}
	}
	cout<<counter<<endl<<sum<<endl;
	return 0;
}	
				
