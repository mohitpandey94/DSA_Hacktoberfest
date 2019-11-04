#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    struct node *lc;
    struct node *rc;
};

node* createNode(int val)
{
    node *newNode =(node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->lc = NULL;
    newNode->rc = NULL;

    return newNode;
}

void insert_tree(node **root,int val)
{
    if(!*root)
    {
        *root = createNode(val);
        return;
    }

    node *temp = *root;
    if(val > temp->val)
    {
        insert_tree(&(temp->rc),val);
    }
    else
        insert_tree(&(temp->lc),val);
}

void traverse_tree(node *root)
{
    if(root == NULL)
        return;
    traverse_tree(root->lc);
    cout<<root->val<<" ";
    traverse_tree(root->rc);
}

int largest_bst(struct node *root)
{
    if(!root)
        return 0;
    int ls = largest_bst(root->lc);
    int rs = largest_bst(root->rc);

    if(!ls && !rs)
        return 1;
    else
    {
        if(root->val > root->lc->val && root->val < root->rc->val)
        {
            return 1+ls+rs;
        }
        else
            return max(ls,rs);
    }
}
int main()
{
    int n;
    cin>>n;
    node *root = NULL;

    for(int i = 0; i < n; i++)
    {
        int val;
        cin>>val;
        insert_tree(&root,val);
    }

    traverse_tree(root);
    cout<<endl;

}
