#include<bits/stdc++.h>
using namespace std;

void mergeArray(int a[], int l, int mid, int h) {
    int temp[h-l+1];
    memset(temp, 0, sizeof(temp));
    int i = l;
    int j = mid+1;
    int ctr = 0;

    while(i <= mid && j <= h) {
        if(a[i] < a[j]) {
            temp[ctr++] = a[i];
            i++;
        } else {
            temp[ctr++] = a[j];
            j++;
        }
    }

    while(i <= mid) {
        temp[ctr++] = a[i++];
    }

    while(j <= h) {
        temp[ctr++] = a[j++];
    }

    ctr = 0;
    for(int k = l; k <= h; k++) {
        a[k] = temp[ctr++];
    }
}
void mergeSortUtil(int a[], int l, int h) {
    if(l < h) {
        int mid = (l+h)/2;
        mergeSortUtil(a, l, mid);
        mergeSortUtil(a, mid+1, h);
        mergeArray(a, l, mid, h);
    }
}
void mergeSort(int a[], int n) {
    mergeSortUtil(a, 0, n-1);
}
int main() {
    int n;
    cin>>n;

    int a[n];

    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }

    cout<<"Array before Merge Sort"<<endl;

    for(int i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    mergeSort(a,n);

    cout<<"Array after Merge Sort"<<endl;

    for(int i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}
