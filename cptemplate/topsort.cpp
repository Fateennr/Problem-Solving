#include<bits/stdc++.h>

using namespace std;

queue<int> topsort(int N,int adj[][])
{
    
    int visited[] = {};
    int in_degree[] = {};
    queue<int>q;
    queue<int>T;

    for(int i=0;i<N;i++)
    {
        in_degree[i] = visited[i] = 0;
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;i<N;j++)
        {
            if(adj[i][j] == true)
            {
                in_degree[j] = in_degree[j]+1;
            }
        }

    }

    for(int i=0;i<N;i++)
    {
        if(in_degree[i] == 0)
        {
            q.push(i);
            visited[i] =true;
        }
    }

    while(!q.empty())
    {
        int vertex = q.front();
        q.pop();
        T.push(vertex);

        for(int j=0;j<N;j++)
        {
            if(adj[vertex][j]==true and visited[j]==false)
            {
                in_degree[j]++;
                if(in_degree[j]==0)
                {
                    q.push(j);
                    visited[j] = true;
                }
            }
        }
        
    }

    return T;
}
int main()
{
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        

    }



    return 0;
}