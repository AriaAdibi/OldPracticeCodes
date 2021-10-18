#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 600;
vector<int> v[MAXN];
int mark[MAXN];
int mate[MAXN];
int n;

bool dfs(int x)
{
	if(x == -1) return true;
	for(int i=0; i<(int)v[x].size(); ++i)
		if(!mark[v[x][i]]++ && dfs(mate[v[x][i]]))
		{
			mate[v[x][i]] = x;
			return true;
		}
	return false;
}

void findMatching()
{
	memset(mark,0,sizeof mark);
	memset(mate,-1,sizeof mate);
	for(int i=0;i<n;++i) if(dfs(i)) memset(mark,0,sizeof mark);
}

int main()
{
	//Input
	findMatching();
	return 0;
}
