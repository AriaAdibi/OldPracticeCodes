#include <iostream>

using namespace std;

int arr[100100];
////////////////////////////////
void input(int n, int arr[])
{
	for(int step=0; step<n; step++)
		cin>>arr[step];
}
////////////////////////////////
int ans(int n, int arr[])
{
	int flag=0;
	for(int step=0; step<n-1; step++)
		if(arr[step]!=arr[step+1])
			flag=1;
	////////////////////////////////
	if(flag==0)
		return 1;

	////////////////////////////////
	else
	{
		int div=0;
		for(int step=0; step<n-1;)
		{
			if(arr[step]==arr[step+1] && step<n-1)
			{
				div++;
				while(arr[step+1]==arr[step+2] && step<n-2)
					step++; 
				step++;

				int save=step;

				if(arr[save]<arr[save+1] && step<n-1)
				{
					while(arr[step+1]<=arr[step+2] && step<n-2)
						step++;
					step+=2;
					if(step==n-1)
						div++;
				}
				if(arr[save]>arr[save+1] && step<n-1)
				{
					while(arr[step+1]>=arr[step+2] && step<n-2)
						step++; 
					step+=2;
					if(step==n-1)
						div++;
				}
			}
			if(arr[step]<arr[step+1] && step<n-1)
			{
				div++;
				while(arr[step+1]<=arr[step+2] && step<n-2)
					step++;
				step+=2;
				if(step==n-1)
					div++;
			}
			if(arr[step]>arr[step+1] && step<n-1)
			{
				div++;
				while(arr[step+1]>=arr[step+2] && step<n-2)
					step++; 
				step+=2;
				if(step==n-1)
					div++;
			}


		}
		return div;
	}
}
////////////////////////////////
int main()
{
	int a1,an;
	cin>>a1>>an;
	int n=an-a1+1;
	input(n,arr);
	cout<<ans(n,arr);
}
