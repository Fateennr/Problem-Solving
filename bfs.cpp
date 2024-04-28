#include<bits/stdc++.h>

using namespace std;

vector<int> pi[100];
bool visited[100];
int level[100];

void bfs(int curr)
{
    queue<int>q;

    q.push(curr);
    visited[curr] = true;

    while(!q.empty())
    {
        curr = q.front();
        q.pop();

        for(int next : pi[curr])
        {
            if(!visited[next])
            {
                q.push(next);
                visited[next] = true;
                level[next] = level[curr] +1;
            }
        }
    }
}

int main()
{
    int m;
    cin>>m;

    for(int i=0;i<m-1;i++)
    {
        int u,v;
        cin>>u>>v;
        pi[u].push_back(v);
        pi[v].push_back(u);

    }

    memset(visited, false, sizeof(visited));

    bfs(1);

    for(int i=1;i<=m;i++)
    {
        cout<<level[i]<<endl;
    }


    return 0;
}