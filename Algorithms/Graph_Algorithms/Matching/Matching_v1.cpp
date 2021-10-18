#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 100 + 10 , M = 100 + 10 ;

int n,m,e,maxMh;

int mh[N],mark[N];

vector<int> adj[N];

bool findPath(int v)
{
       mark[v]=true;
       for(int i = 0;i<adj[v].size();++i)
       {
               int u=adj[v][i];
               if (mh[u]==-1)
               {
                       mh[u]=v;
                       return true;
               }        
       }
       for(int i = 0;i<adj[v].size();++i)
       {
               int u=adj[v][i];
               if (mark[mh[u]] || !findPath(mh[u]))
                       continue;
               mh[u]=v;
               return true;
       }
       return false;
}

void findMaxmatching()
{
       for(int i=0;i<n;++i) if(findPath(i))
       {
               maxMh++;
               memset(mark,0,sizeof mark);
       }
}


int main(){
       cin >> n >> m >> e;//Vertices in X,Y and edges
       for(int i=0;i<e;++i)
       {
               int u,v; //u from x is adjacent to v in y
               cin >> u >> v;
               adj[u-1].push_back(v-1);
       }
       memset(mh,-1,sizeof mh);
       findMaxmatching();
       cout << maxMh << endl;
       for(int i=0;i<m;++i) if(mh[i]!=-1)
               cout << mh[i] << " " << i << endl;
       return 0;
}
