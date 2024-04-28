// #include <iostream>
// #include <utility>
// #include <vector>
// #include <queue>
// #include <functional>
#include <bits/stdc++.h>

using namespace std;
const int Max = 1e4+5;
typedef pair<long long, int> pii;
bool marked[Max];
vector<pii> adj[Max];

long long prim(int x)
{
    priority_queue<pii, vector<pii>, greater<pii> > Q;
    long long y;
    long long mincost=0;
    pii p;
    Q.push(make_pair(0,x));
    while(!Q.empty())
    {
        p = Q.top();
        Q.pop();
        x = p.second;

        if(marked[x] == true) continue;

        mincost += p.first;
        marked[x] = true;

        for(int i =0;i<adj[x].size();++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
            Q.push(adj[x][i]);
        }
        
    }

    return mincost;
}


int main()
{
    long long weight, mincost, edges, nodes, x,y;
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        memset(marked, false, sizeof marked);
        memset(adj, 0, sizeof adj);
        cin>> nodes>>edges;
        for(int i=0;i<edges;i++)
        {
            cin>>x>>y;
            adj[x].push_back(make_pair(1, y));
            adj[y].push_back(make_pair(1, x));
        }
        int m,n;
        cin>>m>>n;

        mincost = prim(m);

        cout<<"Case "<<i<<": "<<mincost<<"\n";
    }
    
}