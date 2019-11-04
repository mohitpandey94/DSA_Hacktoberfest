#include<bits/stdc++.h>
using namespace std;
struct LLnode
{
    int val;
    struct LLnode *next;
};

struct Tnode
{
    int val;
    struct Tnode *lchild;
    struct Tnode *rchild;
};

struct node *createNode(int ele)
{
    node *newnode = new node;
    newnode->val = ele;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
};
void traversal(struct node *root)
{
    while(root)
    {
        cout<<root->val<<" ";
        root = root->next;
    }
}
node * insert_list(struct node *root, int val)
{
    //cout<<"Am i the prob\n";
    if(root == NULL)
    {
       root = createNode(val);
    }
    else
    {
    node *temp = root;
    while(temp->next)
    {
       temp = temp->next ;
    }

    temp->next = createNode(val);
    }
    return root;
}
