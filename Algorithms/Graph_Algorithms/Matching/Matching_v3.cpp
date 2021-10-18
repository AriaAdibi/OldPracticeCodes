bool DFS(int x)
{
	if (x==-1)
		return 1;
	for (int i=0;i<SIZE(N[x]);++i)
		if (!mark[N[x][i]]++ && DFS(mate[N[x][i]]))
			return hmate[x]++,mate[N[x][i]]=x,1;
	return 0;

}

void Matching()
{
	memset(mate,-1,sizeof mate);
	for (int i=0;i<n;++i)
		for (int j=0;j<SIZE(N[i]);++j)
			if (mate[N[i][j]]==-1)
			{
				mate[N[i][j]]=i;
				hmate[i]=1;
				break;
			}
	for (int i=0;i<n;++i)
		if (!hmate[i] && DFS(i))
			memset(mark,0,sizeof mark);
}
