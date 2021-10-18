#include<iostream>
#include<vector>
using namespace std;
FILE *fin=fopen("2SAT.in","r");
FILE *fout=fopen("2SAT.out","w");
const int H=5010;

vector <int>v[H];
int saf[H],mark[H],counter;
int n,m,nn;
void rest(int x){
	for(int i=0;i<counter;i++){
		mark[saf[i]]=x;
	}
}
int dfs(int x){
	mark[x]=2;
	saf[counter++]=x;
	for(int i=0;i<(int)v[x].size();i++){
		int t=v[x][i];
		if(mark[t]==0){
			if(mark[nn-t]==2){
				return 0;
			}else{
				if(dfs(t)==0){
					return 0;
				}
			}	
		}
	}
	return 1;
}
			
int main(){
	scanf("%d%d",&n,&m);
	nn=2*n-1;
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		x--;y--;
		if(x<0){
			x+=2;
			x=nn+x;
		}
		if(y<0){
			y+=2;
			y=nn+y;
		}
		v[nn-x].push_back(y);
		v[nn-y].push_back(x);
	}
	for(int i=0;i<n;i++){
		counter=0;
		if((mark[i]==0)&&(mark[nn-i]==0)){
			saf[counter++]=i;
			if(dfs(i)){
				rest(1);
				continue;
			}else{
				rest(0);
			}
			counter=0;
			saf[counter++]=nn-i;
			if(dfs(nn-i)){
				rest(1);
				continue;
			}else{
				rest(0);
			}
		}else{
			continue;
		}
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for(int i=0;i<n;i++){
		printf("%d\n",mark[i]);
	}
	return 0;
}

