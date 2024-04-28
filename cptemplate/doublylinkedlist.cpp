#include<iostream>

using namespace std;

int n =0;

typedef struct node
{
    int data;
    node *next;
    node *prev;

}Node;

Node *head = nullptr;
Node *tail = nullptr;

void Insert_front(int x);
void Insert_back(int key);
void Insert_after_node (int key,  int v);
void Update_node (int key, int v);
void Remove_head ();
void Remove_element (int key);
void Remove_end ();
void printnode();

Node *Createnode(int x)
{
    Node *newnode = new Node;
    newnode-> data = x;
    newnode -> next = NULL;
    newnode -> prev = NULL;

    return newnode;

}

void printnode()
{
    if(n == 0) 
    {
        cout<<"Head: NULL, Tail: NULL, Empty"<<endl;
        return ;
    }


    Node *temp = head;
    if(head != NULL){
        cout<<"Head="<<head->data<<", ";
    }else 
    {
        cout<<"Head= Null,"<<endl;
    }

    cout<<" ";
    
    if(tail != NULL){
        cout<<"Tail= "<<tail->data<<", ";
    }else 
    {
        cout<<"Tail= Null,"<<endl;
    }
    
    if(n==0)
    {
        cout<<"Empty"<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<"\n";
}

void Insert_front(int x)
{
    Node *newnode = Createnode(x);


    if(head == NULL) 
    {
      head = newnode;
      tail = head;
      n++; }
    else 
    {
        newnode -> next = head;
        head = newnode;
        head->prev = NULL;
        tail = newnode->next;
        // cout<<"head data is: "<<head->data<<endl;
        n++;
    }
    
}

void Insert_back(int key)
{
    Node *newnode = Createnode(key);


    if(tail == NULL) 
    {
      head = newnode;
      tail = head;
      n++; }

    else 
    {
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
        tail ->data = key;
        tail ->next = NULL;
        n++;
    }

}

void Insert_after_node (int key,  int v)
{
    Node *newnode = Createnode(key);
    Node *temp = head;
    while(temp != NULL)
    {
        if(temp->data == v)
        {
            break;
        }
        temp = temp->next;
    }
    if(temp == NULL)
    {
        cout<<"Value Not Found."<<endl;
        return;
    }
    if(temp->next == NULL) tail = newnode;
    newnode->next = temp->next;
    newnode->prev = temp;
    temp -> next = newnode;
    n++;

}

void Update_node (int key, int v)
{
    Node *temp = head;
    while(temp != NULL)
    {
        if(temp->data == v)
        {
            temp->data = key;
            break;
        }

        temp = temp->next;
    }
    if(temp == NULL)
    {
        cout<<"Value Not Found."<<endl;
    }

}

void Remove_head ()
{
    if(head == NULL && head == tail) {cout<<"Underflow."<<endl; return ;}
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
    n--;

    // printnode();
}

void Remove_element (int key)
{
    if(head == NULL && head == tail) {cout<<"Underflow."<<endl; return ;}
    Node *temp = head;
    while(temp->next != NULL)
    {
        if(temp->next->data == key)
        {
            break;
        }

        temp = temp->next;

    }

    if(temp->next == NULL)
    {
        cout<<"Value Not Found"<<endl;
        return;
    }
    else
    {
        node *del = temp;
        if(temp->next->next == NULL)
        {
            tail = temp;
            temp->next = NULL;
        }
        else
        {
            del = temp->next;
            temp->next = temp ->next->next;
            temp->next->prev = temp;
            free(del);
        }
    }
    n--;
}


void Remove_end ()
{
    Node *temp = head;

    if(head == NULL && head == tail) {cout<<"Underflow."<<endl; return ;}
    else if(head ==tail)
    {
        node *del = head;
        head = NULL;
        tail = NULL;
        free(del);
        n--;
        return;
    }
    Node *del = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(del);
    n--;
}


void func_id(int n)
{
    switch (n)
    {
    case 1:
        int inp;
        cin>>inp;
        Insert_front(inp);
        printnode();
        break;
    
    case 2:


        cin>>inp;
        Insert_back(inp);
        printnode();
        break;
    
    case 3:

        int key;
        cin>>key>>inp;
        Insert_after_node(key, inp);
        printnode();
        break;
    
    case 4:

        cin>>key>>inp;

        Update_node(key, inp);
        printnode();
        break;
    case 5:

        Remove_head();
        printnode();
        break;

    case 6:
    
        cin>>inp;
        Remove_element(inp);
        printnode();
        break;

    case 7:
    
        Remove_end();
        printnode();
        break;
    
    default:
        cout<<"invalid"<<endl;
    }
    
}


int main()
{
    int num;
    while(1)
    {
        cin>>num;
        if(num == 0) break;

        func_id(num);
    }
    return 0;
}