/*104 .sgu
  n ta gol , m goldoon darim 
  har golo goldoon yek darage zibayi daran 
  max =?
  kodoom ba kodoom?
  */
#include <iostream>

using namespace std;

int const MAX=120;

int a[MAX][MAX];
int d[MAX][MAX];
bool tf[MAX+MAX];

void input (int n,int m)
{
	for(int i=1; i<n+1; i++)
		for(int j=1 ;j<m+1; j++)
			cin>>a[i][j];

}

int find_max_beuty(int n,int m)
{
	for(int i=1,sum=0 ;i<n+1; i++)
	{
		sum+=a[i][i];
		d[i][i]=sum;
	}
	for(int j=2; j<m+1; j++)
		for(int i=j-1; i>0; i--)
			d[i][j]=max(d[i][j-1],(d[i-1][j-1]+a[i][j]));

	return d[n][m];
	
}

void vases_plases(int n, int m)
{
	int start=0;
	int vase_number=m;
	for(int i=0,k=0; i<m+n+2; i++, vase_number--)
	{
		if(tf[i]==1)
			k++;
		if(k==n)
		{
			start=i;
			break;
		}
	}
	for( ; start>-1; start--, vase_number++)
		if(tf[start]==1)
			cout << vase_number << " ";
	cout<<endl;

		

}

void find_vases_places(int n,int m)
{
	for(int j=m,i=n,k=0; m>0; j--)
	{
		if(d[i][j]==d[i][j-1])
			tf[k++]=0;
		else
		{
			tf[k++]=1;
			i--;
			if(i==0)
				break;

		}
	}
	vases_plases(n, m);
}

int main()
{
	int n,m;
	cin >> n >> m;
	input(n,m);
	cout << find_max_beuty(n,m) <<endl;
	find_vases_places(n,m);
}
