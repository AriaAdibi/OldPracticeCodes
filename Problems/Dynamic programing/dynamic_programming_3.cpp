/* sekehaye c1,c2,c3,...,cn $ ra darim
   barnameyi benevisid ke begooyad M$ ra 
   be chand ravesh mishe sakht*/
#include <iostream>
#include <algorithm>

using namespace std;

int const MAX=1100;
int const MAX2=120;

int a[MAX2];
int d[MAX][MAX2];


void input(int n)
{
	for(int i=1; i<n+1; i++)
		cin >> a[i];
}

int cauonting_ways(int n, int m)
{
	for(int j=1; j<n+1; j++)
		d[0][j]=1;
	for(int j=1; j<n+1; j++)
		for(int i=1; i<m+1; i++)
		{
			if(i>=a[j])
				d[i][j]=d[i][j-1]+d[i-a[j]][j];
			else
				d[i][j]=d[i][j-1];
		}
	return d[m][n];
}
int main()
{
	int n,m;
	cin >> n >> m;
	input (n);
	sort(a, a+n+1);
	cout << cauonting_ways(n,m) <<endl;
}
