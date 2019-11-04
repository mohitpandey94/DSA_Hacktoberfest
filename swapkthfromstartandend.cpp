#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    struct node *prev;
    struct node *next;
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
void insert_before(struct node *&root, int ele)
{
    if(root == NULL)
    {
        root = createNode(ele);
        return;
    }
    else
    {
        struct node *temp;
        temp = createNode(ele);
        temp->next = root;
        root = temp;
    }
}

int main()
{
    node *head= NULL;
    int n;
    cin>>n;
    int ele;
    for(int i = 0; i < n; i++)
    {
        cin>>ele;
        head = insert_list(head,ele);
    }
    return 0;
}
