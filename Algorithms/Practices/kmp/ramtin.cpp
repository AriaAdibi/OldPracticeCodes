#include<iostream>
using namespace std;
const int H=2000000+10;
int a[H],match=0,n,m,counter,out[H];
char s[H],t[H];
void primary(){
	int maxi=0;
	a[0]=0;
	for(int i=1;i<m;i++){
		maxi=a[i-1];
		while(maxi!=0){
			if(t[maxi]==t[i]){
				a[i]=maxi+1;
				maxi++;
				break;
			}
			maxi=a[maxi-1];
		}
		if(maxi==0){
			if(t[maxi]==t[i]){
				maxi++;
				a[i]=maxi;
			}else{
				a[i]=maxi;
			}
		}
	}
	return;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf(" %c",&s[i]);
	}
	s[n]='?';
	for(int i=0;i<m;i++){
		scanf(" %c",&t[i]);
	}
	primary();
	if(s[0]==t[0]){
		match=1;
	}
	for(int i=1;i<n;i++){
		if(match==m){
			out[counter++]=i-m;
			match=a[m-1];
		}
		if(s[i]==t[match]){
			match++;
		}else{
			while(match>0){
				match=a[match-1];
				if(t[match]==s[i]){
					match++;
					break;
				}
			}
		}
	}
	if(match==m){
		out[counter++]=n-m;
	}
	printf("%d\n",counter);
	for(int i=0;i<counter;i++){
		printf("%d ",out[i]+1);
	}
	printf("\n");
	return 0;
}
