#include<iostream>
using namespace std;

void merge_arr(int *arr, int l, int mid, int r)
{
    int left = mid-l+1;
    int right = r-mid;
    int L[left];
    int R[right];
    for(int i=0;i<left;i++)
        L[i]=arr[l+i];
    for(int i=0;i<right;i++)
        R[i]=arr[mid+i+1];

    int j=0,k=0,m=l;
    while(j<left && k<right)
    {
        if(L[j]<=R[k])
        {
            arr[m]=L[j];
            j++;
        }
        else
        {
            arr[m]=R[k];
            k++;
        }
        m++;
    }
    while(j<left)
    {
        arr[m]=L[j];
        j++;
        m++;
    }
    while(k<right)
    {
        arr[m]=R[k];
        m++;
        k++;
    }
}

void msort(int *arr,int l,int r)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        msort(arr, l, mid);
        msort(arr, mid+1, r);
        merge_arr(arr, l, mid, r);
    }
}

int main()
{
    int arr[] = {1,5,2,3,10,-1};
    int n = sizeof(arr)/sizeof(arr[0]);
    msort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;
}
