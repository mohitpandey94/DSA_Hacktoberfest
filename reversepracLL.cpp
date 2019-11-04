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
		cout<<head->val<<" ";
		head = head->next;
	}
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
	reverse(&head,3);
	traversal(head);
	cout<<endl;
}
