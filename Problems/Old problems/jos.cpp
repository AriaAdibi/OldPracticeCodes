#include <iostream>
using namespace std;
int a[10000000];
int main()
{
	int n,k;
	cin>>n;
	cin>>k;
	for(int j=0,i=0,g=0;  g<n-1;  i++)
	{
		if(a[i]==0)
		{
		
			j++;
			if(j==k)
			{
				a[i]=1;
				j=0;
				g++;
			}
		}
		if(i==n-1)
		{
			i=-1;
		}
	}
	for(int j=0; j<n; j++)
	{
		if(a[j]==0)
			cout<<j+1<<endl;
	}
}
