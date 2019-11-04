#include<bits/stdc++.h>
struct node
{
int val;
struct node *lc;
struct node *rc;
};

using namespace std;

struct node* newNode(int val)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->val = val;
  node->lc = NULL;
  node->rc = NULL;

  return(node);
}
void inorder(node *root)
{ if(root == NULL)
{
return;
}
inorder(root->lc);
cout<<root->val<<" ";
inorder(root->rc);
}

struct node *insert_levelorder(struct node *root, int ele)
{
 queue<node *>q;
 node *newNode = new node;
 newNode->lc = NULL;
 newNode->rc = NULL;
 newNode->val = ele;
 if(root == NULL)
 {
     root = newNode;
     return root;
 }
 q.push(root);
 node *temp;
 while(!q.empty())
 {
     temp = q.front();
     q.pop();

         if(temp->lc)
         {
             q.push(temp->lc);
         }
         else
         {
             temp->lc = newNode;
             return root;
         }
         if(temp->rc)
         {
             q.push(temp->rc);
         }
         else
         {
             temp->rc = newNode;
             return root;
         }

     }

     return root;

 }

  void preorder(struct node *root)
 {
 	if(root == NULL)
 		return;

 	cout<<root->val<<" ";
 	preorder(root->lc);
 	preorder(root->rc);
 }

/* bool hasPathSum(node *root, vector<int>&path, int k, int val)

 {
 	if(root == NULL && val == 0)
 	{
 		return true;
	 }

	 val = val-root->val;
	 cout<<"updated val = "<<val<<endl;
	 path.push_back(root->val);
	 cout<<"path["<<k<<"] = "<<root->val<<endl;

	 if(hasPathSum(root->lc,path,k+1,val) || hasPathSum(root->lc,path,k+1,val) )
	 	return true;
	else
		return false;
 }
 */
 int hasPathSum(node* A, int B) {
    if((B == 0) && (A == NULL))
    return 1;

    if((B == 0) && (A != NULL))
    return 0;

    if((B!=0) && (A == NULL))
    return 0;

    if(hasPathSum(A->lc,B-A->val)||hasPathSum(A->rc,B-A->val))
    return 1;

    return 0;


}
 int main()
{
	 int n;
     cin>>n;
     int ele;
     node *first = NULL;
     node *second = NULL;
     node *third = NULL;
     node *forth = NULL;
     node *fifth = NULL;
     node *sixth = NULL;
     first = new node;
     second = new node;
     third = new node;
     forth = new node;
     fifth = new node;
     sixth = new node;
     first->val = 1;
     second->val = 2;
     third->val = 3;
     forth->val = 4;
     fifth->val = 5;
     sixth->val = 6;
     first->lc = second;
     first->rc = third;
     second->lc = forth;
     second->rc = fifth;
     third->lc = sixth;
     third->rc = NULL;
     forth->lc = NULL;
     forth->rc = NULL;
     fifth->lc = NULL;
     fifth->rc = NULL;
     sixth->lc = NULL;
     sixth->rc = NULL;
    /* for(int i = 0; i < n; i++)
     {
         cin>>ele;
         root = insert_levelorder(root,ele);
     }
   /*  cout<<"Normal tree\n";
     preorder(root);
     cout<<endl;
	vector<int>path;
	 //int k = 0;
	 if(hasPathSum(root,path,0,4)){
	 	for(int i = 0; i < path.size(); i++)
	 	{
	 		cout<<path[i]<<endl;
		 }
	 }
	 else
	 cout<<"No Path"<<endl;
	 */


	 int k;
	  cin>>k;
	  cout<<hasPathSum(first,k)<<endl;

     return 0;
 }
