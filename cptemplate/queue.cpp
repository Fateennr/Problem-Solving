#include<iostream>

using namespace std;

class Queue
{
    public:
        int Q[5];
        int rear, maxQ, front, Qsize;


        Queue() : rear(0),front(0),Qsize(0)
        { }

        void Enqueue(int x)
        {
            if(Qsize == maxQ)
            {
                cout<<"Enqueue: Overflow"<<endl;
                return ;
            }
            else
            {
                Q[rear] = x;
                rear=(rear+1)%maxQ;
                Qsize++;
                cout<<"EnQueue: ";
                printQueue();

            }
        }

        void isEmpty()
        {
            if(Qsize == 0)
            {
                cout<<"isEmpty: True"<<endl;
            }
            else{
                cout<<"isEmpty: False"<<endl;
            }
        }

        void isFull()
        {
            if(Qsize == maxQ)
            {
                cout<<"isFull: True"<<endl;
            }
            else{
                cout<<"isFull: False"<<endl;
            }
        }

        void Dequeue()
        {
            if(Qsize == 0)
            {
                cout<<"Dequeue: Underflow"<<endl;
                return;
            }
            else
            {
                front=(front+1)%maxQ;
                Qsize--;
                cout<<"DeQueue: ";
                printQueue();
            }
        }

        void printQueue()
        {
            if(Qsize == 0)
            {
                cout<<"Dequeue: Underflow"<<endl;
                return;
            }
 
            for(int i=front; i<front+Qsize;i++)
            {
                cout<<Q[i%maxQ]<<" ";
            }
            cout<<endl;
        }

};

void funcID (Queue &Que, int n)
{
    int inp;

    switch (n)
    {

        case 1: 
            cin>>inp;
            Que.Enqueue(inp);
            break;
        case 2:
            Que.Dequeue();

            break;
        case 3:
            Que.isEmpty();
            break;
        case 4:
            Que.isFull();
            break;
        case 5:
            cout<<"Size: "<<Que.Qsize<<endl;
            break;
        case 6:
            cout<<"Front: "<<Que.Q[Que.front]<<endl;
            break;
        default :
            cout<<"Invalid Number"<<endl;
    }

}


int main()
{
    Queue queue;

    cin>>queue.maxQ;
    int inp;

    while(1)
    {
        cin>>inp;
        if(inp == -1)
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