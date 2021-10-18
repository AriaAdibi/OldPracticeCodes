#include<iostream>
using namespace std;
const int H=1100;
int n,m,b[H][H];
int main(){
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		b[x][y]=1;
		b[y][x]=1;
	}
	scanf("%d",&y);
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		if(b[y][x]==0){
			cout<<" WRONG !!! "<<endl;
			return 0;
		}else{
			b[y][x]=0;
			b[x][y]=0;
		}
		y=x;
	}
	cout<<"OK !?!"<<endl;
	return 0;
}
