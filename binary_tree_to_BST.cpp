#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};



void printInorder (struct Node* node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder (node->left);

    /* then print the data of node */
    printf("%d ", node->data);

    /* now recur on right child */
    printInorder (node->right);
}



Node *  binaryTreeToBST (Node *root);
 /*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/*Your code here*/
void formarray(Node *root, int *pos, int a[])
{
    if(root == NULL)
    return;

    formarray(root->left,pos,a);
     a[(*pos)++] = root->data;
    formarray(root->right,pos,a);

}
struct Node *hd = NULL;
void formBST(Node **root, int pos, int a[])
{
    if(*root == NULL)
    {
        cout<<"NULL"<<endl;
     return;
    }

    *root = (*root)->left;
    formBST(root,pos,a);
    (*root)->data = a[pos++];
    *root = (*root)->right;
    formBST(root,pos,a);

}
Node *binaryTreeToBST (Node *root)
{
//Your code here
int a[20];
int pos = 0;
formarray(root,&pos,a);

//cout<<"Inorder :\n";
//printInorder(root);
sort(a,a+pos);
cout<<"array:\n";
for(int i = 0; i < pos; i++)
{
    cout<<a[i]<<" ";
}
cout<<endl;
Node *temp = root;
formBST(&temp,0,a);
return root;
}


/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }

     Node *res = binaryTreeToBST (root);
     printInorder(res);
     cout<<endl;
    // cout << endl;
  }
  return 0;
}

