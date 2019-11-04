#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    struct node *prev;
    struct node *next;
};

struct Node
{
    int val;
    struct Node *lc;
    struct Node *rc;
};

struct Node *createTNode(int ele)
{
    Node *neewnode = new Node;
    neewnode->val = ele;
    neewnode->lc = NULL;
    neewnode->lc = NULL;
    return neewnode;
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

void traversal_tree(Node *root)
{
    if(root == NULL)
        return ;

    traversal_tree(root->lc);
    cout<<root->val<<" ";
    traversal_tree(root->rc);
}
node * insert_list(struct node *root, int val)
{
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

struct Node *insert_tree(struct Node *root,int val)
{
    if(root == NULL)
    {
        root = createTNode(val);
        cout<<root->val<<" ";
        return root;
    }
    else
    {
        if(root->val > val)
        {
            root->lc = insert_tree(root->lc,val);
        }
        else if(root->val < val)
        {
            root->rc = insert_tree(root->rc,val);
        }
    }

    return root;
}
struct node *getmiddle(struct node *head)
{
    struct node *fast;
    struct node *slow;
    slow = fast = head;
    while(fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
};
struct node *dlltoBST(node *head)
{
    struct node *temp, *p, *q;
    if(!head || !head->next)
        return head ;

    temp = getmiddle(head);
     p = head;
    while(p->next != temp)
    {
        p = p->next;
    }
    q = temp->next;
    p->next = NULL;
    temp->next = NULL;
    temp->prev = dlltoBST(head);
    temp->next = dlltoBST(q);
    return temp;
};

void tree_traversalDLL(struct node *head)
{
    if(head == NULL)
    {
        return;
    }

    tree_traversalDLL(head->prev);
    cout<<head->val<<" ";
    tree_traversalDLL(head->next);
}
int main()
{
    int n;
    struct node* head = NULL;
    cin>>n;
    int ele;
    for(int i = 0; i < n; i++)
    {
        cin>>ele;
        head = insert_list(head,ele);
    }

    traversal(head);
   // cout<<"\nDLL TO BST :-\n";
    //head = dlltoBST(head);
    //tree_traversalDLL(head);
    cout<<endl;

}
