
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	struct node *next;
};
struct node *createNew(int val)
{
	struct node *newNode;
	newNode = (struct node *)malloc(sizeof(node));
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
};

void traversal(node *head)
{
	while(head)
	{
		//cout << "print\n";
		cout<<head->val<<" ";
		head = head->next;
	}
}
//bool flag = true;
void reverseLL(struct node **head, int k,struct node **one,struct node **dummy)
{
	if(!(*head) || !(*head)->next)
		return;
	struct node *cur = (*head)->next;

	//cout<<"cur val = "<<cur->val<<endl;
	struct node *next,*prev;
	prev = *head;
	/*struct node *temp = *head;

	while((i < k) && (temp))
	{
		temp = temp->next;
		//cout<<"temp val = "<<temp->val<<endl;
		i++;
	}
	struct node *lnext = temp;
	*/
	//cout<<"lnext = "<<lnext->val<<endl;
	//next = cur->next;
	int i = 0;
	while((i < k-1) && cur )
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
		i++;
	}
	if(!(*one))
	{
		*one = prev;
	}
	//cout<<"cur = "<<cur->val<<endl;
	//cout<<"next = "<<next->val<<endl;
	(*head)->next = cur;
	if (*dummy != NULL)
		(*dummy)->next = cur;
	*dummy = *head;
	(*head) = cur;
	//cout<<"lnext = "<<lnext->val<<endl;

}
void reverseK(struct node **head, int k)
{
	struct node *temp = *head;
	struct node *one = NULL;
	struct node *dummy = NULL;
	while(temp)
	{
		//cout<<"ch"<<endl;
		reverseLL(&temp,k,&one,&dummy);
		//if(temp)
		//cout<<"temp val = "<<temp->val<<endl;
		//temp = NULL;
		//break;
		//cout<<"ch"<<endl;
		//traversal(*head);
		//cout<<endl;
	/*	if(temp)
		{
			for(int i = 0; i < k; i++)
			{
				if(!temp)
					break;
				temp = temp->next;
			}
		}
		*/
	}
	*head = one;
}
void insertLL(struct node** head, int ele)
{
	if(*head == NULL)
	{
		*head = createNew(ele);
		return;
	}
	struct node *temp;
	temp = *head;
	while(temp->next)
	{
		temp = temp->next;
	}
	temp->next = createNew(ele);
}


int main()
{

	int n;
	cin>>n;
	struct node *head = NULL;
	for(int i = 0; i < n; i++)
	{
		int ele;
		cin>>ele;
		insertLL(&head,ele);
	}
	traversal(head);
	cout<<endl;
	reverseK(&head,3);
	traversal(head);
	cout<<endl;
}
