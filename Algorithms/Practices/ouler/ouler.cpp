#include<iostream>
using namespace std;
const int H=200*1000+2,Max_n=100000;
int n,e,p[2][H],deg[Max_n],**a,deg2[Max_n],out[H],stack[H];
int head=0;
bool mark[H];

void dfs(){
	while(head>-1){
		while(deg2[stack[head]]<deg[stack[head]]){
			int x = stack[head];
			if (mark[a[x][deg2[x]]]==1){
				deg2[x]++;
				continue;
			}
			head++;
			if(x==p[0][a[x][deg2[x]]]){
				stack[head]=p[1][a[x][deg2[x]]];
			}else{
				stack[head]=p[0][a[x][deg2[x]]];
			}
			mark[a[x][deg2[x]]]=1;
			deg2[x]++;
		}	
		cout<<stack[head]<<" ";
		head--;
	}				
}			

int main(){ 
	cin>>n>>e;
	for(int i=0;i<e;i++){
		cin>>p[0][i]>>p[1][i];
		deg[p[0][i]]++;
		deg[p[1][i]]++;
	}
	a=new int*[Max_n];
	for(int i=0;i<n;i++){
		a[i]=new int[deg[i]];
	}
	for(int i=0;i<e;i++){
		a[p[0][i]][deg2[p[0][i]]++]=i;
		a[p[1][i]][deg2[p[1][i]]++]=i;
	}
	for(int i=0;i<n;i++){
		deg2[i]=0;
	}
	stack[0]=0;	
	dfs();
	cout<<endl;
	return 0;
}				
		
