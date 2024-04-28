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
    int height;
};

binary_tree *root = nullptr;

binary_tree *create_node(int x);
void insertion(int data);
void print_node(binary_tree *Node);
int height(binary_tree* root);
binary_tree *search_node(int key);
binary_tree *Successor(binary_tree *x);
binary_tree *Tree_maximum(binary_tree *x);
binary_tree *Tree_minimum(binary_tree *x); 

int flag =0 ;

binary_tree *Tree_maximum(binary_tree *x)
{
    binary_tree *temp = root;
    while(temp->rightchild != NULL)
    {
        temp = temp->rightchild;
    }

    return temp;
}
binary_tree *Tree_minimum(binary_tree *x)
{
    binary_tree *temp = root;
    while(temp->leftchild != NULL)
    {
        temp = temp->leftchild;
    }


    return temp;
    
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




binary_tree *create_node(int x)
{
    binary_tree *node = new binary_tree;
    node -> data = x;
    node -> parent = NULL;
    node ->  leftchild =NULL;
    node ->  rightchild =NULL;
    node ->height = 0;

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

        if(temp->data < x->data)
        {
            // if(temp->rightchild == NULL)
            // {
            //     target = temp;
            //     break;
            // }
            temp = temp->rightchild;
        }
        else
        {
            // if(temp->leftchild == NULL)
            // {
            //     target = temp;
            //     break;
            // }
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



void print_node_post(binary_tree *Node)
{
    if(Node == NULL) return;

    flag++;

    print_node_post(Node->rightchild);
    print_node_post(Node->leftchild);

    cout<<Node->data<<" ";
    cout <<flag<<"\n";
}

void print_node_post2(binary_tree *Node)
{
    if(Node == NULL) return;

    flag++;

    print_node_post2(Node->rightchild);
    print_node_post2(Node->leftchild);

    cout<<Node->data<<" ";
    cout <<flag<<"\n";
}


int main()
{

    // insertion(10);
    // insertion(5);
    // insertion(1);
    // insertion(7);
    // insertion(20);
    // insertion(25);
    // insertion(22);
    // insertion(21);
    // insertion(27);

    int n;
    cin>>n;
    while(n--)
    {
        int inp;
        cin>>inp;
        print_node_post(search_node(inp));

    }

    return 0;

}

