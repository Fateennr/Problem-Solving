#include<iostream>
#include<sstream>
#include<unordered_map>

using namespace std;

// int count_unique_substrings(string const& s) 
// {
//     int n = s.size();

//     const int p = 31;
//     const int m = 1e9 + 9;

//     vector<long long> p_pow(n);
//     p_pow[0] = 1;
//     for (int i = 1; i < n; i++)
//         p_pow[i] = (p_pow[i-1] * p) % m;

//     vector<long long> h(n + 1, 0);
//     for (int i = 0; i < n; i++)
//         h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

//     int cnt = 0;
//     for (int l = 1; l <= n; l++) {
//         unordered_set<long long> hs;
//         for (int i = 0; i <= n - l; i++) {
//             long long cur_h = (h[i + l] + m - h[i]) % m;
//             cur_h = (cur_h * p_pow[n-i-1]) % m;
//             hs.insert(cur_h);
//         }
//         cnt += hs.size();
//     }
//     return cnt;
// }



int solve(string s, string goodarr, int goodlimit)
{
    int reslim = 0, gg=0;

    unordered_map<string> map;

    for(int i=0;i<s.size();i++)
    {
        string m = "";

        for(int j=i;i<s.size;j++)
        {
            int ind = (s[i] - 'a');

            if(s[ind] == 0)
            {
                reslim++;
            }

            if(reslim>goodlimit) 
            {
                reslim =0 ;
                break;
            }

            m+= s[i];

            if(map.find(m) == map.end())
            {


                map.insert(m);
                gg++;
            }

        }
    }


    return gg;

}



int main()
{

    string s;
    string goodarr;
    int goodlimit, goodarrnum;

    cin>>s; 
    cin>>goodarr;
    cin>>goodlimit;


    cout<<solve(s, goodarr, goodlimit)<<"\n";

    return 0;
}