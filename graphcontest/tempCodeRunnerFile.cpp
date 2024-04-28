#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

char maze[505][505];
int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};
bool vis[505][505];
int crys[505][505];
int m,n, crystal;

int bfs(int x, int y)
{

    crystal = 0;
    memset(vis, false, sizeof(vis));

    if(maze[x][y] == 'C')
    {
        crys[x][y] = 1;
        vis[x][y] = true;
        crystal++;
    }
    else 
    {
        vis[x][y] = true;
        crys[x][y] = 0;
    }

    queue<pii>q;
    q.push(pii(x,y));

    while(!q.empty())
    {
        pii top = q.front();
        q.pop();

        for(int i=0;i<4;i++)
        {
            int tx = top.first +fx[i];
            int ty = top.second +fy[i];

            if(maze[tx][ty] == '#')
            {
                crys[tx][ty] = crystal;
                vis[tx][ty] = true;
                continue;
            }

            if(tx>=0 and tx<m && ty>=0 && ty<n and vis[tx][ty] == false and crys[tx][ty] != -1)
            {
                crystal = crys[tx][ty];
                continue;
            }
            else if(tx>=0 and tx<m && ty>=0 && ty<n and vis[tx][ty] == false and crys[tx][ty] == -1)
            {
                vis[tx][ty] = true;
                if(maze[tx][ty] == 'C')
                {
                    crystal++;
                }
                crys[tx][ty] = crystal;
                q.push(pii(tx, ty));
            }            
        }
    }

    return crystal;

}


int main()
{
    int t;
    cin>>t;

    for(int z =1;z<=t;z++)
    {
        int q;
        char inp;
        cin>>m>>n>>q;

        for(int i=0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                cin>>inp;
                
                maze[i][j] = inp;
            }
        }
        cout<<"Case "<<z<<":"<<"\n";
        int x,y;

        crystal = 0;
        memset(vis, false, sizeof(vis));
        memset(crys, -1, sizeof(crys));

        while(q--)
        {
            cin>>x>>y;

            if(crys[x-1][y-1] != -1)
            {
                cout<<crys[x-1][y-1]<<endl;
            }
            else
            {
                cout<<bfs(x-1, y-1)<<"\n";
            }
        }

    }
}