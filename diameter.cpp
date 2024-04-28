#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define MAX 300000

int depth[MAX];
vector<int> pi[MAX];
// int height[MAX];

void dfs(int v, int par= 0)
{
    for(int child : pi[v])
    {
        if(child == par)
        {
            continue;
        }

        depth[child] = depth[v]+1;
        dfs(child, v);

        // height[v] = max(height[v], height[child]+1);
    }
}

int main()
{
    int n = 1;
    // cin>>n;

    while(n--)
    {
        int m;
        cin>>m;
        vector<int> weight[m];

        for(int i=0;i<m-1;i++)
        {
            int u,v;
            cin>>u>>v;
            pi[u].push_back(v);
            pi[v].push_back(u);

        }

        dfs(1);

        // for(int i=1;i<=m;i++)
        // {
        //     cout<<depth[i]<<" ";
        //     // cout<<height[i]<<endl;
        // }
        // cout<<"\n";

        int max_depth = -1;
        int max_node = -1;

        for(int i=1;i<= m;i++)
        {
            if(max_depth <depth[i])
            {
                max_depth = depth[i];
                max_node = i;
            }

            depth[i] = 0;
        }

        // cout<<max_depth<<" "<<max_node<<endl;

        //diameter
        dfs(max_node);

        max_depth = -1;
        max_node = -1;

        for(int i=1;i<= m;i++)
        {
            if(max_depth <depth[i])
            {
                max_depth = depth[i];
                max_node = i;
            }

            depth[i] = 0;
        }

        // cout<<"diameter "<<max_depth<<" "<<max_node<<endl;

        cout<<max_depth<<"\n";
    }
    return 0;
}