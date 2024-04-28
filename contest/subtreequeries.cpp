#include<bits/stdc++.h>

using namespace std;
const int N = 200005;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " "; _print(x); cerr <<"\n";
#define debugarr(x, n) cerr << #x << " "; _print(x, n); cerr <<"\n";
#else
#define debug(x)
#endif

// #ifndef ONLINE_JUDGE
// #else
// #define debug(x)
// #endif


// void __print(int x){ cerr<<x;}
template<class t> void _print(t x){ cerr<<x;}


template<class t>
void _print(vector<t> v1)
{
    cerr<<"[ ";
    for(t i :v1)
    {
        _print(i);
        cerr<<" ";
    }
    cerr << "]";
}

template<class t>
void _print(t v1[], int n)
{
    cerr<<"[ ";
    for(int i=0;i<=n;i++)
    {
        _print(v1[i]);
        cerr<<" ";
    }
    cerr << "]";
}

vector<int> tree[N];
int value[N];
int newvalue[N];
int startnode[N];
int endnode[N];
int newtree[N];
int segtree[4*N];

int i = 0, p =1;

void dfs(int v, int par, vector<int>arr[])
{
    // debug(v);
    startnode[v] = i;
    newvalue[p] = value[v];
    newtree[v] = p;
    p++;
    
    // debug(startnode[v]);
    for(int child : arr[v])
    {
        if(child == par)
        {
            continue;
        }
        // debug(child);

        // depth[child] = depth[v]+1;
        // debug(i);
        i++;
        dfs(child, v, arr);
        // debug(endnode[child]);
    }
    // i++;
    endnode[v] = i+1;
    // debug(endnode[v]);
}



void init(int node, int begin, int end)
{
    if(begin>end) return;

    if(begin==end) segtree[node] = newvalue[begin];
    else
    {
        int left = node*2;
        int right = node*2+1;

        int mid= (begin+end)/2;

        init(left, begin, mid);
        init(right, mid+1, end);

        segtree[node] = (segtree[right]+segtree[left]);
    }
    
}

void lazy_update(int node, int b, int e, int from, int to, int x)
{
    if(b>to || e<from)
    { return;}

    if(b>=from && e<=to)
    {
        segtree[node] = x;
        // newvalue[newtree[from]] = x;
        // debug(newvalue);
        return;
    }
    else
    {
        int left = node*2;
        int right = node*2+1;

        int mid = (b+e)/2;

        lazy_update(left, b, mid, from, to, x);
        lazy_update(right, mid+1, e, from, to, x);

        segtree[node] = segtree[left] + segtree[right];

    }
}


int query(int node, int begin, int end, int from, int to)
{
    if(begin>end) return 0;
    if(begin>to || end<from ) return 0;

    else if(begin>=from && end<=to)
    {
        // cout<<segtree[node]<<"\n";
        return segtree[node];
    }
    else
    {
        int left = node*2;
        int right = node*2+1;

        int mid= (begin+end)/2;

        int q1 = query(left, begin, mid, from, to);
        int q2 = query(right, mid+1, end, from , to);

        // cout<<q1<<" "<<q2<<"\n";

        return q1+q2;  
    }
}



int main()
{
    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++)
    {
        cin>>value[i];

    }

    for(int i= 1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        
        // debug(a);
        // debug(b);

        tree[a].push_back(b);
        tree[b].push_back(a);
    }



    // debug(tree);

    dfs(1, 0, tree);
    // debugarr(startnode, 5);
    // debugarr(endnode, 5);
    // debugarr(newtree, 5);
    // debugarr(newvalue, 5);
    // debugarr(newtree, 5);

    init(1,1,n);





    int c, from, to, x, node, subtreesize;

    for(int i=0;i<q;i++)
    {
        cin>>c>>from;
        node = newtree[from];
        subtreesize = endnode[from]-startnode[from]-1;
        // debug(node);
        // debug(subtreesize);

        if(c == 1)
        {
            cin>>x;
            lazy_update(1, 1, n, node, node, x);
            // debugarr(segtree, 20);
            //point update
        }
        else if(c==2)
        {
            // cin>>to;
            cout<<query(1,1,n, node, node+subtreesize)<<"\n";
            //subtree result
        }
    }
    return 0;
}