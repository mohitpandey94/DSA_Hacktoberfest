#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i = 0; i < n; i++)
	    cin>>a[i];

	    int k = 0;
	    while(k < n)
	    {
	        if(a[k] != 0)
	        {
	            int j = k+1;
	         /*   while(a[j] <= 0)
	            {
	                j++;
	            }
	            */
	            if(a[j] == a[k])
	            {
	                a[k] = 2*a[j];
	                a[j] = 0;
	            }

	            k = j;

                continue;
	        }
	        k++;
	    }

	   int count = 0;  // Count of non-zero elements

    // Traverse the array. If element encountered is non-
    // zero, then replace the element at index 'count'
    // with this element
    for (int i = 0; i < n; i++)
        if (a[i] != 0)
            a[count++] = a[i]; // here count is
                                   // incremented

    // Now all non-zero elements have been shifted to
    // front and  'count' is set as index of first 0.
    // Make all elements 0 from count to end.
    while (count < n)
        a[count++] = 0;

        for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";

        cout<<endl;

	}
	return 0;
}
