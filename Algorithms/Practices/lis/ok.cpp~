#include<iostream>
using namespace std;
const int H=1000*1000+10;
int n,a[H],b[H],par[H],head,c[H];

void print(int x){
	if(x==-1){
		return;
	}
	print(par[x]);
	printf("%d ",a[x]);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		int p=lower_bound(b,b+head,a[i])-b;
		b[p]=a[i];
		par[i]=c[p-1];
		c[p]=i;
		if(p==head){
			head++;
		}
		par[c[0]]=-1;
	}
	printf("%d\n",head);
	print(par[c[head-1]]);
	printf("%d\n",a[c[head-1]]);
	return 0;
}
