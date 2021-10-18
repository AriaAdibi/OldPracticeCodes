#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int MAXn = 200;
typedef pair<int,int> pii;
int a[MAXn][MAXn], b[MAXn][MAXn];
int pl[MAXn], in[MAXn];
int n;

int tmp[MAXn];
vector<pii> col;
vector<pii> row;
void printper(vector<pii>& v)
{
	for(int i = 0; i < n; i++)
		tmp[i] = i;
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
			if(tmp[j] == in[i])
			{
				v.push_back(pii(i,j));
				swap(tmp[i], tmp[j]);
				break;
			}
	}
}

bool cmp(pii p1, pii p2)
{
	for(int i = 0; i < n; i++)
	{
		int v1, v2;
		if(p1.first == 0)
			v1 = a[p1.second][in[i]];
		else
			v1 = b[p1.second][i];
		if(p2.first == 0)
			v2 = a[p2.second][in[i]];
		else
			v2 = b[p2.second][i];
		if(v1 != v2)
			return v1 < v2; 
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j],
			    a[i][j]--;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> b[i][j],
			    b[i][j]--;
	for(int i = 0; i < n; i++)
		pl[a[0][i]] = i;
	vector<pii> v;
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < n; j++)
			v.push_back(make_pair(i,j));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			in[j] = pl[b[i][j]];
		sort(v.begin(), v.end(), cmp);
		bool f = true;
		for(int j = 0; j < 2*n; j+=2)
			if(cmp(v[j], v[j+1]) || cmp(v[j+1], v[j]))
				f = false;
		if(f)
		{
			printper(col);
			for(int i = 0; i < 2*n; i+=2)
				if(v[i+1].first == 1)
					in[v[i+1].second] = v[i].second;
				else
					in[v[i].second] = v[i+1].second;
			printper(row);
			cout << col.size() + row.size() << endl;
			for(int i = 0; i < (int)col.size(); i++)
				cout << "col " << col[i].first+1 << " " << col[i].second+1 << endl;
			for(int i = 0; i < (int)row.size(); i++)
				cout << "row " << row[i].first+1 << " " << row[i].second+1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
