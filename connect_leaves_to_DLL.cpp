// C program to extract leaves of a Binary Tree in a Doubly Linked List
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

// Structure for tree and linked list
struct Node
{
    int data;
    struct Node *left, *right;
};

// Main function which extracts all leaves from given Binary Tree.
// The function returns new root of Binary Tree (Note that root may change
// if Binary Tree has only one node).  The function also sets *head_ref as
// head of doubly linked list.  left pointer of tree is used as prev in DLL
// and right pointer is used as next
void fnc1(Node** root,Node* cur, Node** pre, bool* flag)
{
    if(!cur)
        return;
    if(!(*flag) && !cur->left && !cur->right)
    {
        *flag = true;
        cur->left = *pre;
        *root = cur;
        *pre = cur;
        return;
    }
    else if(!cur->left && !cur->right)
    {
        cur->left = *pre;
        (*pre)->right = cur;
        *pre = cur;
        return;
    }
    fnc1(root,cur->left,pre,flag);
    fnc1(root,cur->right,pre,flag);
};
struct Node* fnc(struct Node *root)
{
    bool flag = false;
    struct Node* pre = NULL;
    fnc1(&root,root,&pre,&flag);
    pre->right = NULL;
    return root;
}

// Utility function for allocating node for Binary Tree.
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Utility function for printing tree in In-Order.
void print(struct Node *root)
{
    if (root != NULL)
    {
         print(root->left);
         printf("%d ",root->data);
         print(root->right);
    }
}

// Utility function for printing double linked list.
void printList(struct Node *head)
{
     while (head)
     {
         printf("%d ", head->data);
         head = head->right;
     }
}

// Driver program to test above function
int main()
{
     struct Node *head = NULL;
     struct Node *root = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5);
     root->right->right = newNode(6);
     root->left->left->left = newNode(7);
     root->left->left->right = newNode(8);
     root->right->right->left = newNode(9);
     root->right->right->right = newNode(10);

     printf("Inorder Trvaersal of given Tree is:\n");
     print(root);
        struct Node *temp = root;
     head = fnc(temp);

    printf("\nExtracted Double Linked list is:\n");
     printList(head);
     cout<<endl;
    // cout<<"Root val = "<<root->data<<endl;

    printf("\nInorder traversal of modified tree is:\n");
     print(root);
     return 0;
}
