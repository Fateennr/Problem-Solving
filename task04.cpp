#include<bits/stdc++.h>
using namespace std;

deque<char> dd;
stack<char>st;

void solve(string &s1)
{
    int flag = 0;
    for(int i=0;i<s1.size();i++)
    {
        switch(s1[i])
        {
            case '<':
                if(flag==1)
                {
                    if(!st.empty())
                    {
                        st.pop();
                    }
                    continue;
                }
                else
                {
                    if(!dd.empty()) dd.pop_back();
                }
                break;
            case '[':
                while(!st.empty())
                {   
                    char c = st.top();
                    st.pop();
                    dd.push_front(c);
                }
                flag = 1;
                break;
            case ']':
                while(!st.empty())
                {   
                    char c = st.top();
                    st.pop();
                    dd.push_front(c);
                }
                flag = 0;
                break;
            default:
                if(flag == 1)
                {
                    st.push(s1[i]);
                }
                else
                {
                    dd.push_back(s1[i]);
                }

        }
    }
    while(!st.empty())
    {   
        char c = st.top();
        st.pop();
        dd.push_front(c);
    }

    for(auto& c: dd)
    {
        cout<<c;
    }
    cout<<"\n";
}

int main()
{
    int n;
    cin>>n;
    cin.ignore();
    string s1;
    while(n--)
    {
        getline(cin,s1);
        solve(s1);
    }
    return 0;
}