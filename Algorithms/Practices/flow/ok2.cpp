#include<iostream>
using namespace std;
const int H=310;
int f[H][H],c[H][H],n,flo,e,edge[2][H*H];
bool mark[H][H],flag[H];
int dfs(int x,int mini){
	flag[x]=true;
	if(x==n){
		flo+=mini;
		return mini;
	}	    
	for(int i=1;i<=n;i++){
		if(flag[i]==0){
			int t=min(c[x][i]-f[x][i],mini);
			if(t==0){
				continue;
			}	
			int p=dfs(i,t);
			f[x][i]+=p;
			f[i][x]-=p;
			if(p>0){
				return p;
			}	
		}
	}
	return 0;		
}

int main(){
	cin>>n>>e;
	for(int i=0;i<e;i++){
		int x,y,z;
		cin>>x>>y>>z;
		c[x][y]+=z;
		mark[x][y]=1;
		edge[0][i]=x;
		edge[1][i]=y;
	}
	int check=1;
	while(check==1){
		int x;
		x=dfs(1,1000000);
		if(x==0){
			check=0;
		}else{		
			memset(flag,0,sizeof flag);
		}
	}	
	cout<<flo<<endl;
	return 0;
}				
