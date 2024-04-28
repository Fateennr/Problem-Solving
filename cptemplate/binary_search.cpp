#include<iostream>
#define int long long
#define max  100007
using namespace std;
int arr2[max], inparr[max];


int Iterative_binary_search(int x, int N)
{

    int l, r, m , mid;

    l =0, r = N-1;

    while(l<= r)
    {
        mid = l+(r-l)/2;

        if(x == arr2[mid])
        {
            return mid;
        }
        else if(x > arr2[mid])
        {
            l = mid+1 ;
        }
        else
        {
            r = mid -1;
        }

    }
    return l;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);


    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>inparr[i];
    }

    int T;

    arr2[0] = inparr[0];
    for(int i=1;i<n;i++)
    {
        arr2[i] = arr2[i-1]+inparr[i];
        // cout<<arr2[i]<<"\n";
    }
    cin>>T;
    while(T--)
    {
        int ans;
        cin>>ans;
        cout<<Iterative_binary_search(ans, n)+1<<"\n";
    }


}