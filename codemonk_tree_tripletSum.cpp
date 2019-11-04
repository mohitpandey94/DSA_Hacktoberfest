#include <iostream>
#include<bits/stdc++.h>

using namespace std;
struct node
{
    long long int val;
    struct node *lc;
    struct node *rc;
};

struct node *newNode(long long ele)
{
    struct node *temp = (node*)malloc(sizeof(node));
    temp->val = ele;
    temp->lc = NULL;
    temp->rc = NULL;
    return temp;
}
map<int,node*>mp;
struct node *createTree(long long a[],long long parent[], int n)
{
    struct node *root = NULL;
    root = mp[a[0]];
    if(!root)
    {

        cout<<"NULL" <<endl;
    }
    struct node *temp = NULL;
    temp = root;
    for(int i = 0; i < n-1; i++)
    {

       temp = mp[parent[i]];
       if(!temp->lc)
       {
           temp->lc = mp[a[i+1]];
       }
       else
       temp->rc = mp[a[i+1]];
    }
    if(!root)
    {

        cout<<"NULL" <<endl;
    }
    return root;
}
int ctr = 0;
void findTriplets(struct node *root, long long k,vector<int>temp)
{
    if(temp.size() == 3)
    {
        if((temp[0] + temp[1] + temp[2]) == k)
        {
          ctr++;
          return ;
        }
        else
            return;

    }
    if(!root)
        return;
    temp.push_back(root->val);
    findTriplets(root->lc,k,temp);
    findTriplets(root->rc,k,temp);
    temp.pop_back();
}
void fnc(struct node *root,int k)
{
    if(!root)
        return;

        vector<int>vec;
        vec.push_back(root->val);
        findTriplets(root,k,vec);
        fnc(root->lc,k);
        fnc(root->rc,k);
        vec.pop_back();

}
void traversal(struct node *root)
{
    if(root == NULL)
    return;

    traversal(root->lc);
    cout<<root->val<<" ";
    traversal(root->rc);
}
int main()
{
    int n;
    long long k;
    cin>>n;
    cin>>k;
    long long a[n];
    for(int i = 0; i < n; i++)
    {
        struct node *temp;
        cin>>a[i];
        temp = newNode(a[i]);
        mp[a[i]] = temp;
    }

    long long parent[n-1];
    for(int i = 0; i < n - 1; i++)
    cin>>parent[i];

    struct node *head = NULL;
    head = createTree(a,parent,n);
    if(!head)
        cout<<"root m NULL"<<endl;
  //  cout<<"root val = "<<head->val<<endl;
   // fnc(head,k);
  //  traversal(head);
    cout<<ctr<<endl;
    return 0;
}

