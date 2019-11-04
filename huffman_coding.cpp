#include<bits/stdc++.h>
using namespace std;
struct node
{
    char a;
    int freq;
    struct node *lc;
    struct node *rc;
};

node *createNewleaf(char a,int b)
{
    node *newnode = new node;
    newnode->a = a;
    newnode->freq = b;
    newnode->lc = NULL;
    newnode->rc = NULL;
}
struct compare
{
bool operator()(node *i, node *j)
{
    return i->freq > j->freq;
}
};
void printcode(struct node *root, int arr[], int pos)
{
    if(root)
    {
        if(root->lc)
        {
            arr[pos] = 0;
            printcode(root->lc,arr,pos+1);
        }
        if(root->rc)
        {
            arr[pos] = 1;
            printcode(root->rc,arr,pos+1);
        }

        if(!root->lc && !root->rc)
        {
            cout<<"Code for "<<root->a<<" : ";
            int i;
            for (i = 0; i < pos; ++i)
                printf("%d", arr[i]);

            cout<<endl;
        }
    }
}
int main()
{

	char a[100];
	int freq[100];
	int n;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin>>freq[i];
	}

	priority_queue<node*,vector<node*>,compare>q,k;
	for(int i = 0; i < n; i++)
    {
        //cout<<"char at "<<i<<" = "<<a[i]<<" and freq = "<<freq[i]<<endl;
        q.push(createNewleaf(a[i],freq[i]));
        k.push(createNewleaf(a[i],freq[i]));
    }
  /*  while(!q.empty())
    {
        node *temp;
        temp = q.top();
        q.pop();
        cout<<"char = "<<temp->a<<" and freq =  "<<temp->freq<<endl;
    }
    */

    while(q.size() > 1)
    {
        node *temp1;
        node *temp2;
        node *internal;
        temp1 = q.top();
        q.pop();
        temp2 = q.top();
        q.pop();
        internal = createNewleaf('$', temp1->freq + temp2->freq);
        internal->lc = temp1;
        internal->rc = temp2;
        q.push(internal);
    }
    node *root ;
    if(q.size() == 1)
    {
        root = q.top();
        q.pop();
    }

    int arr[100];

    printcode(root,arr,0);
/*	cout<<"\nVetor is:\n";
	for(int i = 0; i < n; i++)
	{
		cout<<v[i].first<<" , "<<v[i].second<<endl;
	}
	*/

	return 0;
}
