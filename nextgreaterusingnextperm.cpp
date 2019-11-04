#include<bits/stdc++.h>

using namespace std;
long long int power(int a, int n)
{
    if(n == 0)
        return 1;
    int f = a;
    cout<<" n = "<<n<<endl;
    for(int i = 0; i < n-1; i++)
        f = f * a;
    return f;
}
int main()
{
     int t;
    cin>>t;
 //   cout<<power(t,2)<<endl;
    while(t--)
    {
    long long int n;
    cin>>n;
    long long int b = n;
    vector<int>a;
	while(n>0)
	{
		a.insert(a.begin(),n%10);
		n = n/10;
	}
	for(int i = 0; i < a.size(); i++){
        cout << a[i];
	}
    cout << endl;
    long long int num = 0;
    for(int i = 0; i < a.size() ; i++)
	{
	    cout<<"num =  "<<num<<endl;
	    num = num + a[i] *power(10,a.size() - i -1);
	}
	cout<<"num = "<<num<<endl;

	sort(a.begin(),a.end());
    for(int i = 0; i < a.size(); i++){
     //   cout << a[i];
	}
	cout << "-----------------------" << endl;
	do
	{
	    num = 0;
	   /* for(int i = 0; i < a.size(); i++)
			cout<<a[i]<<" ";
		cout<<endl;
		*/

	for(int i = 0; i < a.size() ; i++)
	{
	    cout<<"num =  "<<num<<endl;
	    num = num + a[i] *power(10,a.size() - i -1);
	}
	cout<<"num = "<<num<<endl;
	if(num > b)
	{
	    cout<<"con"<<endl;
	    break;
	}

	}while(next_permutation(a.begin(),a.end()));


	cout<<num<<endl;
    }

return 0;
}
