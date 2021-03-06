#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct node
{
	long long sum, zarb;
	int  chap;
};


const int N=1 << 19, N2=10*1000+10;
const int MAX=2*N+10;

node a[2*N];

int n, m, k, counter=1;

void pl(int, int, int, int, int, int);
void cr(int, int, int, int, int, int);
long long ans(int, int, int, int);
void shift(int);

int main()
{
	cin >> n >> m >> k;
	for(int i=0; i < 2*N; i++){
		a[i].chap=-1;
		a[i].sum=0;
		a[i].zarb=1;
	}
	for(int i=0; i < m; i++)
	{
		char c;
		int x, y, z;
		scanf(" %c", &c);
		if(c=='?')
		{
			scanf(" %d", &x);
			cout << ans(0, 0, N, x)%k << endl;
		}
		else
		{
			scanf(" %d %d %d", &x, &y, &z);
			y++;
			if(c=='+')
			{	
				pl(0, 0, N, x, y, z);
			}
			else
				cr(0, 0, N, x, y, z);
		}
	}
	return 0;
}

void pl(int ind, int l, int r, int s, int f, int x)
{
	if((l==s) && (r==f))
	{
		a[ind].sum+=x;
		return;
	}
	if(a[ind].chap==-1)
	{
		a[ind].chap=counter;
		counter+=2;
	}
	shift(ind);
	int mid=(l+r)/2;
	if(f <= mid)
		pl(a[ind].chap, l, mid, s, f, x);
	else if(s >= mid)
		pl(a[ind].chap+1, mid, r, s, f, x);
	else
	{
		pl(a[ind].chap, l, mid, s, mid, x);
		pl(a[ind].chap+1, mid, r, mid, f, x);
	}
}

void cr(int ind, int l, int r, int s, int f, int t)
{
	if((l==s) && (r==f))
	{
		a[ind].zarb*=t;
		a[ind].sum*=t;
		return;
	}
	if(a[ind].chap==-1)
	{
		a[ind].chap=counter;
		counter+=2;
	}
	shift(ind);
	int mid=(l+r)/2;
	if(f <= mid)
		cr(a[ind].chap, l, mid, s, f, t);
	else if(s >= mid)
		cr(a[ind].chap+1, mid, r, s, f, t);
	else
	{
		cr(a[ind].chap, l, mid, s, mid, t);
		cr(a[ind].chap+1, mid, r, mid, f, t);
	}
}

long long ans(int ind, int l, int r, int x)
{	
	if(r-l==1){
		return a[ind].sum;
	}
	if(a[ind].chap==-1)
	{
		a[ind].chap=counter;
		counter+=2;
	}
	shift(ind);
	int mid=(l+r)/2;
	if(x < mid)
		return ans(a[ind].chap, l, mid, x);
	else
		return ans(a[ind].chap+1, mid, r, x);
}

void shift(int ind)
{
	int tmp=a[ind].chap;
	int x=a[ind].zarb, y=a[ind].sum;
	a[tmp].zarb*=x;
	a[tmp].sum*=x;
	a[tmp].sum+=y;
	tmp++;
	a[tmp].zarb*=x;
	a[tmp].sum*=x;
	a[tmp].sum+=y;
	a[ind].zarb=1;
	a[ind].sum=0;
	a[tmp].sum%=k;
	a[tmp].zarb%=k;
	a[tmp-1].sum%=k;
	a[tmp-1].zarb%=k;
	
}




