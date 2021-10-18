#include<iostream>
using namespace std;
const int H=2002;
int match[H],a[H][H],deg[H],counter=0,n,m,e;
bool mark[H];

int dfs(int x){
	mark[x]=true;
	for(int i=0;i<deg[x];i++){
		if(mark[a[x][i]]==false){
			mark[a[x][i]]=1;
			if(match[a[x][i]]==0){
				counter++;
				match[x]=a[x][i];
				match[a[x][i]]=x;
				return 1;
			}else{
				if(dfs(match[a[x][i]])==1){
					match[x]=a[x][i];
					match[a[x][i]]=x;
					return 1;
				}
			}
		}
	}
	return 0;					
}
int main(){
	scanf("%d%d%d",&n,&m,&e);
	for(int i=0;i<e;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		y+=n;
		a[x][deg[x]++]=y;
		a[y][deg[y]++]=x;
	}
	for(int i=1;i<=n;i++){
		dfs(i);
		memset(mark,0,sizeof mark);	
	}
	cout<<counter<<endl;
/*	for(int i=1;i<=n;i++){
		if(match[i]!=0){
			int x=match[i]-n;
			printf("%d %d\n",i,x);
		}
	}
	for(int i=1;i<=n;i++){
		if(match[i]==0){
			dfs(i);
		}
	}
	printf("%d\n",counter);
	for(int i=1;i<=n;i++){
		if(match[i]!=0){
			if(mark[i]==0){
				printf("+ %d\n",i);
			}else{
				int x=match[i]-n;
				printf("- %d\n",x);
			}
		}
	}
	counter=m+n-counter;
	printf("%d\n",counter);
	for(int i=1;i<=n;i++){
		if(match[i]!=0){
			if(mark[i]==1){
				printf("+ %d\n",i);
			}else{
				int x=match[i]-n;
				printf("- %d\n",x);
			}
		}else{
			printf("+ %d\n",i);
		}
			
	}
	for(int i=1;i<=n;i++){
		if(match[i]!=0){
			mark[match[i]]=true;
		}
	}
	for(int i=n+1;i<=m+n;i++){		
		if(mark[i]==0){
			int x=i-n;
			printf("- %d\n",x);
		}
	}
	int j=0;
	for(int i=1;i<=m+n;i++){
		if(deg[i]==0)
			j++;
	}
	counter-=j;			
	printf("%d\n",counter);
	for(int i=1;i<=n;i++){
		if(match[i]!=0){
			int x=match[i]-n;
			printf("%d %d\n",i,x);
		}else{
			if(deg[i]!=0){
				int x=a[i][0]-n;
				printf("%d %d\n",i,x);
			}	
		}	
	}
	for(int i=n+1;i<=m+n;i++){
		if((match[i]==0)&&(deg[i]>0)){
			int x=i-n;
			printf("%d %d\n",a[i][0],x);
		}
	}*/												
	return 0;
}					
