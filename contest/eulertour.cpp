#include<bits/stdc++.h>

using namespace std;
#define MAX 300000

int depth[MAX];
vector<int> pi[MAX];
int st[MAX];


void tour(int u, int p, Tree &T) {
        st[u] = t++;
        int idx = 0;
        for(int v: T[u]) {
            if(v == p) continue; 
//            nxt[v] = (idx++ ? v : nxt[u]); // only for hld
            anc[0][v] = u, lvl[v] = lvl[u] + 1;
            tour(v, u, T);
        }
        en[u] = t; // [st, en] contains subtree range 
    }
// void tour(int u, int p, vector<vector<int>> &m)
// {


// }

int main()
{

    int m, n;
    cin>>m>>n;

    for(int i=0;i<m-1;i++)
    {
        int u,v;
        cin>>u>>v;
        pi[u].push_back(v);
        pi[v].push_back(u);

    }

    // memset(st, 0, sizeof st);
    memset(depth, 0, sizeof depth);

    while(n--)
    {
    	int a, b;
    	cin>>a>>b;

    	// dfs(a,b,0);


    }

    for(int i=1;i<=m;i++)
    {
    	cout<<depth[i]<<" ";
    }
    cout<<"\n";

    return 0;
}