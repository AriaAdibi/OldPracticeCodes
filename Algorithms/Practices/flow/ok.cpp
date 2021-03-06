#include<iostream>
using namespace std;
const int H=310;
int f[H][H],c[H][H],n,flo,e,edge[H*H][2],stack[H][3],m;
bool flag[H];
int mini;
int bfs(){	    
	int tail=1;
	flag[1]=1;
	stack[0][0]=1;
	stack[0][1]=10000000;
	int p;
	for(int head=0;head<tail;head++){
		int t=stack[head][0];
		for(int i=1;i<=n;i++){
			if(flag[i]==0 && c[t][i]-f[t][i]>0){
				p=min(c[t][i]-f[t][i],stack[head][1]);
				if(p>0){
					flag[i]=1;
					stack[tail][1]=p;
					stack[tail][2]=head;
					stack[tail++][0]=i;
					if(i==n){
						tail--;
						mini=stack[tail][1];
						while(tail!=0){
							int v = stack[tail][0];
							int pedar = stack[stack[tail][2]][0];
							f[pedar][v]+=mini;
							f[v][pedar]-=mini;
							tail=stack[tail][2];
						}
						return mini;
					}				
				}
			}
		}
	}				
	return 0;		
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		c[x][y]+=z;
		c[y][x]+=z;
		edge[i][0]=x;
		edge[i][1]=y;
	}
	int check=1;
	while(check==1){
		int x;
		x=bfs();
		flo+=x;
		if(x==0){
			check=0;
		}else{		
			memset(flag,0,sizeof flag);
		}
	}	
	cout<<flo<<endl;
	return 0;
}				
