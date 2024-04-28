#include<bits/stdc++.h>
using namespace std;

#define ll long long 

ll vis[501][501];
char a[501][501];
ll crystal;

ll dx[4] = {-1,0,1,0};
ll dy[4] = {0,-1,0,1};

void dfs(ll x, ll y, ll c, ll n, ll m)
{
	if(x < 0 or x > n-1 or y < 0 or y > m-1)		return;
	if(vis[x][y] || a[x][y] == '#')					return;

	if(a[x][y] == 'C')	crystal++;
	vis[x][y] = c;

	

	for (int i = 0; i < 4; ++i)
	{
		dfs(x + dx[i], y + dy[i], c, n, m);
	}

	return;
}

int main()
{
	//cin.tie(0) -> sync_with_stdio(0);

	int t,tc=1;		scanf("%d", &t);
	while(t--)
	{
		ll m,n,q;	scanf("%lld%lld%lld", &m, &n, &q);
		ll x,y;

		//cout << m << "!! " << n << endl;

		for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                char ch;
                while (1)
                {
                    ch = getchar();
                    if (ch == '#' || ch == '.' || ch == 'C')
                        break;
                }
                a[i][j] = ch;
            }
        }


		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				vis[i][j] = 0;
			}
		}

		ll c = 1;
		ll total[501 * 501] = {0};

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(!vis[i][j] and a[i][j] != '#')
				{
					crystal = 0;
					dfs(i, j, c, m, n);
					total[c] = crystal;
					
					c++;
				}
			}
		}

		printf("Case %d:\n", tc);

		while(q--)
		{
			ll l,r;		scanf("%lld%lld", &l, &r);
			l--,r--;

			printf("%lld\n", total[vis[l][r]]);
		}

		tc++;
	}
}

