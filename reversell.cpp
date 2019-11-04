#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    struct Node *next;
};

struct Node *createNode(int ele)
{
    Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->val = ele;
    newnode->next = NULL;
    return newnode;
};
void traverse(Node *root)
{
    if(root == NULL)
        return;
    cout<<root->val<<" ";
    traverse(root->next);
}
void pushback(struct Node **head, int ele)
{
    if(*head == NULL)
    {
        (*head) = createNode(ele);
        return;
    }
    else
    {
    Node *tem = createNode(ele);
    tem->next = (*head);
    (*head) = tem;
    }
}

struct Node *reverselist(struct Node *root)
{
    struct Node *prev = NULL;
    struct Node *temp = root;
    struct Node *next;
    while(temp != NULL)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;

    }
    root = prev;
    return root;
};

struct Node *recursivereverse(struct Node *cur, struct Node *prev)
{
    if(cur == NULL)
        return NULL;

    if(cur->next == NULL)
    {
            cur->next = prev;
          return cur;
    }
    struct Node *next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = recursivereverse(next, prev);
    return cur;
};
int main()
{
    struct Node *head = NULL;
    int n;
    cin>>n;
    int ele;
    for(int i = 0; i < n; i++)
    {
        cin>>ele;
        pushback(&head,ele);
    }

    cout<<endl;
    traverse(head);
    cout<<endl;
    cout<<"Reverse"<<endl;
   // head = reverselist(head);
    head = recursivereverse(head,NULL);
    traverse(head);
    return 0;
}
