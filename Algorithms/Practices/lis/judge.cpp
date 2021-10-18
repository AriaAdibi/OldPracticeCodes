#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("out2");
int main(){
	int n,m,x,y;
	fin>>m;
	cin>>n;
	if(n!=m){
		cout<<"WRONG ans"<<endl;
		return 0;
	}
	cin>>x;
	for(int i=1;i<n;i++){
		cin>>y;
		if(y<x){
			cout<<"WRONG!!!";
			return 0;
		}
		x=y;
	}
	cout<<"Accepted"<<endl;
	return 0;
}
