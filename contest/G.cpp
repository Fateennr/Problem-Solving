#include<bits/stdc++.h>

using namespace std;

const int N = 200005;

int depth[N];
vector<vector<int>>up;
vector<int> pp(N, -1);
vector<vector<int>>m(N);
int value[N];
int LOG;

void TreeAncestor(int n,const vector<int>&parent)
{
		LOG = ceil(log2(4e5));

		up.resize(n+1,vector<int>(LOG+1, -1));

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


	v = getKthAncestor(v, depth[v]-depth[u]);


	if(u == v) return u;


	for(int b = 18; b>=0;b--)
	{

		if(up[u][b] != up[v][b])
		{
			u = up[u][b], v = up[v][b];
		}
	}

	return up[u][0];
	
}


void dfs(int n, int depth[])
{

    for(int child=1;child<=n;child++)
    {
        if(pp[child] == -1)
        {
            continue;
        }

        depth[child] = depth[pp[child]]+1;
    }
}


void dfsgg(int n, int parent, int value[])
{
	int x = value[n];

    for(auto i : m[n])
    {
        if(i != parent)
        {
        	dfsgg(i, n, value);
        	x += value[i];
		}
    }

    value[n] = x;
}




int main()
{
	int n,q;
	cin>>n>>q;


	for(int i=2;i<=n;i++)
	{
        int u,v;
        cin>>u>>v;
        m[u].push_back(v);
        m[v].push_back(u);

        pp[v] = u ;
	}

	// memset(depth, 0 , sizeof(depth));
	dfs(n,depth);
	TreeAncestor(n, pp);

	int a, b;


	while(q--)
	{
		cin>>a>>b;

		int x = lca(a, b);

		value[a] += 1;
		value[b] += 1;
		value[x] -= 1;
		int y = up[x][0];

		if(y != -1) {value[y] -= -1;}
	}

	dfsgg(1, 0, value);

	for(int i=1;i<=n;i++)
	{
		cout<<value[i]<<" ";
	}

	cout<<"\n";


	return 0;
}