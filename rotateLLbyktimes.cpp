#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;


struct node
{
    int data;
    struct node* next;
}*head;

void rotate(struct node **head_ref, int k);
int len(node *head)
{
  int l = 0;


  while(head)
  {
      head = head->next;
      l++;
  }
  return l;
}
void rotate(struct node **head_ref, int k)
{
  // Complete this method
  node *temp = *head_ref;
  int l = len(temp);
  if(l == 0 || l == 1)
  return;

  cout<<"length = "<<l<<endl;
  k = k%l;
  if(k == 0)
    return;
  node *next_ptr = NULL;
  int ctr = 0;
  node *cur = temp;

  while(ctr < k-1 && cur)
  {
      cur = cur->next;
      ctr++;
  }

  next_ptr = cur->next;
  cur->next = NULL;
  cur = temp;
  temp = next_ptr;
  *head_ref = next_ptr;
  while(next_ptr->next)
  {
      next_ptr = next_ptr->next;
  }
  next_ptr->next = cur;
}

  void insert()
{
    int n,i,value;
    struct node *temp;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&value);
        if(i==0)
        {
            head=(struct node *) malloc( sizeof(struct node) );
            head->data=value;
            head->next=NULL;
            temp=head;
            continue;
        }
        else
        {
            temp->next= (struct node *) malloc( sizeof(struct node) );
            temp=temp->next;
            temp->data=value;
            temp->next=NULL;
        }
    }
}

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */

    int t,k,n,value;
     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     scanf("%d",&t);
     while(t--)
     {
     insert();
     scanf("%d",&k);
     rotate(&head,k);
     printList(head);

     }
     return(0);
}
