#include<iostream>
#include<stack>
#include<queue>

using namespace std;



struct binary_tree
{
    int data;
    binary_tree *parent;
    binary_tree *rightchild;
    binary_tree *leftchild;
};

binary_tree *root = nullptr;

binary_tree *create_node(int x);
void insertion(int data);
void print_node(binary_tree *Node);


void print_node_level(binary_tree *root)
{
    int p = 1;
    if (root == NULL) return;
 
    queue<binary_tree *> q;
     

    binary_tree *curr;

    q.push(root);
    q.push(NULL);
 
    while (q.size() > 1)
    {
        curr = q.front();
        q.pop();
         
        if (curr == NULL)
        {
           q.push(NULL);
           cout << "\n";
           p++;
            cout<<"Level: "<<p<<": ";
        }
        else {
            if(curr->leftchild)
            q.push(curr->leftchild);
             

            if(curr->rightchild)
            q.push(curr->rightchild);
             
            cout << curr->data << " (";
    
            if (curr->parent != NULL)
            {
                cout << curr->parent->data;
            }
            else
        {
            cout << "null";
        }

            cout << ") ";
        }
    }
}

void print_node(binary_tree *Node)
{
    stack<binary_tree*> s;
    binary_tree* curr = root;
 
    while (curr != NULL || s.empty() == false) {
         
        while (curr != NULL) {

            s.push(curr);
            curr = curr->leftchild;
        }

        curr = s.top();
        // cout<<"top is"<< curr->data<<endl;
        s.pop();
 

    cout <<curr->data << "(";
    
    if (curr->parent != NULL)
    {
        cout << curr->parent->data;
    }
    else
    {
        cout << "N";
    }

    cout << ") ";

        curr = curr->rightchild;
 
    }
    // cout<<endl;

}


void print_node_pre(binary_tree *Node)
{
    // cout<<"in"<<endl;
    if (Node == NULL)
    {
        // cout<<"Empty"<<endl;
        return;
    }
    cout <<Node->data << "(";
    
    if (Node->parent != NULL)
    {
        cout << Node->parent->data;
    }
    else
    {
        cout << "null";
    }

    cout << ") ";

    print_node_pre(Node->leftchild);
    print_node_pre(Node->rightchild);
}


void print_node_post(binary_tree *Node)
{
    if(Node == NULL) return;

    print_node_post(Node->leftchild);
    print_node_post(Node->rightchild);

    if (Node == NULL)
    {
        // cout<<"Empty"<<endl;
        return;
    }
    cout <<Node->data << "(";
    
    if (Node->parent != NULL)
    {
        cout << Node->parent->data;
    }
    else
    {
        cout << "null";
    }

    cout << ") ";
}


binary_tree *create_node(int x)
{
    binary_tree *node = new binary_tree;
    node -> data = x;
    node -> parent = NULL;
    node ->  leftchild =NULL;
    node ->  rightchild =NULL;

    return node;
}

void insertion(int data)
{
    binary_tree *x = create_node(data);

    if(root == NULL) 
    {
        root = x;
        // print_node(root);
        return;
    }

    binary_tree *temp = root;
    binary_tree *target = nullptr;

    while(temp != NULL)
    {
        target = temp;

        if(temp->data < x->data){
            temp = temp->rightchild;
        }else
        {
            temp = temp->leftchild;
        }

    }

    x->parent = target;

    if (x->data < target -> data)
    {
        target->leftchild = x;
    }
    else
    {
        target->rightchild = x;
    }
}



int main()
{
    int N;
    cin>>N;

    for(int i=0;i<N;i++)
    {
        int inp;
        cin>>inp;
        insertion(inp);
    }

    print_node_post(root);


    cout<<"\n";

    return 0;
}

