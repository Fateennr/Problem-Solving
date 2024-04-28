#include<bits/stdc++.h>

using namespace std;

const int N = 200005;

int depth[N];

vector<int>m(N, -1);
vector<vector<int>>up;

int LOG;

void TreeAncestor(int n,const vector<int>&parent)
{
		// cout<<"gg"<<"\n";
		LOG = ceil(log2(4e5));
		// cout<<LOG<<"\n";

		up.resize(n+1,vector<int>(LOG+1, -1));
		// cout<<"gg\n";

		for(int i=1;i<=n;i++)
		{
			up[i][0]= parent[i];
		}

		for(int j=1;j<LOG;j++)
		{
			for(int i=1;i<=n;i++)
			{
				if(up[i][j-1]!=-1)
				{

					up[i][j] = up[up[i][j-1]][j-1];

				}
				else
				up[i][j] = -1;
			}
		}
		// for(int j=0;j<=LOG;j++)
		// {
		// 	for(int i=0;i<n;i++)
		// 	{
		// 		cout<<up[i][j]<<" ";
		// 	}
		// }

		// return 0;
}

	int getKthAncestor(int node, int k)
	{
		if(k==1)
		{
			return up[node][0];
		}

		int ans = node;
		for(int j=0;j<=LOG;j++)
		{
			if(k&(1<<j))
			{
				ans = up[ans][j];
				if(ans == -1)
				{
					break;
				}

				k-=(1<<j);
			}
		}


		return ans;
	}



int lca(int u, int v)
{
	if(depth[u] > depth[v]) swap(u,v);

	// cout<<v<<"gg\n";

	v = getKthAncestor(v, depth[v]-depth[u]);
	// cout<<v<<"gg\n";


	if(u == v) return u;

	// cout<<LOG-1<<"\n"; 

	for(int b = 18; b>=0;b--)
	{
		// cout<<b<<"\n";

		if(up[u][b] != up[v][b])
		{
			// cout<<"enter\n";
			u = up[u][b], v = up[v][b];

			// cout<<u<<" "<<v<<"\n";
		}
	}

	return up[u][0];

	// return v;
	
}

    int dis(int u, int v)
    {
        int g = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[g];
    }


void dfs(int n, int depth[])
{

    for(int child=1;child<=n;child++)
    {
        if(m[child] == -1)
        {
            continue;
        }

        depth[child] = depth[m[child]]+1;
        // height[v] = max(height[v], height[child]+1);
    }
}

int main()
{
	int n,q;
	cin>>n>>q;

	// m.push_back(-1);
	// m.push_back(-1);

	for(int i=2;i<=n;i++)
	{
		int inp1, inp2;
		cin>>inp1>>inp2;

		m[inp2] = inp1;
	}

	memset(depth, 0 , sizeof(depth));
	dfs(n,depth);

	// for(int i=1;i<=n;i++)
	// {
	// 	cout<<depth[i]<<" ";
	// }

	// cout<<"\n";

	// for(int i=1;i<=n;i++)
	// {
	// 	cout<<m[i]<<" ";
	// }

	TreeAncestor(n, m);

	// cout<<"\n"<<getKthAncestor(4, 2);
	int a, b;

	// cout<<"\n"<<depth[2]<<" "<<depth[5]<<"\n";

		// for(int j=0;j<=LOG;j++)
		// {
		// 	for(int i=0;i<n;i++)
		// 	{
		// 		cout<<up[i][j]<<" ";
		// 	}
		// }


	while(q--)
	{
		cin>>a>>b;
		cout<<dis(a,b)<<"\n";
	}


	return 0;
}