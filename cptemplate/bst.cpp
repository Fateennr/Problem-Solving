#include<iostream>
#include<stack>
#include<queue>

using namespace std;
int flag = 0;


struct binary_tree
{
    int data;
    binary_tree *parent;
    binary_tree *rightchild;
    binary_tree *leftchild;
    int height = 0;
};

binary_tree *root = nullptr;

binary_tree *create_node(int x);
void insertion(int data);
void print_node(binary_tree *Node);
void balance_node(binary_tree *y, int bf, binary_tree *newnode);
int balance_factor(binary_tree *temp);
int height(binary_tree* root);
void left_rotate(binary_tree *y);
void right_rotate(binary_tree *y);
binary_tree *search_node(int key);


//initiating node
binary_tree *create_node(int x)
{
    binary_tree *node = new binary_tree;
    node -> data = x;
    node -> height = 0;
    node -> parent = NULL;
    node ->  leftchild =NULL;
    node ->  rightchild =NULL;

    return node;
}

//in main function taking input key and calling the insertion function
void insertion(int data)
{
    binary_tree *x = create_node(data); // creating a node pointer without any connection

    // cout<<"entry";

    if(root == NULL) 
    {
        root = x;
        print_node(root);
        return;
    }

    binary_tree *target = nullptr;
    binary_tree *temp = root; // for insertion taking two pointer temp and target to track the insertion path in the treee

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

    //after this temp must be NULL and target will be the last node where temp node will attach

    x->parent = target; //target will be the parent of x

    if (x->data < target -> data)
    {
        target->leftchild = x; 
    }
    else
    {
        target->rightchild = x;
    }

    //updating height
    temp = x ;
    while(temp != NULL)
    {
        height(temp);
        temp = temp->parent;
    }

    print_node(root);

    //balancing node
    temp = x;
    // cout<<"temp "<<temp->data;
    while(temp != NULL)
    {
        // cout<<"1"<<endl;
        int bf = balance_factor(temp);  //checking the imbalance in the tree
        // cout<<"bf "<<bf<<endl;

        if(bf < -1 || bf> 1){
            // cout<<"bf "<<bf<<endl;
            cout<<"Imbalance at node: "<<temp->data<<endl;
            balance_node(temp, bf, x); //temp = y 
            break;
        }
        temp = temp->parent;
    }
    if(flag == 0) {cout<<"Balanced"<<endl;}
    else {flag = 0;}

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
 
        cout << curr->data << "(";
        // if(curr->parent != NULL) {cout<<curr->parent->data<<") ";}
        // else {cout<<"null) ";}
        cout<<balance_factor(curr)<<") ";
 
        curr = curr->rightchild;
 
    }

    cout<<endl;
}

binary_tree *search_node(int key)
{
    binary_tree *temp = root;

    while(temp != NULL)
    {
        if(temp->data >key)
        {
            temp = temp->leftchild;
        }
        else if(temp->data < key)
        {
            temp = temp->rightchild;
        }
        else
        {
            break;
        }

    }

    return temp ;
}

int height(binary_tree* root)
{
    queue<binary_tree*> nodesInLevel;

    int height = -1;
    int nodeCount = 0;
    binary_tree *currentNode;

    if (root == NULL) 
    {
        return -1;
    }
    nodesInLevel.push(root);
    while (!nodesInLevel.empty()) {

        height++;

 
        nodeCount = nodesInLevel.size();
        while (nodeCount--) {
            currentNode = nodesInLevel.front();
 

            if (currentNode->leftchild != NULL) {
                nodesInLevel.push(currentNode->leftchild);
            }
            if (currentNode->rightchild != NULL) {
                nodesInLevel.push(currentNode->rightchild);
            }

            nodesInLevel.pop();
        }
    }
    return root->height = height;
}

int balance_factor(binary_tree *temp)
{
    int left = height(temp->leftchild);
    int right = height(temp->rightchild);   
    return left - right;
}

void left_rotate(binary_tree *y) 
{                                                
    binary_tree *x = y->rightchild;
    binary_tree *xL = x->leftchild;

    x->parent = y->parent;

    if( y ==  root)
    {
        root=x;
    }
    else if(y == y->parent->leftchild)
    {
        y->parent->leftchild = x;
    }else
    {
        y->parent->rightchild = x;
    }

    x ->leftchild = y;
    y->parent = x;

    y->rightchild = xL;

    if(xL != NULL)
    {
        xL->parent = y;
    }

    // cout<<"done"<<endl;
}

void right_rotate(binary_tree *y)
{

    binary_tree * x = y ->leftchild;
    binary_tree * xR = x->rightchild;

    x->parent = y->parent;
    if(y == root)
    {
        root = x;
    }
    else if(y == y->parent->leftchild)
    {
        y->parent->leftchild = x;
    }
    else
    {
        y->parent->rightchild = x;
    }

    x->rightchild = y;
    y->parent = x;
    y->leftchild = xR;
    if(xR != NULL)
    {
        xR->parent = y;
    }

    // //updating height
    // binary_tree* temp = y ;
    // while(temp != NULL)
    // {
    //     update_height(temp);
    //     temp = temp->parent;
    // }

}

void balance_node(binary_tree *y, int bf, binary_tree *newnode) //balance node checks 4 scenerio where the nodes should be balanced
{
    flag = 1;
    //RR
    if(bf>1 && newnode->data< y->leftchild->data)
    {
        cout<<"LL Case\nright_rotate("<<y->data<<")"<<endl;

        right_rotate(y);
    }
    else if(bf >1 && newnode->data > y->leftchild->data) //LR
    {
        cout<<"LR Case\nLeft_rotate("<<y->leftchild->data<<"), ";
        cout<<"right_rotate("<<y->data<<")"<<endl;

        left_rotate(y->leftchild);
        right_rotate(y);
    }
    else if(bf<-1 && newnode->data> y->rightchild->data) //LL
    {
        cout<<"RR Case\nright_rotate("<<y->data<<")"<<endl;

        // cout<<"1"<<endl;
        left_rotate(y);
    }
    else if(bf <-1 && newnode->data < y->rightchild->data) //RL
    {
        cout<<"RL Case\nright_rotate("<<y->rightchild->data<<"), ";
        cout<<"Leftt_rotate("<<y->data<<")"<<endl;
        right_rotate(y->rightchild);
        left_rotate(y);
    }

    // cout<<"balanced"<<endl;
    cout<<"Status: ";
    print_node(root);

}

int main()
{
    while(1)
    {
        int inp;
        cin>>inp;
        if(inp == -1)
        {
            cout<<"Status: ";
            print_node(root);
            break;
        }else
        {
            insertion(inp);
            // cout<<endl;
            cout<<"Root="<<root->data<<endl;
        }
    }

    return 0;
}