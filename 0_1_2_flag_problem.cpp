#include<bits/stdc++.h>
using namespace std;

 void sortColors(vector<int>& a) {

    int l = 0;
    int mid = 0;
    int n = a.size();
    int h = n-1;

    while(mid <= h) {
        if(a[mid] == 0) {
            swap(a[l],a[mid]);
            l++;
            mid++;
        } else if(a[mid] == 2) {
            swap(a[h],a[mid]);
            h--;
        } else {
            mid++;
        }
    }
}

int main() {
    int n;
    cin>>n;
    vector<int>a(n, 0);

    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }

    cout<<"Before Sorting"<<endl;
    for(int i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    sortColors(a);

    cout<<"After Sorting"<<endl;
    for(int i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}
