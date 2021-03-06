#include<iostream>
using namespace std;

const int H=400+10;
int INF;
int c[H][H],f[H][H],mark[H];
int flow,n,m,last,first,glob;
int edge[10000+10][3];
int dfs(int x,int y){
	if(x==n){
		flow+=y;
		glob=y;
		return 1;
	}
	mark[x]=1;
	for(int i=1;i<=n;i++){
		int temp=c[x][i]-f[x][i];
		if(temp<INF || mark[i]==1){
			continue;
		}
		temp=min(INF,y);
		if(dfs(i,temp)==1){
			f[x][i]+=glob;
			f[i][x]-=glob;
			return 1;
		}
	}
	return 0;
}

int main(){
	{
		int x,y,z;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&x,&y,&z);
			c[x][y]+=z;
			c[y][x]+=z;
	//		edge[i][0]=x;
	//		edge[i][1]=y;
	//		edge[i][2]=z;
		}
	}
	INF=1<<30;
	while(INF>0){
		while(dfs(first,INF)==1){
			memset(mark,0,sizeof mark);
		}
		INF/=2;
		memset(mark,0,sizeof mark);
	}
	cout<<flow<<endl;
/*	int x,y,z;
	for(int i=0;i<m;i++){
		x=edge[i][0];y=edge[i][1];z=edge[i][2];
		if(f[x][y]>z){
			f[x][y]-=z;
			cout<<z<<endl;
		}else{
			cout<<f[x][y]<<endl;
			f[x][y]=0;
		}
	}
*/	return 0;
}
