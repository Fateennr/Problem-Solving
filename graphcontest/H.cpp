#include<bits/stdc++.h>
#define ll long long 
#define M (int)2e5+5

using namespace std;

int flag;
ll id[M];

void initialize()
{
    for(int i=0;i<M;i++)
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

void dsu(int m, int n)
{
    

}
int main()
{
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        int N;
        cin>>N;
        ll m,n;
        cin>>m>>n;
        dsu(m,n);
    }
    return 0;
}