#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <cstring>

using namespace std;

#define F first
#define PB(v,x) v.push_back(x)
#define size(X) (int)X.size()
#define S second
#define show(X) cerr << #X << " = " << X << endl;
#define getrandom(min,max) \
	((rand()%(int)(((max)+1)-(min)))+min)
#define foreach(var, container) \
	for(typeof((container).begin()) var = (container).begin(); \
			var != (container).end(); \
			++var)
#define SetBit(value, place) ((value) | (1 << (place)))
#define ClearBit(value, place) ((value) & (~(1 << (place))))
#define ToggleBit(value, place) ((value) ^ (1 << (place)))
#define GetBit(value, place) (((value) >> (place)) & 1)
#define GetPrecentage(Numerator, Denominator)	((Numerator)*100.0/(Denominator))
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({LL t;scanf("%lld",&t);t;})
#define GD ({double t;scanf("%lf",&t);t;})
#define is istringstream
#define os ostringstream
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REV(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define ROR(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define CLEAR(x) memset(x,0,sizeof x);
#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define eps 1.0e-11
#define PI(x) printf("%d ",x)
template <class X> void printa(X a,int n)
{
	REP(i,n) cerr << a[i] << " " ;
	cerr << endl;
}

template <class X> void printv(X v) 
{
	foreach(it,v) cerr << *it << " " ;
	cerr << endl;
}
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;

const int MAXN = 1100;
int a[MAXN][MAXN];
int n,m,t;
int rank[MAXN*MAXN];
int par[MAXN*MAXN];
vector<pii> v;
vector<int> T;
int sum = 0;
vector<int> ans;
int k[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int mark[MAXN*MAXN];

pii pos(int x)
{
	int a1 = x/m;
	int a2 = x%m;
	return pii(a1,a2);
}

void input()
{
	cin >> n;
	cin >> m;
	REP(i,n) REP(j,m)
	{
		int x = i*m + j+1;
		x--;
		cin >> a[i][j];
		PB(v,pii(a[i][j],x));
	}
	REP(i,t = GI) PB(T,GI);
	sort(v.begin(),v.end());
	reverse(T.begin(),T.end());
}

int FindPar(int a)
{
	if(par[a]==a)
		return a;
	else return par[a] = FindPar(par[a]);
}

void merg(int a,int b)
{
	if(rank[a] > rank[b])
		par[b] = a;
	else if(rank[b] > rank[a])
		par[a] = b;
	else
	{
		par[b] = a;
		rank[a] ++;
	}
}

void solv()
{
	int cur = 0;
	REV(i,m*n)
	{
		if(cur == t)
			break;
		while(cur < t && v[i].F <= T[cur])
		{
			PB(ans,sum);
			cur++;
		}
		if(cur == t)
			break;
		pii h = pos(v[i].S);
		++sum;
		mark[v[i].S] = 1;
		REP(j,4)
		{
			int gx = h.F + k[j][0];
			int gy = h.S + k[j][1];
			if(gx >= 0 && gy >= 0 && gx < n && gy < m)
			{
				int alf = gx*m + gy+1;
				alf--;
				if(!mark[alf])
					continue;
				if(a[gx][gy] >= a[h.F][h.S] && FindPar(alf)!=FindPar(v[i].S))
				{
					merg(FindPar(alf),FindPar(v[i].S));
					sum--;
				}
			}
		}
	}
	if(T[t-1] == 0 && v[m*n-1].F>0)
		PB(ans,sum);
}

int main()
{
	input();
	REP(i,m*n) par[i] = i;
	solv();
	REV(i,t) cout << ans[i] << " ";
	cout << endl;
	return 0;
}
