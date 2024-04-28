#include<iostream>
#define int long long
#define max 1000000+7

using namespace std;


signed main()
{
    int arr[max];
    int m,n, sum =0;
    cin>>n;
    while(n--)
    {
        cin>>m;

        if(m ==1)
        {
            int ans;
            cin>>ans;
            cout<<ans-1<<"\n";
            continue;
        }

        cin>>arr[0];

        for(int i=1;i<m;i++)
        {
            cin>>arr[i];

            int diff = arr[i-1]-arr[i];
            if(diff>0)
            {
                sum+=diff;
            }

        }

        cout<<sum<<"\n";
        sum = 0;

    }
    return 0;
}