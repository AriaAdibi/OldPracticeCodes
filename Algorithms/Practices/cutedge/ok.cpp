#include<iostream>
using namespace std;
const int H=1010;
int n,e,out[H],a[H][H][2];
int dis[H],counter,deg[H],par[H],root=0;
bool mark[H];
int dfs(int x,int y){
	int mini=1000000;
	mark[x]=1;
	for(int i=0;i<deg[x];i++){
		int v=a[x][i][0];
		if(v==par[x]){
			continue;
		}
		if(mark[v]==0){
			dis[v]=dis[x]+1;
			par[v]=x;
			int t=dfs(v,a[x][i][1]);
			mini=min(mini,t);
		}else{
			mini=min(mini,dis[v]);
		}	
	}
	if((mini>=dis[x])&&(x!=root)){
		out[counter++]=y;
	}
	return mini;
}				


int main(){
	scanf("%d%d",&n,&e);
	for(int i=0;i<e;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][deg[x]][0]=y;
		a[y][deg[y]][0]=x;
		a[x][deg[x]++][1]=i;
		a[y][deg[y]++][1]=i;
	}
	for(int i=1;i<=n;i++){
		if(mark[i]==0){
			root=i;
			dfs(i,10000000);
		}
	}
	sort(out,out+counter);
	printf("%d\n",counter);
	for(int i=0;i<counter;i++){
		printf("%d ",out[i]+1);
	}
	printf("\n");
	return 0;
}			
