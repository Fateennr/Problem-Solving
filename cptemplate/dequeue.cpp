#include<iostream>

using namespace std;

class Deque
{
    public:
        int Q[5];
        int rear, maxQ, front, Qsize;


        Deque() : rear(-1),front(-1),Qsize(0), maxQ(5)
        { }

        void push_front(int x)
        {
            if(Qsize == maxQ)
            {
                cout<<"Overflow"<<endl;
                return;
            }
            if(rear == -1 && front == -1)
            {
                front =0;
                rear = 0;
                Q[front] = x;
                Qsize++;
                printQueue();

            }
            else if(front == 0)
            {
                front = maxQ -1;
                Q[front] =x;
                Qsize++;
                printQueue();
            }
            else 
            {
                front--;
                Q[front] = x;
                Qsize++;
                printQueue();
            }
        }
        void push_back(int x)
        {
            if(rear == -1 && front == -1)
            {
                front =0;
                rear = 0;
                Q[front] = x;
                Qsize++;
                printQueue();

            }
            else if(rear == maxQ-1)
            {
                rear =0;
                Q[rear] = x;
                Qsize++;
                printQueue();

            }
            else
            {
                rear++;
                Q[rear] = x;
                Qsize++;
                printQueue();
            }
        }
        void pop_front()
        {
            if(Qsize == 0)
            {
                cout<<"Dequeue: Underflow"<<endl;
                return;
            }
            if(front == rear)
            {
                front = -1;
                rear = -1;
                Qsize = 0;
                printQueue();
            }
            else if(front == maxQ-1)
            {
                front= 0;
                Qsize--;
                printQueue();
            }
            else
            {
                front++;
                Qsize--;
                printQueue();

            }
        }

        void pop_back()
        {
            if(Qsize == 0)
            {
                cout<<"Dequeue: Underflow"<<endl;
                return;
            }
            if(front == rear)
            {
                front = -1;
                rear = -1;
                Qsize = 0;
                printQueue();
            }
            else if(rear == 0)
            {
                rear = maxQ-1;
                Qsize--;
                printQueue();
            }
            else
            {
                rear--;
                Qsize--;
                printQueue();

            }
        }

        void printQueue()
        {
            if(Qsize == 0)
            {
                cout<<"Underflow"<<endl;
                return;
            }
 
            for(int i=front; i<front+Qsize;i++)
            {
                cout<<Q[i%maxQ]<<" ";
            }
            cout<<endl;
        }

};

void funcID (Deque &Que, int n)
{
    int inp;

    switch (n)
    {

        case 1: 
            cin>>inp;
            Que.push_front(inp);
            break;
        case 2:
            cin>>inp;
            Que.push_back(inp);
            break;
        case 3:
            Que.pop_front();
            break;
        case 4:
            Que.pop_back();
            break;
        case 5:
            cout<<Que.Qsize<<endl;
            break;
        default :
            cout<<"Invalid Number"<<endl;
    }

}


int main()
{
    Deque queue;
    int inp;

    while(1)
    {
        cin>>inp;
        if(inp == 6)
        {
            cout<<"Exit"<<endl;
            break;
        }
        else
        {
            funcID(queue, inp);
        }

    }
 return 0;   
}