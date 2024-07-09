#include <bits/stdc++.h>
using namespace std;
#define m 1000010

long long int primes[m], cnt, siv[m];

void sieve()
{
    long long int i, j;
    for (i=3; i<m; i+=2)
        if(!siv[i])
            for (j=i*i; j<m; j+=i+i)
                siv[j]=1;
    primes[cnt++]=2;
    for (i=3; i<m; i+=2)
        if(!siv[i]) primes[cnt++]=i;
    return;
}



int main()
{
    sieve();
    long long int t,c=0;
    scanf("%lld",&t);
    while(t--)
    {
        long long int n,sum=1,s,k,i;
        scanf("%lld",&n);

        // finding the number of divisors of N
        for(i=0;i<m && primes[i]*primes[i]<=n;i++)
        {
            if(n%primes[i]==0)
            {
                k=0;
                while(n%primes[i]==0)
                {
                    n/=primes[i];
                    k++;
                    if(n==0 || n==1)
                        break;
                }
                sum*=k+1;
            }

        }

        /* If the number N is divided by a prime number than the
        sum has to be multiped by (1+1) where first 1 is the count of
        that prime number, N is divisible by and second 1 is the plus one
        of the formula. */

        if(n!=1)
            sum*=2;
        printf("Case %lld: %lld\n",++c,sum-1);
    }
    return 0;
}



// #include<bits/stdc++.h>

// #define int long long

// using namespace std;

// int m = 1e6+10, cnt = 0;
// vector<bool> is_prime(m, false);
// vector<int> primes(m, 0); //array of primes


// void sieve()
// {
//     is_prime[0] = is_prime[1] = 1;

//     for (int i = 2; i*i <= m; i++) 
//     {

//         if (!is_prime[i]) 
//         {

//             for (int j = i * i; j <= m; j += i)
//             {
//                 is_prime[j] = true;

//             }
//         }

//     }
    
//     primes[cnt++] = 2;
    
//     for(int i=3;i<=m;i+=2)
//     {
//         if(!is_prime[i])
//         {
//             primes[cnt++] = i;

//             // cout<<primes[cnt-1]<<"\n";
            
//         }
//     }
// }


// signed main()
// {
//     int t;
//     cin>>t;

//     sieve();

//     for(int i=1;i<=t;i++)
//     {
//         int sum = 1;
//         int n;
//         cin>>n;

//         int k = n;

//         if(!is_prime[k])
//         {
//             cout<<"Case"<<" "<<i<<": 1\n";
//         }
//         else
//         {
//             for(int j=0;j<m&& primes[j]*primes[j] <= k;j++)
//             {
//                 // cout<<"aaa "<<primes[j]<<"\n";

//                 if(n%primes[j]==0){


//                     int cnt = 0;

//                     while(n%primes[j] == 0)
//                     {
//                         n /= primes[j];
//                         cnt++;

//                     }

//                     // cout<<"n is "<<n<<"\n";
//                     sum *= (cnt+1);

//                     // cout<<"sum is "<<sum<<"\n";
//                     // cout<<primes[j]<<"\n";
//                 } 
//             }
            
//             cout<<"Case"<<" "<<i<<": "<<sum-1<<"\n";
            
//         }
//     }


//     return 0;

// }