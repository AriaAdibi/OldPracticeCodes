#include<iostream>
using namespace std;
const int H=1100;
int c[H][H],n,m,good,edge[H][2],f[H][H],mark[H],flow;

int dfs(int x){
	if(x==n){
		return 1;
	}
	mark[x]=1;
	for(int i=1;i<=n;i++){
		if(c[x][i]-f[x][i]>=good){
			if(mark[i]==1){
				continue;
			}
			if(dfs(i)==1){
				f[x][i]+=good;
				f[i][x]-=good;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	scanf("%d%d",&n,&m);
	int x,y,z;
	good=1<<30;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		c[x][y]=z;
		edge[i][0]=x;
		edge[i][1]=y;
	}
	while(good>0){
		while(dfs(1)){
			memset(mark,0,sizeof mark);	
			flow+=good;
		}
		good/=2;
	}
	cout<<flow<<endl;
	for(int i=0;i<m;i++){
		cout<<f[edge[i][0]][edge[i][1]]<<endl;
	}
	return 0;
}
