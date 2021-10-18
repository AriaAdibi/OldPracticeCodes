#include<iostream>
using namespace std;
#define show(x) cerr<<#x<<" = "<<x<<endl

const int MAXN=1000000;
int kh[MAXN];
int sizk;


int main(){
	int n, m;
	cin>>n>>m;
	string sn, sm;
	cin>>sn>>sm;
	for(int i=0;i<=n-m;i++){
		int bo=1;
		for(int j=i, k=0;k<m;j++, k++){
			if(sn[j]!=sm[k]){
				bo=0;
				break;
			}
		}
		if(bo){
			kh[sizk++]=i+1;
		}
	}
	cout<<sizk<<endl;
	for(int i=0;i<sizk;i++){
		cout<<kh[i]<<" ";
	}
	cout<<endl;
	return 0;
	
}

