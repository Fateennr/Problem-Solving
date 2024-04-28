#include <iostream>

using namespace std;

struct binary_tree
{
    int data;
    binary_tree *parent;
    binary_tree *leftchild;
    binary_tree *rightchild;
};

binary_tree *search_node(binary_tree *Node, int data);
void create_node(int data, int parent, int childno);
void print_node(binary_tree *Node);
void func_id(int n);
void removal(int key);
int getheight(binary_tree *Node);

binary_tree *root = nullptr; // initialising root

int getheight(binary_tree *Node)
{
    if (Node == NULL)
    {
        return -1;
    }

    int left = getheight(Node->leftchild);
    int right = getheight(Node->rightchild);

    int height = max(left, right) + 1;

    return height;
}

void print_node(binary_tree *Node)
{
    if (Node == NULL)
    {
        return;
    }
    cout << Node->data << "(";

    if (Node->parent != NULL)
    {
        cout << Node->parent->data;
    }
    else
    {
        cout << "N";
    }

    cout << ") ";

    print_node(Node->leftchild);
    print_node(Node->rightchild);
}

binary_tree *search_node(binary_tree *Node, int data)
{
    if (Node == NULL)
    {
        return NULL;
    }
    // cout<<"gg"<<Node->data<<endl;

    binary_tree *temp = Node;
    if (temp->data == data)
    {
        return Node;
    }
    else
    {
        temp = search_node(Node->leftchild, data);
        if (temp == NULL)
        {
            temp = search_node(Node->rightchild, data);
        }
    }

    return temp;
}

void create_node(int data, int parent, int childno)
{
    binary_tree *newnode = new binary_tree;
    newnode->data = data;
    newnode->leftchild = NULL;
    newnode->rightchild = NULL;
    newnode->parent = NULL;

    if (parent == 0)
    {
        // cout << "if loop" << endl;
        root = newnode;
    }
    else
    {
        // cout << "else loop" << endl;
        binary_tree *temp = search_node(root, parent);
        // cout << temp->data << endl;
        if (temp == NULL)
        {
            cout << "Not found" << endl;
            return;
        }
        else
        {
            // newnode->data = data;
            newnode->parent = temp;
            if (childno == 1)
            {
                temp->leftchild = newnode;
            }
            else if (childno == 2)
            {
                temp->rightchild = newnode;
            }
            else
            {
                cout << "invalid childno" << endl;
                return;
            }
        }
    }
}

void removal(int key)
{
    binary_tree *temp = search_node(root, key);
    binary_tree *del = temp;
    if (temp != NULL)
    {
        if (temp->parent->leftchild == temp)
        {
            temp = temp->parent;
            temp->leftchild = NULL;
        }
        else
        {
            temp = temp->parent;
            temp->rightchild = NULL;
        }
    }
    free(del);

    print_node(root);
    cout << " (preorder)\n";
}

void func_id(int n)
{
    int inp;
    binary_tree *temp;
    switch (n)
    {
    case 2:
        cin >> inp;
        removal(inp);
        break;

    case 3:

        cin >> inp;
        temp = search_node(root, inp);
        if (temp == NULL)
        {
            cout << "Not present." << endl;
        }
        else
        {
            cout << "Present, Left(";

            if (temp->leftchild != NULL)
            {
                cout << temp->leftchild->data;
            }
            else
            {
                cout << "null";
            }

            cout << ") ";

            cout << "Right(";

            if (temp->rightchild != NULL)
            {
                cout << temp->rightchild->data;
            }
            else
            {
                cout << "null";
            }

            cout << ") " << endl;
        }
        break;

    case 4:
        cout << getheight(root) << endl;
        break;

    default:
        cout << "invalid" << endl;
        break;
    }
}

int main()
{
    int n, data, parent, num;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> data >> parent >> num;
        create_node(data, parent, num);
    }

    print_node(root);
    cout << " (preorder) \n";

    while (1)
    {
        int inp;
        cin >> inp;
        if (inp <= 0)
        {
            break;
        }
        func_id(inp);
    }

    return 0;
}