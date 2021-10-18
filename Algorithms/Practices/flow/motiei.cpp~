#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=500+10;
int a[N][N];
int n, m;
int Maxflow=0, flow;
bool mark[N];

bool DFS(int x,int y)
{
	mark[x]=1;
	if(x==n)
	{
		Maxflow+=y;
		return 1;
	}
	for(int i=1 ; i<=n ; i++)
	{
		if(!mark[i] && a[x][i]>=y)
		{
			if(DFS(i,y))
			{
				a[x][i]-=y;
				a[i][x]+=y;
				return 1;
			}
		}
	}
	return 0;
}
	

int main()
{
	cin >> n >> m;
	int x, y, z;
	for(int i=0 ; i<m ; i++)
	{
		cin >> x >> y >> z;
		a[x][y]+=z;
		a[y][x]+=z;
	}
	for(int i=30 ; i>=0 ; i--)
	{
		while(DFS(1,(1<<i)))
		{
			memset(mark,0,sizeof mark);
		}
		memset(mark,0,sizeof mark);
	}
	cout << Maxflow << endl;
	return 0;
}
	


	





