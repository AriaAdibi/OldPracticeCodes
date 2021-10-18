#include <iostream>

using namespace std;

///////////////////////
struct array
{
	int arr[100000];
	int n;
	array()
	{
		for(int i=0; i<n; i++)
		{
			arr[i]=0;
		}
	}
};
//////////////
array a;
//////////////
void input (array &a)
{
	for(int i=0; i<a.n; i++)
		cin>>a.arr[i];
}
//////////////
void trans (array a, array &b, int k)
{
	for(int i=k,j=0; i<b.n+k; i++,j++)
		b.arr[j]=a.arr[i];
}
//////////////
void merge(array &a)
{
	array b;
	array c;
	b.n=(a.n+1)/2;
	c.n=a.n/2;
	trans(a,b,0);
	trans(a,c,b.n);
	/////////////
	cerr<<"B:";
	for(int i=0; i<b.n; i++)
		cerr<<b.arr[i];
	cerr<<endl;
	cerr<<"C:";
	for(int i=0; i<c.n; i++)
		cerr<<c.arr[i];
	cerr<<endl;
	///////////////////////
	if(b.n>=1 && c.n>=1)
	{
		merge(b);
		merge(c);
		//////////////
		int k=0,l=0,i=0;
		for( ;i<b.n; i++)
		{
			cerr<<"F"<<endl;
			if(l==c.n)
				break;
			for(int j=l; j<c.n; j++)
			{
				if(b.arr[i]<=c.arr[j])
				{
					a.arr[k]=b.arr[i];
					k++;
					///////////
					cerr<<"M:";
					for(int p=0; p<k+1; p++)
						cerr<<a.arr[p];
					cerr<<endl;
					///////////
					break;
				}
				if(b.arr[i]>c.arr[j])
				{
					a.arr[k]=c.arr[j];
					k++;
					l++;
					///////////
					cerr<<"M2:";
					for(int p=0; p<k+1; p++)
						cerr<<a.arr[p];
					cerr<<endl;
					///////////
					if(l==c.n)
						break;
					
				}
				
			}
		}
		if(k<a.n)
		{
			cerr<<"if"<<endl;
			if(l!=c.n)
				while(l<c.n)
				{
					a.arr[k]=c.arr[l];
					k++;
					l++;
					cerr<<"IF:";
					for(int i=0; i<k;i++)
						cerr<<a.arr[i];
					cerr<<endl;
				}
			else
				while(i<b.n)
				{
					a.arr[k]=b.arr[i];
					k++;
					i++;
					cerr<<"IF2:";
					for(int i=0; i<k;i++)
						cerr<<a.arr[i];
					cerr<<endl;

				}
		}
	}
}
//////////////
void output(array a)
{
	for(int i=0; i<a.n; i++)
		cout << a.arr[i];
}
//////////////
int main()
{
	int n;
	cin>>n;
	a.n=n;
	input(a);
	merge(a);
	output(a);
}
