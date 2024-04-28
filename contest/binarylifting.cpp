#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define MAX 300000

int leftdepth[MAX];
int rightdepth[MAX];
vector<int> pi[MAX];
// int height[MAX];

void dfs(int v, int par, int depth[])
{
    for(int child : pi[v])
    {
        if(child == par)
        {
            continue;
        }

        depth[child] = depth[v]+1;
        dfs(child, v, depth);

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

        dfs(1,0, leftdepth);

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
            if(max_depth <leftdepth[i])
            {
                max_depth = leftdepth[i];
                max_node = i;
            }

            leftdepth[i] = 0;
        }

        // cout<<max_depth<<" "<<max_node<<endl;

        //diameter
        dfs(max_node,0,leftdepth);

        max_depth = -1;
        max_node = -1;

        for(int i=1;i<= m;i++)
        {
            if(max_depth <leftdepth[i])
            {
                max_depth = leftdepth[i];
                max_node = i;
            }

            // depth[i] = 0;
        }

        // cout<<"diameter "<<max_depth<<" "<<max_node<<endl;

        // cout<<max_depth<<" "<<max_node<<"\n";

        // for(int i=1;i<=m;i++)
        // {
        //     cout<<leftdepth[i]<<" ";
        //     // cout<<height[i]<<endl;
        // }
        // cout<<"\n";

        dfs(max_node,0,rightdepth);

        for(int i=1;i<=m;i++)
        {
            cout<<max(rightdepth[i],leftdepth[i])<<" ";
            // cout<<height[i]<<endl;
        }
        cout<<"\n";

    }
    return 0;
}