#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int N=500+10, INF=(int) 1e9+10;

int c[N][N], f[N][N];
bool mark[N];

int n, m;
int valf=0, pathmin, k;

void flow();
bool dfs(int, int);

int main()
{
	cin >> n >> m;
	for(int i=0; i < m; i++)
	{
		int v, u, w;
	       	cin >> v >> u >> w;	
		v--;
		u--;
		c[v][u]+=w;
		c[u][v]+=w;
	}
	flow();
	for(int i=0; i < n ;i++)
		valf+=f[0][i];
	cout << valf << endl;
	return 0;
}

void flow()
{
	for(int i=30; i >= 0; i--)
	{
		k=1 << i;
		while(dfs(0, INF))
			memset(mark, 0, sizeof mark);
		memset(mark, 0, sizeof mark);
	}
}

bool dfs(int u, int Min)
{
	mark[u]=1;
	if(u==n-1)
	{
		pathmin=Min;
		return 1;
	}
	for(int i=0; i < n; i++)
		if((!mark[i]) && (c[u][i]-f[u][i] >= k))
			if(dfs(i, min(Min, c[u][i]-f[u][i])))
			{
				f[u][i]+=pathmin;
				f[i][u]-=pathmin;
				return 1;
			}
	return 0;
}


