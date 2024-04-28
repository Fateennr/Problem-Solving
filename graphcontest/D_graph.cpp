#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define uu first
#define vv second

bool vis[15][15];
priority_queue<char, vector<char>, greater<char>> pq;
int d[15][15]; 
char cell[15][15]; 
int fx[] = {1,-1, 0,0};
int fy[] = {0, 0, 1,-1};
int N;

int bfs(int x, int y, int foodcount)
{
    char foodweight;
    memset(vis, false, sizeof vis);
    memset(d, -1, sizeof d);

    vis[x][y] = true;
    if(pq.top()==cell[x][y]) 
    {
        d[x][y] = 0;
        foodcount--; 
        pq.pop();   
        foodweight= pq.top();
        cout<<"food "<<foodweight<<"\n"; 
    }
    if(foodcount == 0) {return 0;}

    queue<pii> pi;

    pi.push({x,y});
    int tx, ty;

    while(!pi.empty())
    {
        pii top = pi.front();
        pi.pop();

        for(int i=0;i<4;i++)
        {
            tx = top.uu+fx[i];
            ty = top.vv+fy[i];

            if(tx>= 0 and tx<=N and ty>=0 and ty<=N and  vis[tx][ty] == false and cell[tx][ty] != '#' and (cell[tx][ty] == foodweight || cell[tx][ty] == '.'))
            {
                // cout<<tx<<" "<<ty<<"\n";
                vis[tx][ty] = true;
                d[tx][ty] = d[top.uu][top.vv] +1;

                if(cell[tx][ty] >= 65 and cell[tx][ty]<=90)
                {
                    foodcount--;
                    pq.pop();   
                    foodweight = pq.top();
                    cout<<"food "<<foodweight<<"\n";
                }
                if(foodcount == 0) {return d[tx][ty];}

                pi.push({tx,ty});
            }
        }
    }

    return -1;
}


int main()
{
    int T, ansx, ansy, foodcount = 0;
    cin>>T;
    for(int i =1;i<=T;i++)
    {
        cin>>N;
        N--;

        for(int m =0;m<=N;m++)
        {    
            for(int n =0;n<=N;n++)
            {
                char inp;
                cin>>inp;
                if(inp!= '#' && inp!='.')
                {
                    foodcount++;
                    pq.push(inp);
                    if(inp == 'A')
                    {
                        ansx = m;
                        ansy = n;
                    }
                }
                cell[m][n] = inp;
            }
        }
        cout<<"food count "<<foodcount<<"\n";
        int ans = bfs(ansx, ansy, foodcount);
        cout<<"Case "<<i<<": ";(ans == -1 ? cout<<"Impossible\n" : cout<<ans<<"\n" );
        foodcount = 0 ;
    }


    return 0;
}