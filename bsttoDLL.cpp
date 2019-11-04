#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    struct node *lc;
    struct node *rc;
};
struct node *createNew(int ele)
{
    node *newnode = new node;
    newnode->val = ele;
    newnode->lc = newnode->rc = NULL;
    return newnode;
};

void inorder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->lc);
    cout<<root->val<<" ";
    inorder(root->rc);
}
struct node *insertBST(node *root, int ele)
{
    if(root == NULL)
        return createNew(ele);

    else
    {
        node *temp = root;
        while(true)
        {
            //if(temp->lc == NULL && temp->rc == NULL)
              //  break;
            if(ele < temp->val)
            {
                if(temp->lc)
                {
                    temp = temp->lc;
                }
                else
                {
                    temp->lc = createNew(ele);
                    break;
                }
            }
            else
            {
                if(temp->rc)
                {
                    temp = temp->rc;
                }
                else
                {
                    temp->rc = createNew(ele);
                    break;
                }
            }
        }
        /*if(temp->val > ele)
        {
            temp->lc = createNew(ele);
        }
        else
        {
            temp->rc = createNew(ele);
        }
        */
    }

    return root;
};
struct node* BSTtoDLL(node *root)
{
    node *left;
    node *right;
    if(root == NULL)
    {
        return root;
    }

    if(root->lc)
    {
    node *left;
    left = BSTtoDLL(root->lc);
    for(;left->rc != NULL; left = left->rc);
    left->rc = root;
    root->lc = left;
    }

    if(root->rc)
    {
    node *right;
    right = BSTtoDLL(root->rc);
    for(;right->lc != NULL; right = right->lc);
    right->lc = root;
    root->rc = right;
    }
    return root;

};
void roottoheadDLL(struct node **dummy)
{
    while((*dummy)->lc )
    {
        (*dummy) = (*dummy)->lc;
    }
}

void list_traversal(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->val<<" ";
    list_traversal(root->rc);
}
int main()
{
        int n;
        cin>>n;
        node *root = NULL;
        int ele;
        for(int i = 0; i < n; i++)
        {
            cin>>ele;
            root = insertBST(root,ele);
        }

        cout<<"Inorder Traversal of tree\n";
        inorder(root);
        cout<<endl;
        struct node *dummy;
        dummy = BSTtoDLL(root);
        roottoheadDLL(&dummy);
        list_traversal(dummy);
        return 0;
}
