#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define mx 300005

using namespace std;

int segtree[4*mx], lazy[4*mx], arr[mx];
const int MAX = 1e9+7;

void init(int node, int begin, int end)
{
    if(begin>end) return;

    if(begin==end) segtree[node] = arr[begin];
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

void printtree()
{
    for(int i=1;i<3*9;i++)
    {
        cout<<segtree[i]<<" ";
    }
    cout<<"\n";
}

signed main()
{
    int n, q;
    cin>>n>>q;

    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }

    init(1, 1, n);
    printtree();


    while(q--)
    {
        int gg,from, to, x;
        cin>>gg;
        if(gg == 1)
        {
            cin>>from>>x;
            lazy_update(1, 1, n, from, from, x);
            printtree();
        }
        else if(gg == 2)
        {
            cin>>from>>to;
            cout<<query(1,1,n,from,to)<<"\n";
        }
    }
    return 0;
}