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
void balance_node(binary_tree *y, int bf, binary_tree *newnode);
int balance_factor(binary_tree *temp);
int height(binary_tree* root);
void left_rotate(binary_tree *y);
void right_rotate(binary_tree *y);
binary_tree* LCA(binary_tree *root, int n1, int n2);
binary_tree *search_node(int key);


void solve(int n1, int n2)
{

    binary_tree *gg = LCA(root, n1, n2);


    binary_tree *temp1 = search_node(n1);
    binary_tree *temp2 = search_node(n2);

    while(temp1->data != gg->data)
    {
        cout<<temp1->data<<" ";
        temp1 = temp1->parent;
    }

    // cout<<gg->data<<" ";

    while(gg->data != temp2->data)
    {
        cout<<gg->data<<" ";
        if(gg->data < temp2->data) {gg = gg->rightchild;}
        else if(gg->data > temp2->data) {gg = gg->leftchild;}
    }

    cout<<gg->data<<endl;

}


binary_tree* LCA(binary_tree *root, int n1, int n2) //determining latest common ancestor
{
    binary_tree *temp = root;
    while(temp != NULL)
    {
        if(temp->data < n1 && temp->data < n2)
        {
            temp = temp->rightchild;
        }
        else if(temp->data > n1 && temp->data > n2)
        {
            temp = temp->leftchild;
        }
        else
        {
            break;
        }
    }

    return temp;
}

//initiating node
binary_tree *create_node(int x)
{
    binary_tree *node = new binary_tree;
    node -> data = x;
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
        // print_node(root);
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
            balance_node(temp, bf, x); //temp = y 
            break;
        }

        temp = temp->parent;
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
 
        cout << curr->data << "(";
        // if(curr->parent != NULL) {cout<<curr->parent->data<<") ";}
        // else {cout<<"null) ";}
        cout<<height(curr)<<") ";
 
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
    return height;
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
    //RR
    if(bf>1 && newnode->data< y->leftchild->data)
    {
        right_rotate(y);
    }
    else if(bf >1 && newnode->data > y->leftchild->data) //LR
    {
        left_rotate(y->leftchild);
        right_rotate(y);
    }
    else if(bf<-1 && newnode->data> y->rightchild->data) //LL
    {
        // cout<<"1"<<endl;
        left_rotate(y);
    }
    else if(bf <-1 && newnode->data < y->rightchild->data) //RL
    {
        right_rotate(y->rightchild);
        left_rotate(y);
    }

    // cout<<"balanced"<<endl;
}


int main()
{
    while(1)
    {
        int inp;
        cin>>inp;
        if(inp == -1)
        {
            break;
        }else
        {
            insertion(inp);
            // cout<<endl;
        }
    }
    print_node(root);
    cout<<endl;

    while(1)
    {
        int n1, n2;
        cin>>n1>>n2;
        if(n1 == -1 || n2 == -1)
        {
            break;
        }
        solve(n1, n2);
    }


    return 0;
}