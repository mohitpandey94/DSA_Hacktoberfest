#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    struct node *prev;
    struct node *next;
};
int n,m;
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
int carry = 0;
struct node * sumoftwolist(node *list1, node *list2)
{
    if(!list1 || !list2)
        return NULL;

   // static int carry = 0;
    struct node *res;
    res = new node;

    res->next = sumoftwolist(list1->next,list2->next);
    int sum = list1->val + list2->val + carry ;
    res->val = (sum)%10;
    carry = sum/10;

    return res;
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

void carryover(node *&res, node *list1, node *cur)
{
   // cout<<"Carry function"<<endl;
    if(list1 == cur)
        return;

    carryover(res,list1->next,cur);
    int sum = carry + list1->val;
    carry = (sum)/10;
    insert_before(res,sum%10);
}
struct node * sumoftwolistmain(struct node *list1, struct node *list2)
{
    node *cur;
    if(!list1 && !list2)
        return NULL;

    if(!list1)
        return list2;

    else if(!list2)
        return list1;

    struct node *res = NULL;
    if(m == n)
    {
        res = sumoftwolist(list1, list2);
        cout<<"Equal m n"<<endl;
        return res;
    }
    else
    {
        int diff;

        if(n > m)
        {
            cur = list1;
             diff = n - m;
             while(diff--)
             {
                 cur = cur->next;
             }
            res = sumoftwolist(cur,list2);
            carryover(res,list1,cur);
      //      cout<<"m > n"<<endl;

        }
        else
        {
            cur = list2;
            diff = m - n;
            while(diff--)
            {
                cur = cur->next;
            }
            res = sumoftwolist(cur,list1);
            carryover(res,list2,cur);
            //cout<<"m < n"<<endl;
        }
    }

    if(carry)
    {
    //    cout<<"Carry\n";
        insert_before(res,carry);
    }
    return res;
}
int main()
{
    struct node *list1,*list2;
    list1 = list2 = NULL;
    cin>>n;
    cin>>m;
    int ele;
    int i;
    for(i = 0; i < n; i++)
    {
        cin>>ele;
        list1 = insert_list(list1,ele);
    }
    for(i = 0; i < m; i++)
    {
        cin>>ele;
        list2 = insert_list(list2,ele);
    }

   struct node *res = NULL;
    res = sumoftwolistmain(list1,list2);
    if(res == NULL)
    {
        cout<<"NULL"<<endl;
    }
    traversal(res);
    cout<<endl;
   // traversal(list2);
    //cout<<endl;
    return 0;
}
