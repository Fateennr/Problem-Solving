#include<bits/stdc++.h>

using namespace std;


int Iterative_binary_search(int x, int N, int arr2[], int newans)
{

    int l, r, m , mid;

    l =newans+1, r = N-1;

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

int solve(int n, int dullah[], int noshin[])
{
    int gg=0;
    sort(dullah, dullah+n);
    sort(noshin, noshin+n);

    int newans =0;
    for(int i=0;i<n;i++)
    {
        int ans = Iterative_binary_search(noshin[i], n, dullah, newans);
        gg++;
        if(ans==n-1)
        {
            // cout<<dullah[ans]<<" "<<noshin[ans]<<"\n";
            if(dullah[ans] <noshin[i])
            {
                gg--;
            }
            break;
        }
        newans = ans;

    }

    return gg;

}

int main()
{
    int n;
    cin>>n;

    int dullah[100005], noshin[100005];

    for(int i=0;i<n;i++)
    {
        cin>>dullah[i];
    }

    for(int i=0;i<n;i++)
    {
        cin>>noshin[i];
    }


    cout<<solve(n, dullah, noshin)<<"\n";

}