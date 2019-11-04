
#include<bits/stdc++.h>
using namespace std;
struct node
{
    struct node *lc;
    struct node *rc;
    int val;
};

node *createNew(int val)
{
    node *newnode = new node;
    newnode->val = val;
    newnode->lc = NULL;
    newnode->rc = NULL;
    return newnode;
}

struct node *insert_tree(struct node *root, int ele)
{
    if(root == NULL)
    {
        root = createNew(ele);
        return root;
    }

    node *temp;
    temp = root;

    while(true)
    {
        if(ele < temp->val)
        {
            if(!temp->lc)
            {
                temp->lc = createNew(ele);
                break;
            }
            else
                temp = temp->lc;
        }
        else
        {
            if(!temp->rc)
            {
                temp->rc = createNew(ele);
                break;
            }
            else
                temp = temp->rc;
        }
    }

    return root;

};

void inorder_trav(node *a)
{
    if(a == NULL)
    {
        return;
    }
    inorder_trav(a->lc);
    cout<<a->val<<" ";
    inorder_trav(a->rc);
}
int height(node *a)
{
    if(a == NULL)
        return 0;
    else
        return 1 + max(height(a->lc),height(a->rc));
}
int diameter(node *a)
{
    if(a == NULL)
    {
        return 0;
    }

    else return (max(max(diameter(a->lc),diameter(a->rc)),1+height(a->lc)+height(a->rc)));
}
struct node* first = NULL;
struct node *last = NULL;

void fnc(struct node**root, struct node *cur, struct node *prev)
{

    if(cur == MULL)
        return;
    fnc(root,cur->left,prev);

    if(!first)
    {
        first = NULL;
        prev = cur;
    }
}
void convertToCLL(struct node**root)
{

    fnc(root,*root,NULL);
}
int main()
{
    int n;
    cin>>n;
    node *root = NULL;
    for(int i = 0; i < n; i++)
    {
        int ele;
        cin>>ele;
        root = insert_tree(root,ele);
    }

    inorder_trav(root);
   // cout<<"Diameter = "<<diameter(root)<<endl;
   convertToCLL(&root);
    return 0;
}
