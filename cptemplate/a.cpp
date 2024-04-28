#include <bits/stdc++.h>


using namespace std;
deque<char>dd;
stack<char>st;

int main()
{


    dd.push_back(' ');
    dd.push_back(' ');
    dd.push_back('g');
    st.push(' ');
    st.push(' ');
    st.push('c');

    for(auto& c: dd)
    {
        cout<<c;
    }
    while(!st.empty())
    {
        char c = st.top();
        st.pop();
        cout<<c<<"\n";
    }
}
