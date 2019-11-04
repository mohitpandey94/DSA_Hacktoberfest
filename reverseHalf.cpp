#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    struct node *next;
};

struct node *createnode(int ele)
{
    node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->val = ele;
    newnode->next = NULL;
    return newnode;
};
void traverse(node *root)
{
    if(root == NULL)
        return;
    cout<<root->val<<" ";
    traverse(root->next);
}
void pushback(struct node **head, int ele)
{
    if(*head == NULL)
    {
        (*head) = createnode(ele);
        return;
    }
    else
    {
    node *tem = createnode(ele);
    tem->next = (*head);
    (*head) = tem;
    }
}

struct node *reverselist(struct node *root)
{
    struct node *prev = NULL;
    struct node *temp = root;
    struct node *next;
    while(temp != NULL)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;

    }
    //root = prev;
    return prev;
};

struct node *recursivereverse(struct node *cur, struct node *prev)
{
    if(cur == NULL)
        return NULL;

    if(cur->next == NULL)
    {
            cur->next = prev;
          return cur;
    }
    struct node *next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = recursivereverse(next, prev);
    return cur;
};

struct node *findmid(struct node *head , struct node **premid)
{

    struct node *slow = head;
    struct node *fast = head;

    while(slow && fast && fast->next)
    {
        *premid = slow;
        slow = slow->next;
        fast = fast->next;
        if(fast)
            fast = fast->next;

    }
    return slow;
};
int main()
{
    struct node *head = NULL;
    int n;
    cin>>n;
    int ele;
    for(int i = 0; i < n; i++)
    {
        cin>>ele;
        pushback(&head,ele);
    }

    cout<<"LL :-\n";
    traverse(head);
    cout<<endl;
    struct node *premid = NULL;
struct node *mid = findmid(head,&premid);
mid = reverselist(mid);
premid->next = mid;
traverse(head);
/*
    cout<<endl;
    traverse(head);
    cout<<endl;
    cout<<"Reverse"<<endl;
   // head = reverselist(head);
    head = recursivereverse(head,NULL);
    traverse(head);
    */
    return 0;
}
