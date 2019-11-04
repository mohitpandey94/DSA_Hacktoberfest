#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
int val;
struct node *next;
};
void traversal(struct node *head)
{
	while(head)
	{
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
}
void midsplit(node *head, node **left, node **right)
{
    if(head == NULL || head->next == NULL)
    {
        *left = head;
        *right = NULL;
        return;
    }
    struct node *slow,*fast;
    slow =head;
    fast = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next;
        if(fast->next)
        {
            fast = fast->next;
        }
    }

    struct node *temp;
    temp = head;
    while(temp->next != slow)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    *left = head;
    *right = slow;
}
struct node *mergefnc(struct node *left, struct node *right)
{
    if(!left)
    return right;
    else if(!right)
    return left;

    struct node *result;
    if(left->val <= right->val)
    {
        result = left;
        result->next = mergefnc(left->next,right);
    }
    else
    {
        result = right;
        result->next = mergefnc(left,right->next);
    }

    return result;
};
void mergesort(struct node **head)
{
    if(!(*head)||!(*head)->next)
        return ;
    struct node *left,*right;
    left = NULL;
    right = NULL;
    midsplit(*head,&left,&right);
    mergesort(&left);
    mergesort(&right);
    *head = mergefnc(left,right);
};
int main() {
	struct node *p1,*p2,*p3,*p4,*p5,*p6;
	p1 = (node*)malloc(sizeof(node));
	p2 = (node*)malloc(sizeof(node));
	p3 = (node*)malloc(sizeof(node));
	p4 = (node*)malloc(sizeof(node));
	p5 = (node*)malloc(sizeof(node));
	p6 = (node*)malloc(sizeof(node));
	p1->val = 5;
	p1->next = p2;
	p2->val = 1;
	p2->next = p3;
	p3->val = 3;
	p3->next = p4;
	p4->val = 6;
	p4->next = p5;
	p5->val = 2;
	p5->next = p6;
	p6->val = 4;
	p6->next = NULL;
	cout<<"Traversal before sorting\n";
	traversal(p1);
	mergesort(&p1);
	cout<<"Traversal after sorting\n";
    traversal(p1);
	return 0;
}
