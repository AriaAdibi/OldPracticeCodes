// YA HAGH

#include<iostream>
#include<vector>
using namespace std;
const int H=5010*2;
int n,m,nn,saf[H],counter,mark[H];
vector <int>a[H];
void rest(int x){
	for(int i=0;i<counter;i++){
		mark[saf[i]]=x;
	}
}

int dfs(int x){
	mark[x]=2;
	saf[counter++]=x;
	int temp;
	for(int i=0;i<(int)a[x].size();i++){	
		temp=a[x][i];
		if(mark[temp]!=0){
			continue;
		}
		if(mark[nn-temp]==2){
			return 0;
		}else{
			if(dfs(temp)==0){
				return 0;
			}
		}
	}
	return 1;
}

int main(){
	scanf("%d%d",&n,&m);
	nn=2*n+1;
	int x,y;
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		if(x<0){
			x=nn+x;
		}
		if(y<0){
			y=nn+y;
		}
		a[nn-x].push_back(y);
		a[nn-y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(mark[i]==0 && mark[nn-i]==0){
			if(dfs(i)==1){
				rest(1);
				continue;
			}else{
				rest(0);
			}
			counter=0;
			if(dfs(nn-i)==1){
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
	for(int i=1;i<=n;i++){
		printf("%d\n",mark[i]);
	}
	return 0;
}
#include<iostream>
#include<cstdlib>
using namespace std;
const int H=1010;
int a[H][H],n,m;
int main(){
	srand(time(0));
	int n=2000;
	int m=30000;
	int x,y,z;
	cout<<n<<" "<<m<<endl;
	while(m>0){
		x=rand()%n+1;
		y=rand()%n+1;
		z=rand()%4;
		if(z==0){
			cout<<x<<" "<<y<<endl;
		}else if(z==1){
			cout<<-x<<" "<<-y<<endl;
		}else if (z==2){
			cout<<-x<<" "<<y<<endl;
		}else{
			cout<<x<<" "<<-y<<endl;
		}
		m--;
	}
	return 0;
}
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

