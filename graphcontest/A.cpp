#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define uu first
#define vv second

int fx[]={1,-1,0,0}; //ডিরেকশন অ্যারে
int fy[]={0,0,1,-1};
char cell[505][505]; //cell[x][y] যদি -১ হয় তাহলে সেলটা ব্লক
int d[505][505], vis[505][505]; //d means destination from source. 
int m,n, crystal;


int bfs(int sx,int sy) //Source node is in [sx][sy] cell.
{
	memset(vis,0,sizeof vis);
	vis[sx][sy]=1;
	queue<pii>q;
	for(int k=0;k<4;k++)
	{
		int tx=top.uu+fx[k];
		int ty=top.vv+fy[k]; 
		if(tx>=0 and tx<m and ty>=0 and ty<n and cell[tx][ty]!= '#' and vis[tx][ty]==0) 
		{       
            q.push({tx, ty});
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
                
                 cell[i][j] = inp;
            }
        }
        cout<<"Case "<<z<<":"<<"\n";
        memset(d, -1, sizeof d);
        int x,y;

        while(q--)
        {
            crystal = 0;
            cin>>x>>y;
            cout<<bfs(x-1, y-1)<<"\n";

        }

    }

    return 0;
}