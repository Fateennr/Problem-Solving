#include<bits/stdc++.h>
using namespace std;

class TreeAncestor
{
public:
	vector<vector<int>>up;

	int LOG;

	TreeAncestor(int n,const vector<int>&parent)
	{
		// cout<<"gg"<<"\n";
		LOG = ceil(log2(1e9));
		// cout<<LOG<<"\n";

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
		// for(int j=0;j<=LOG;j++)
		// {
		// 	for(int i=0;i<n;i++)
		// 	{
		// 		cout<<up[i][j]<<" ";
		// 	}
		// }
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
};

int main()
{
	int n,q;

	cin>>n>>q;

	vector<int>m;
	m.push_back(-1);
	m.push_back(-1);
	for(int i=2;i<=n;i++)
	{
		int inp;
		cin>>inp;
		m.push_back(inp);
	}


	TreeAncestor ta(n, m);

	int a,b;

	while(q--)
	{
		cin>>a>>b;
		cout<<ta.getKthAncestor(a,b)<<"\n";
	}
    
}