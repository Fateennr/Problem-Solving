#include<iostream>
#include<vector>
#include<utility>
#include<functional>
#include<algorithm>

using namespace std;
const int Max = 1e4+5;
int id[Max], nodes, edges;
pair<long long, pair<int, int> > p[Max];

void initialize()
{
    for(int i=0;i<Max;i++)
    {
        id[i] = i;
    }
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);

    id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int> >p[])
{
    int x,y;
    long long cost, mincost = 0;
    for(int i=0;i<edges;i++)
    {
        x=p[i].second.first;
        y=p[i].second.second;

        cost = p[i].first;

        if(root(x) != root(y))
        {
            mincost += cost;
            union1(x, y);
        }
    }

    return mincost;
}
int main()
{
    int x,y;
    long long weight, cost, mincost;
    initialize();
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        cin>>x>>y>>weight;
        p[i] = make_pair(weight, make_pair(x,y));
    }

    sort(p, p+edges);
    mincost = kruskal(p);

    cout<<mincost<<"\n";
    return 0;
}