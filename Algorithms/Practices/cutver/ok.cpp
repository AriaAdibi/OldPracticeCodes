#include<iostream>
#include<fstream>
using namespace std;
const int H=5050;
bool  a[H][H],mark[H],flag[H];
int dis[H],n,e;
int out[H],counter=0,root;
int dfs(int x){
	int mini=100000,check=0;
	mark[x]=1;
	for(int i=1;i<=n;i++){
		if(a[x][i]==true){
			if(mark[i]==false){
				if(x==root){
					check++;
				}
				dis[i]=dis[x]+1;
				int t=dfs(i);
				if(mini>t){
					mini=t;
				}
				if((t==dis[x])&&(flag[x]==0)&&(x!=root)){
					flag[x]=1;
					out[counter++]=x;
				}
			}	
		}
	}
	if(x==root){
		dis[x]=-1;
		if(check>1){
			out[counter++]=x;
		}
	}	
	int mim=1000000;
	for(int i=1;i<=n;i++){
		if(a[x][i]==1){
			mim=min(mim,dis[i]);
		}
	}
	mim=min(mim,mini);
	return mim;
}				
				

int main(){
	scanf("%d%d",&n,&e);
	for(int i=0;i<=n;i++){
		dis[i]=100000;
	}
	for(int i=0;i<e;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][y]=1;
		a[y][x]=1;
	}
	for(int i=1;i<=n;i++){
		if(mark[i]==0){
			dis[i]=0;
			root=i;
			dfs(i);
		}
	}
	sort(out,out+counter);
	counter=unique(out,out+counter)-out;
	cout<<counter<<endl;
	for(int i=0;i<counter;i++){
		cout<<out[i]<<" ";
	}	
	cout<<endl;
	return 0;
}				
