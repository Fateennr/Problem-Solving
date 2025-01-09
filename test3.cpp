#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    vector<char> vowels = { 'a', 'e', 'i', 'o', 'u' };

    while(t--)
    {
        int n;
        cin>>n;
        string s = "";

        int gg = n%5 ;
        int repeatation = n/5;

        for(int i=0;i<5;i++)
        {
            int printcount = repeatation + (gg > i);

            for(int j=0; j<printcount;j++)
            {
                s += vowels[i];
            }

        }
        cout << s <<"\n";
    }



    return 0;
}