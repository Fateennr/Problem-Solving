#include<iostream>
#include<stack>

using namespace std;

stack<int>stack1;
stack<int>stack2;

void qstack(int inp)
{
    int n;

    if(inp ==1)
    {
        int size;
        cin>>n;
        stack1.push(n);
        size = stack1.size();
        for(int i=0;i<size;i++)
        {
            // if(!stack1.empty() && !stack2.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        cout<<"Size:"<<stack2.size()<<" Elements: ";

        while(!stack2.empty())
        {
            cout<<stack2.top()<<" ";
            stack1.push(stack2.top());
            stack2.pop();
        }
        cout<<endl;

    }
    else if(inp ==2)
    {
        int size;
        size = stack1.size();
        for(int i=0;i<size;i++)
        {
            // if(!stack1.empty() && !stack2.empty())
            stack2.push(stack1.top());
            stack1.pop();
        }

        stack2.pop();
        cout<<"Size:"<<stack2.size()<<" Elements: ";

        while(!stack2.empty())
        {
            cout<<stack2.top()<<" ";
            stack1.push(stack2.top());
            stack2.pop();
        }
        if(stack1.empty())
        {
            cout<<"NULL"<<endl;
        }
        cout<<endl;

    }

}

int main()
{
    int N,q, inp;
    cin>>N>>q;
    for(int i=0;i<q;i++)
    {
        cin>>inp;
        qstack(inp);
        
    }
    

    return 0;
}