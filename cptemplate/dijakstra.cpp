#include<bits/stdc++.h>

using namespace std;
#define MAX 10005
struct node
{
    int u;
    int cost;
    node(int _u, int _cost)
    {
        u = _u;
        cost = _cost;
    }
    bool operator < (const node& p) const { return cost < p.cost; }
};

int dist[105];

void dijakstra(vector<int>g[], vector<int>cost[], int source)
{

    priority_queue<node>q;
    q.push(node(source, 0));
    dist[source] = 0;

    while(!q.empty())
    {
        node top = q.top();
        q.pop();

        int u = top.u;

        for(int i=0; i<(int)g[u].size();i++)
        {
            int v = g[u][i];

            //relaxation
            if(dist[u] + cost[u][i] < dist[v])
            {
                dist[v] = dist[u] + cost[u][i];
                q.push(node(v, dist[v]));
            }
        }
    }
}

int main()
{
    int numedges, numnodes;
    int T;
    cin>>T;

    for(int i =1;i<=T;i++)
    {
        cin>>numnodes>>numedges;
        vector<int> g[105], cost[105];

        for (int i = 0; i < 105; ++i) {
            dist[i] = MAX;
        }
        // cout<<dist[numedges]<<"\n";
        for(int i=0;i<numedges;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            g[u].push_back(v);
            g[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        dijakstra(g, cost, 1);
        cout<<"Case "<<i<<": ";
        (dist[numnodes]!= MAX) ? cout<<dist[numnodes]<<"\n" : cout<<"Impossible\n";
    }
    return 0;
}
