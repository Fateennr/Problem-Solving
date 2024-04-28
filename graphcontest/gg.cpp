#include<bits/stdc++.h>
#define pii pair<int, int>
#define uu first
#define vv second

using namespace std;

char maze[505][505];
int fx[] = {1,-1,0,0,1,-1,1,-1};
int fy[] = {0,0,1,-1,1,1,-1,-1};
bool vis[505][505];
// int crys[505][505];
int m,n, crystal;

queue<pii> q;

void dfs(int x, int y)
{
    vis[x][y] = true;
       

    for(int i=0;i<8;i++)
    {
        int tx = x+fx[i];
        int ty = y+fy[i];

        if(tx>=0 and tx<=m and ty>=0 && ty<=n and maze[tx][ty] == '@' and vis[tx][ty] == false)
        {
            dfs(tx,ty);
        }
    }          
}


int main()
{
    char inp;
    while(1)
    {
        cin>>m>>n;
        if(m == 0 && n==0)
        {
            break;
        }
        m--;
        n--;

        for(int i=0;i<=m;i++)
        {
            for(int j =0;j<=n;j++)
            {
                cin>>inp;
                maze[i][j] = inp;
            }
        }
        memset(vis, false, sizeof vis);
        crystal = 0;

        for(int i=0; i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {

                if(maze[i][j]=='@' and vis[i][j] == false)
                {
                    dfs(i, j);
                    crystal++;
                }
            }
        }

        cout<<crystal<<"\n";
    }
    return 0;
}