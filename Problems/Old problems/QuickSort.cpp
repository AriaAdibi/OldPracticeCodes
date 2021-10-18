#include <iostream>

using namespace std;
////////////////////////
int arr[100000];
int arr2[100000];
////////////////////////
void input(int n, int arr[])
{
	for(int step=0; step<n; step++)
		cin>>arr[step];
}
///////////////////////
void QuickSort(int n1,int n, int arr[], int arr2[])
{
	if((n-n1)>1)
	{
		int i=n1,j=n-1;
		for(int step=n1+1,t=0; step<n; step++)
		{
			if(i==j)
			{
				arr2[i]=arr[n1];
				break;}
			///////////////////////////
			if(arr[n1]>arr[step])
			{ arr2[i]=arr[step]; i++;}
			if(arr[n1]<arr[step])
			{ arr2[j]=arr[step]; j--;}
			if(arr[n1]==arr[step])
			{
				if(t%2==0)
				{ arr2[i]=arr[step]; i++; t++; }
				else
				{ arr2[j]=arr[step]; j--; t--; }
			}

		}
		///////////////
		for(int step=0; step<n; step++)
			arr[step]=arr2[step];
		//////////////
		QuickSort(n1,i,arr,arr2);
		QuickSort(j+1,n,arr,arr2);
	}
}
//////////////////////
void output(int n, int arr[])
{
	for(int step=0; step<n; step++)
		cout<<arr[step]<<" ";
}
/////////////////////
int main()
{
	int n;
	cin>>n;
	input(n,arr);
	QuickSort(0,n,arr,arr2);
	output(n,arr);
}
