#include<iostream>
#include<vector>
using namespace std;
const int H=1000*1000;
int **a,n,m,**b,*deg2,counter=0;
int tar[H],*man,*khor,*vor,edge[2][H/10];
bool mark[H];
vector <int>out[H];
void dfs1(int x){
	mark[x]=1;
	for(int i=0;i<khor[x];i++){
		int v=a[x][i];
		if(mark[v]==0){
			dfs1(v);
		}
	}
	tar[counter++]=x;
}
void dfs2(int x){
	mark[x]=1;
	for(int i=0;i<vor[x];i++){
		int v=b[x][i];
		if(mark[v]==0){
			dfs2(v);
		}
	}
	out[counter].push_back(x);
}
bool cmp(const vector<int> &q,const vector<int> &p){
	return(q[0]<p[0]);
}
int main(){
	scanf("%d%d",&n,&m);
	vor=new int[n];
	khor=new int[n];
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;	
		vor[v]++;
		khor[u]++;
		edge[0][i]=u;
		edge[1][i]=v;
	}
	a=new int*[n];
	b=new int*[n];
	for(int i=0;i<n;i++){
		a[i]=new int[khor[i]];
	}
	for(int i=0;i<n;i++){
		b[i]=new int[vor[i]];
	}
	deg2=new int[n];
	man=new int [n];
	for(int i=0;i<m;i++){
		int x=edge[0][i],y=edge[1][i];
		a[x][deg2[x]++]=y;
	}
	for(int i=0;i<m;i++){
		int x=edge[1][i],y=edge[0][i];
		b[x][man[x]++]=y;
	}
	delete []deg2;
	delete []man;
	for(int i=0;i<n;i++){
		if(mark[i]==0){
			dfs1(i);
		}
	}
	counter=0;
	memset(mark,0,sizeof mark);
	reverse(tar,tar+n);
	for(int i=0;i<n;i++){
		if(mark[tar[i]]==0){
			dfs2(tar[i]);
			sort(out[counter].begin(),out[counter].end());
			counter++;
		}
	}
	printf("%d\n",counter);
	sort(out,out+counter,cmp);
	for(int i=0;i<counter;i++){
		for(int j=0;j<out[i].size()-1;j++){
			printf("%d ",out[i][j]+1);
		}
		printf("%d\n",out[i][out[i].size()-1]+1);
	}
	return 0;
}	
