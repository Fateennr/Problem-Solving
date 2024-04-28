#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <functional>

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
    cin>> nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        cin>>x>>y>>weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }

    mincost = prim(1);

    cout<<mincost<<"\n";
    
}