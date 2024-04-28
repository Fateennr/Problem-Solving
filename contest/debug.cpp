#include<bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x <<"\n";
#else
#define debug(x)
#endif

template<class t>
void __print(vector<t> v1)
{
    cerr<<"[";
    for(t i :v1)
    {
        cerr<< i << " ";
    }
    cerr << "]";
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif


    vector<int> v1 = {1,2,3};

    for(int i :v1)
    {
        cerr << i <<" ";
    }


    int a = 10, b= 20;

    a++;
    
    debug(a);

    return 0;
}