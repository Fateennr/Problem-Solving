#include<iostream>
#include<vector>

using namespace std;
int size;
int top = -1;
int stack[100];
int Max;

class Stack
{

    public:

        void push(int c)
        {

            if (size == Max)
            {
                cout<<"Overflow"<<endl;
                return ;
            }
            top++;
            size++;
            // cout<<"entered. now size is "<<size<<endl;
            stack[top] = c;
            for (int i=0;i<size;i++)
            {

                cout<<stack[i]<<" ";
            }

            cout<<endl;

        }

        bool isEmpty()
        {
            return top == -1;
        }
        bool isFull()
        {
            return top == Max;        
        }

        void pop()
        {
            if (top == -1)
            {
                cout<<"Underflow"<<endl;
                return ;
            }
            cout<<stack[top]<<endl;
            top --;
            size--;
            for (int i=0;i<size;i++)
            {

                cout<<stack[i]<<" ";
            }
            cout<<endl;

        }

        int Size()
        {
            return size;
        }

};

void funcID(int n, Stack mystack)
{
    int inp;
    if (n ==1)
    {
        cin>>inp; 
        mystack.push(inp);
    }
    else if (n==2)
    {
        mystack.pop();
    }
    else if (n == 3)
    {
        if(mystack.isEmpty() == 1) {cout<<"True"<<endl;}
        else if(mystack.isEmpty() == 0) {cout<<"False"<<endl;}
    }
    else if(n ==4)
    {
        if(mystack.isFull() == 1) {cout<<"True"<<endl;}
        else if(mystack.isFull() == 0) {cout<<"False"<<endl;}
    }
    else if (n ==5)
    {
        cout<<mystack.Size()<<endl;
    }
    else if (n==6)
    {
        cout<<stack[top]<<endl;
    }
    else 
    {
        cout<<"Invalid"<<endl;
    }
}


int main()
{

    Stack mystack;
    // cout<<"input max: ";
    cin>>Max;
    int inp;
    while(1)
    {
        cin>>inp;

        if(inp == -1)
        {
            break;
        }
        funcID(inp , mystack);

    }
    return 0;
}
