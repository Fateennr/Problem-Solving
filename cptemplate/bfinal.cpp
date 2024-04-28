#include<iostream>
#include<sstream>

using namespace std;

struct Node
{
    bool endmark;
    Node *next[10];

    int prefcount =0;

    Node()
    {
        endmark = false;
        for(int i=0;i<10;i++)
        {
            next[i] = NULL;
        }
    }
};

Node *root = NULL;

void insert(string str, int len)
{
    int idx;
    Node *curr = root;
    for(int i=0;i<len;i++)
    {
        idx = str[i]- 48; 
        if(curr->next[idx] == NULL)
        {
            curr->next[idx] = new Node();

        }
        curr->prefcount++;
        curr = curr->next[idx];
    }
    curr->endmark = true;
}

// int display(Node *curr,  int level)
// {

//     if(curr->endmark == true)
//     {
//         if(curr->prefcount>1) return curr->prefcount;
//     }

//     for(int i=0;i<10;i++)
//     {
//         if(curr->next[i] != NULL)
//         {
//             display(curr->next[i], level+1);
//         }
//     }
// }

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        root =new Node();
        int a;
        cin>>a;

        while(a--)
        {
            string str;
            cin>>str;

            insert(str, str.size());
        }

        cout<<display(root, 0)<<"\n";
    }

    return 0;
}