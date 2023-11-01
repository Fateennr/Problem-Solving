#include <bits/stdc++.h>

using namespace std;

int cc_check(string &s1);


int solve(string s) {
    int p = 0;
    int m = cc_check(s);

    while (m != -1 && p<=300) {
        s.insert(m, "01");
        // cout<<"news "<<s<<endl;
        p++;
        m = cc_check(s);
        // cout<<m<<endl;
    }

    if(p>300)
    {
        return -1;
    }
    else
    {
        return p;
    }
}



int cc_check(string &s1)
{
    int m = s1.size();
    for (int i = 0; i < m; i++)
    {
        int zz = m-i-1;
        if (s1[i] == s1[zz])
        {
            if(s1[i] == '1')
            {
                // cout<<"i is "<<i<<endl;
                return i;
            }
            else
            {
                // cout<<"zz is "<<zz<<endl;
                return zz+1;
            }
            
        }
        else
        {
            continue;
        }
    }

    return -1;
}
bool check(string &s1)
{
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] == s1[s1.size()-i-1])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string s;
    int n;
    cin >> n;
    while (n--)
    {
        int n;
        cin>>n;
        cin>>s;

        if (check(s))
        {
            cout <<0<< endl;
        }
        else
        {
            cout<<solve(s)<<endl;
        }
    }

    return 0;
}