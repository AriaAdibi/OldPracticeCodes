#include<iostream>
#define show(x) cerr<<#x<<":"<<x<<endl;
using namespace std;
struct man{
	long long zarb,jam;
};
const int H=4*100100;	
man a[H];
char ch;
int lef,righ,amal,n,m,t=0,k;

void out(int y,int x,int aval,int akhar){/*y adadi ke donbaleshim,x node,aval VA akhar baze*/
	int mid=(aval+akhar)/2;
	if(akhar-aval==1){
		t*=a[x].zarb;
		t+=a[x].jam;
		x/=2;
		return;
	}	
	if(y>=mid){
		out(y,2*x+1,mid,akhar);
	}else{
		out(y,2*x,aval,mid);
	}
	t*=a[x].zarb;
	t+=a[x].jam;
	t%=k;			
}
void shift(int x){
	int h=2*x,g=2*x+1;
	a[h].zarb*=a[x].zarb;
	a[g].zarb*=a[x].zarb;
	a[h].jam*=a[x].zarb;
	a[g].jam*=a[x].zarb;
	a[h].jam+=a[x].jam;
	a[g].jam+=a[x].jam;
	a[h].zarb%=k;
	a[g].zarb%=k;
	a[h].jam%=k;
	a[g].jam%=k;
	a[h].jam%=k;
	a[g].jam%=k;
	a[x].zarb=1;
	a[x].jam=0;
}			
void find(int l,int r,int x,int aval,int akhar){ /*r VA l barye bazeye mojood,x:node,aval VA akhar baraye jayi ke migardim*/ 
	if(((aval==l)&&(akhar==r))||(l-r==1)){
		if(ch=='*'){
			a[x].zarb*=amal;
			a[x].jam*=amal;
		}else{
			a[x].jam+=amal;
		}
		return;
	}
	shift(x);
	int mid=(l+r)/2;
	if(aval>=mid){
		find(mid,r,2*x+1,aval,akhar);
	}else if(akhar<=mid){
		find(l,mid,2*x,aval,akhar);
	}else{
		find(mid,r,2*x+1,mid,akhar);
		find(l,mid,2*x,aval,mid);
	}
}					

int main(){
	cin>>n>>m>>k;
	for(int i=0;i<H;i++){
		a[i].zarb=1;
	}	
	for(int i=0;i<m;i++){
		cin>>ch;
		if(ch=='?'){
			t=0;
			cin>>lef;
			out(lef-1,1,0,n);
			cout<<t%k<<endl;
			continue;
		}	
		cin>>lef>>righ;
		lef--;
		cin>>amal;
		find(0,n,1,lef,righ);
	}
	return 0;
}
