#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"
int flag, newVal;

template<typename node, typename change> //node and change are two datatypes kind off for templates
class SegmentTree
{
public:
    int n;
 
    node *tree, identity; 
    node (*merge)(node, node); // function pointers, like a pointer variable to call a function

 
    change *lazy, noChange;
    void (*applyUpdate)(int, int, node&, change); //funcpointers
    void (*mergeUpdate)(int, int, change&, change); //functionpointers
 
    void build(vector<node> &input, int lo, int hi, int root=0)
    {
        if(lo==hi)
        {
            tree[root]=input[lo];
            return;
        }
 
        int mid=lo+hi>>1, leftChild=2*root+1, rightChild=2*root+2;
        build(input, lo, mid, leftChild);
        build(input, mid+1, hi, rightChild);
 
        tree[root]=merge(tree[leftChild], tree[rightChild]);
    }
 
    void propagate(int lo, int hi, int root, change lazy[])
    {
        applyUpdate(lo, hi, tree[root], lazy[root]);
 
        if(lo<hi)
        {
            int mid=lo+hi>>1, leftChild=2*root+1, rightChild=2*root+2;
 
            mergeUpdate(lo, mid, lazy[leftChild], lazy[root]);
            mergeUpdate(mid+1, hi, lazy[rightChild], lazy[root]);
        }
 
        lazy[root]= noChange;       

        // for(int i=0;i<4*n;i++)
        // {
        //     cout<<lazy[i].first<<" "<<lazy[i].second<<"\n";
        // }
        // cout<<"\n";
    }
 
    void update(int from, int to, int lo, int hi, int root, change delta)
    {
        // cout<<"update \n";
        if(lo>hi) return;
        
        propagate(lo, hi, root, lazy);
        if(from>hi || to<lo) return;
 
        if(from<=lo && to>=hi)
        {
        mergeUpdate(lo, hi, lazy[root], delta);
        propagate(lo, hi, root, lazy);
        for(int i=0;i<4*n;i++)
        {
            cout<<lazy[i].first<<" "<<lazy[i].second<<"\n";
        }
        cout<<"\n";
            return;
        }
 
        int mid=lo+hi>>1, leftChild=2*root+1, rightChild=2*root+2;
        update(from, to, lo, mid, leftChild, delta);
        update(from, to, mid+1, hi, rightChild, delta);
 
        tree[root]= merge(tree[leftChild], tree[rightChild]);
        // cout<<"root "<<tree[root]<<"\n";
 
    }
 
    node query(int from, int to, int lo, int hi, int root)
    {
        if(lo>hi) return identity; 
        
        propagate(lo, hi, root, lazy);
        if(from>hi || to<lo) return identity;
 
        if(from<=lo && to>=hi) 
        {
            // cout<<"\nmatch is "<<root<<"\n";
            return tree[root];
        }
        
        int mid=lo+hi>>1, leftChild=2*root+1, rightChild=2*root+2;
        node q1=query(from, to, lo, mid, leftChild), q2=query(from, to, mid+1, hi, rightChild);
        return merge(q1, q2);
    }
 
public:
    SegmentTree(SegmentTree& st): tree(st.tree), lazy(st.lazy), n(st.n),merge(st.merge), identity(st.identity),applyUpdate(st.applyUpdate), mergeUpdate(st.mergeUpdate), noChange(st.noChange)
    {} //giving the contents of st in the initializer list
 
    SegmentTree(vector<node> &input, node (*merge)(node, node), node identity, void (*applyUpdate)(int, int, node&, change), void (*mergeUpdate)(int, int, change&, change), change noChange): n(input.size()), merge(merge), identity(identity), applyUpdate(applyUpdate), mergeUpdate(mergeUpdate), noChange(noChange)
    {
        tree=new node[n<<2]; // node type array with 4*n size
        build(input, 0, n-1);
        // for(int i=0;i<n;i++)
        // {
        //     cout<<tree[i]<<" ";
        // }
 
        lazy=new change[n<<2]; 
        fill(lazy, lazy+(n<<2), noChange); //datatype of change is no change 
        //fill is a std library for filling the array with values, starting from 0 to 4n here
    }
 
    node query(int from, int to)
    {
        if(from>to || to>n) return identity;
        return query(from, to, 0, n-1, 0);
    }
 
    void update(int from, int to, change delta)
    {
        update(from, to, 0, n-1, 0, delta);
    }
 
    ~SegmentTree()
    {
        delete[] tree;
        delete[] lazy;
    }
};
 
void pre()
{
    fastio;   
}
 
int sumVal(int a, int b) //what to do with tree //basically merge  function of tree is doing this
{
    return a+b;
}
 
void applyReplace(int lo, int hi, int& val, pair<int,int> delta) // main function to apply a replace
{
    flag= delta.first;
    newVal=delta.second;
    // cout<<"flag is "<<flag<<"\n";
    if(flag != 0)
    {
        cout<<"ggflag under apply is "<<flag<<" "<<newVal<<"\n";
        cout<<"value is "<<val<<"\n";


        val*=flag;
        val+=newVal;

        cout<<"val "<<val<<"\n";
    }
}
 
void mergeReplace(int lo, int hi, pair<int,int>& delta1, pair<int,int> delta2) //function for passing the update to the child in the lazy tree
{
    // cout<<"ggflag is "<<flag<<"\n";

    flag=delta2.first;
    newVal=delta2.second;

    if(flag!=0) 
    {
        delta1=delta2;
        // cout<<"changesmerge\n"<<flag<<" "<<newVal<<"\n";
    }

}
 
void solve(int tc)
{
    int n, q,b,c, l, r,t;
    cin >> n >> q;
 
    vector<int> v(n);
    for(auto &it: v) cin >> it;
    // for(int i=0;i<n;i++) 
    // {
    //     cout<<v[i]<<" ";
    // }
    // cout<<"\n";
 
    pair<int,int> noChange= {0, 0}, delta; //no change variable is used if we dont need to cahnge anything in the tree
    SegmentTree<int, pair<int,int>> st(v, sumVal, 0, applyReplace, mergeReplace, noChange); //default value for tree is needed to change
 
    for(int i=0;i<q;i++)
    {
        cin >>t>>l>>r;
 
        if(t==0)
        {
            cin>>b>>c; 
 
            delta = {b, c}; // flag=true, value = u 
            //delta is the pair to update the value to u
            st.update(l, r-1, delta); // from=k, to=k, delta=delta
        }
        else if(t==1)
        {
            // cout<<"in";
            cout << st.query(l, r-1)%998244353 << endl;
        }
    }
}
 
signed main()
{
    pre();
 
    int tc, tt=1;
    // cin >> tt;
    
    for(tc=1; tc<=tt; tc++)
    {
        solve(tc);
        // cout << endl;
    }
 
    return 0;
}