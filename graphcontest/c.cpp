#include<bits/stdc++.h>

using namespace std;

char maze[30][30];
int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};
bool vis[30][30];
// int crys[505][505];
int m,n, crystal;

void dfs(int x, int y)
{
    // cout<<x<<" "<<y<<"\n";
    vis[x][y] = true;
       
    for(int i=0;i<4;i++)
    {
        int tx = x+fx[i];
        int ty = y+fy[i];

        if(tx>=0 and tx<=m and ty>=0 && ty<=n and maze[tx][ty] == '.' and vis[tx][ty] == false)
        {
            dfs(tx,ty);
            crystal++;
        }
    }          
}


int main()
{
    int z, ansx, ansy;
    cin>>z;
    char inp;
    for(int g =1;g<=z;g++)
    {
        cin>>n>>m;
        m--;
        n--;

        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                cin>>inp;
                if(inp == '@')
                { 
                    ansx = i;
                    ansy = j;
                }
                // cout<<"ansx"<<i<<" "<<j<<"\n";
                maze[i][j] = inp;
            }
        }
        memset(vis, false, sizeof vis);
        crystal = 1;
        dfs(ansx, ansy);
        cout<<"Case "<<g<<": "<<crystal<<"\n";
    }
    return 0;
}