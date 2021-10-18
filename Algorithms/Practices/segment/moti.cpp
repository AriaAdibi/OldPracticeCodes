#include<iostream>
using namespace std;
const int H=4*1000*1000+10;
struct man{
	long long mul,plus;
	man(){
		mul=1;
		plus=0;
	}
};
man a[H];
int num,z;
char ch;
int k,n,m;
void norm(int x){
	if(a[x].mul>=k){
		a[x].mul%=k;
	}
	if(a[x].plus>=k){
		a[x].plus%=k;
	}
}
void out(int p,int q,int x,int l){
	if(q-p==1){
		num*=a[x].mul;
		num+=a[x].plus;
		if(num>=k){
			num%=k;
		}
		return;
	}
	int mid=(p+q)/2;
	if(l<mid){
		out(p,mid,2*x,l);
	}else{
		out(mid,q,2*x+1,l);
	}
	num*=a[x].mul;
	num+=a[x].plus;
	if(num>=k){
		num%=k;
	}
}

void shift(int x){
	int temp=2*x;
	a[temp].mul*=a[x].mul;
	a[temp].plus*=a[x].mul;
	a[temp].plus+=a[x].plus;
	norm(temp);
	temp++;
	a[temp].mul*=a[x].mul;
	a[temp].plus*=a[x].mul;
	a[temp].plus+=a[x].plus;
	norm(temp);
	a[x].mul=1;
	a[x].plus=0;
}


void find(int p,int q,int x,int l,int r){
	if(p==l && q==r){
		if(ch=='*'){
			a[x].mul*=z;
			a[x].plus*=z;
			norm(x);			
		}
		if(ch=='+'){
			a[x].plus+=z;
			norm(x);
		}
		return ;
	}
	int mid=(p+q)/2;
	shift(x);
	if(r<=mid){
		find(p,mid,2*x,l,r);
	}else if(l>=mid){
		find(mid,q,2*x+1,l,r);
	}else{
		find(p,mid,2*x,l,mid);
		find(mid,q,2*x+1,mid,r);
	}
}


int main(){
	scanf("%d%d%d",&n,&m,&k);
	n++;
	int x,y;
	for(int i=0;i<m;i++){
		scanf(" %c",&ch);
		if(ch=='?'){
			scanf("%d",&x);
			num=0;
			out(0,n,1,x);
			cout<<num%k<<endl;
		}else{
			scanf("%d%d%d",&x,&y,&z);
			y++;
			find(0,n,1,x,y);
		}
	}
	return 0;
}

