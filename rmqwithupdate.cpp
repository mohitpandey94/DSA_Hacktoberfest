#include<bits/stdc++.h>
using namespace std;
void lazyprop(int seg[], int lazy[], int pos, int ql, int qh, int sl, int sh, int val)
{
		
	if(lazy[pos] != 0)
	{
		seg[pos]+=lazy[pos];
		if(sl != sh)
		{
			lazy[2*pos+1] += lazy[pos];
			lazy[2*pos+2] += lazy[pos];
		}
		
		lazy[pos] = 0;
	}
	
	if(sl > qh || sh < ql || sl > sh)
		return;
	
	if(sl >= ql && qh >= sh)
	{
		seg[pos] += val;
		
			if(sl != sh)
			{
				lazy[2*pos+1] += val;
				lazy[2*pos+2] += val;
			}
			
		return;
	}
	
	int m = (sl + sh)/2;
	lazyprop(seg,lazy,2*pos+1, ql, qh, sl,m,val);
	lazyprop(seg,lazy,2*pos+2, ql, qh, m+1,sh,val);
	seg[pos] = min(seg[2*pos+1],seg[2*pos+2]);
	
}

int query_lazy(int seg[], int lazy[], int pos, int ql, int qh, int sl, int sh)
{
		
	if(lazy[pos] != 0)
		{
			seg[pos]+=lazy[pos];
			if(sl != sh)
			{
				lazy[2*pos+1] += lazy[pos];
				lazy[2*pos+2] += lazy[pos];
			}
			
			lazy[pos] = 0;
		}
		
	if(ql > sh || qh < sl || sl > sh)
		return INT_MAX;
	
	if(sl >= ql && qh >= sh)
		return seg[pos];
		
	int m = (sl + sh)/2;
	
	return min(query_lazy(seg,lazy,2*pos+1, ql, qh, sl,m),query_lazy(seg,lazy,2*pos+2, ql, qh, m+1,sh));
	
}
void update(int a[],int idx, int val,int seg[], int pos, int l, int h)
{
	if(l == h)
	{
		a[idx] = a[idx] + val;
		seg[pos] = seg[pos] + val;
		return;
	}
	else
	{
		int m = (l + h)/2;
		if(l <= idx && m >= idx )
			update(a,idx,val,seg,2*pos+1,l,m);
		else
			update(a,idx,val,seg,2*pos+2,m+1,h);
			
		seg[pos] = min(seg[2*pos+1],seg[2*pos+2]);
	}
}

void updateRange(int seg[], int pos, int rl, int rh, int sl , int sh, int val)
{
	if(sl > sh || rl > sh || rh < sl)
		return;
	
	if(sl == sh)
	{	
		seg[pos] += val;
		return;
	}
	int m = (sl + sh)/2;
	updateRange(seg,2*pos+1,rl,rh,sl,m,val);
	updateRange(seg,2*pos+2,rl,rh,m+1,sh,val);
	seg[pos] = min(seg[2*pos+1],seg[2*pos+2]);
}
int query(int seg[], int qs, int qe, int ss, int se, int pos)
{
    
    if(ss>=qs && se <= qe)
    {
        return seg[pos];
    }
	if(qs > se || qe < ss)
    {
        return INT_MAX;
    }

    int m = (ss + se)/2;
    int l = query(seg,qs,qe,ss,m,2*pos+1);
    int h = query(seg,qs,qe,m+1,se,2*pos+2);

    return min(l,h);
}
void constructtree(int input[], int seg[], int pos, int l, int h)
{
   if(l > h)
   	return;

    if(l == h)
    {
        seg[pos] = input[l];
        return;
    }

    int m = (l + h)/2;
    constructtree(input, seg,2*pos+1,l,m);
    constructtree(input,seg,2*pos+2,m+1,h);
    seg[pos] = min(seg[2*pos+1],seg[2*pos+2]);
    cout<<"seg["<<pos<<"] = "<<seg[pos]<<endl;
}
int main()
{
    int a[1000];
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>a[i];

    int segsize = 2 * (int)pow(2,(int)ceil(log2(n))) - 1;
    cout<<"segsize = "<<segsize<<endl;
    int seg[segsize];
    int lazy[segsize];
    for(int i = 0; i < segsize; i++)
    {
    	seg[i] = 0;
    	lazy[i] = 0;
	}
    constructtree(a,seg,0,0,n-1);
 	cout<<"Segment tree\n";
	 for(int i = 0; i < segsize; i++)
 	{
 			cout<<seg[i]<<" ";
	}
	cout<<endl;
    int l,h;
  /*  cin>>l>>h;
    int res = query(seg, l,h,0 , n-1, 0);
    cout<<res<<endl;
    update(a,4,-2,seg,0,0,n-1);
     for(int i = 0; i < segsize; i++)
 	{
 			cout<<seg[i]<<" ";
	}
	cout<<endl;
     cin>>l>>h;
    res = query(seg, l,h,0 , n-1, 0);
    cout<<res<<endl;
    updateRange(seg,0, 0,6, 0 , n - 1, 2);
     cin>>l>>h;
    res = query(seg, l,h,0 , n-1, 0);
    cout<<res<<endl;
    */
    cout<<"Lazy array\n";
    for(int i = 0; i < sizeof(lazy)/sizeof(int); i++)
    {
    	cout<<lazy[i]<<" ";
	}
	cout<<endl;
    lazyprop(seg,lazy,0,0,3,0,n-1,2);
    cout<<"Segment tree\n";
    for(int i = 0; i < segsize; i++)
 	{
 			cout<<seg[i]<<" ";
	}
	cout<<endl;
	 cout<<"Lazy array\n";
    for(int i = 0; i < sizeof(lazy)/sizeof(int); i++)
    {
    	cout<<lazy[i]<<" ";
	}
	cout<<endl;
	int res;
    res = query_lazy(seg,lazy,0,0,4,0,n-1);
    cout<<res<<endl;
    return 0;
}

