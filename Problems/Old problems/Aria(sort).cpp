#include <iostream>
using namespace std;
int main()
{
int a[1000];
int n;
cin>>n;
for(int j,i=0; i<n; i++)
{
cin>>j;
a[i]=j;
}
for(int x,i=0; i<n; i++)
{
if(a[i]>a[i+1])
{
x=a[i+1];
a[i+1]=a[i];
a[i]=x;
i=-1;
}
for(int i=0; i<n; i++)
{
cout<< a[i] <<" ";
}
cout<<endl;
}	

