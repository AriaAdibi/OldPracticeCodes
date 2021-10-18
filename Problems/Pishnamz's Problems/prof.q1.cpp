#include <iostream>

using namespace std;

long long  p[100000];

int main()
{
	long long sum=1, number=0;
	for(int step=0; step<100000; step++,number++)
	{
		sum+=number;
		p[step]=sum;
	}
	int n;
	cin>>n;
	for(int flag, input, step=0; step<n; step++)
	{
		flag=0;
		cin>>input;
		for(int level=0; p[level]<=input; level++)
		{
			if(input==p[level])
			{
				cout<<1;
				flag=1;
				break;
			}
		}
		if(flag==0)
			cout<<0;
	}
}
