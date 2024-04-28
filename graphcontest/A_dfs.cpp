#include<bits/stdc++.h>
#define pii pair<int, int>
#define uu first
#define vv second

using namespace std;

char maze[505][505];
int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};
bool vis[505][505];
int crys[505][505];
int m,n, crystal;

queue<pii> q;

int dfs(int x, int y)
{
    vis[x][y] = true;

    q.push(make_pair(x, y));

    // cout<<x<<" "<<y<<endl;
    if(maze[x][y] == 'C')
    {
        crystal++;
    }          

    for(int i=0;i<4;i++)
    {
        int tx = x+fx[i];
        int ty = y+fy[i];

        if(tx>=0 and tx<m && ty>=0 && ty<n and maze[tx][ty] != '#' and vis[tx][ty] == false)
        {
            dfs(tx,ty);
        }
    }          
}


int main()
{
    int t;
    cin>>t;

    for(int z =1;z<=t;z++)
    {
        int l;
        char inp;
        cin>>m>>n>>l;

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
        memset(crys, -1, sizeof(crys));

        while(l--)
        {
            cin>>x>>y;
            x--;
            y--;
            crystal = 0;
            memset(vis, false, sizeof(vis));

            if(crys[x][y] != -1)
            {
                crystal = crys[x][y];
            }
            else
            {
                dfs(x, y);
            }
            while(!q.empty())
            {
                pii top= q.front(); q.pop();
                int tx = top.uu;
                int ty = top.vv;

                if(crys[tx][ty] != -1)
                {
                    crystal = crys[tx][ty];
                }
                else
                {
                    crys[tx][ty] = crystal;
                }
            }

            cout<<crystal<<"\n";
        }

    }

    return 0;
}