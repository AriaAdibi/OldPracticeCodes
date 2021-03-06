#include<iostream>
using namespace std;
const int H=310;
int c[H][H],f[H][H],n,m,head,tail,stack[H],mini[H],par[H],glob,mark[H],flow;


int bfs(){
	head=0;memset(mark,0,sizeof mark);tail=0;
	stack[tail++]=1;par[1]=-1;mark[1]=1;mini[1]=100000000;
	int temp;
	while(head<tail){
		temp=stack[head];head++;
		for(int i=1;i<=n;i++){
			if(mark[i]==1 || c[temp][i]-f[temp][i]==0){
				continue;
			}
			mark[i]=1;
			par[i]=temp;
			stack[tail++]=i;
			mini[i]=min(mini[temp],c[temp][i]-f[temp][i]);
			if(i==n){
				glob=mini[n];
				flow+=glob;
				temp=n;
				while(par[temp]!=-1){
					f[par[temp]][temp]+=glob;
					f[temp][par[temp]]-=glob;
					temp=par[temp];
				}
				return 1;
			}
		}
	}
	return 0;
}
			
			
				
int main(){	
	scanf("%d%d",&n,&m);
	int x,y,z;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		c[x][y]=z;
	}
	while(bfs());
	cout<<flow<<endl;
}
