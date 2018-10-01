#include<iostream>
using namespace std;

int part(int *arr, int l, int r)
{
    int pivot = arr[r];
    int i=l-1;
    for(int j=l;j<r;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}

void qsort(int *arr, int l, int r)
{
    if(l<r)
    {
        int mid = part(arr, l, r);
        qsort(arr, l, mid-1);
        qsort(arr, mid+1, r);
    }
}

int main()
{
    int arr[] = {1,5,2,3,10,-1};
    int n = sizeof(arr)/sizeof(arr[0]);
    qsort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;
}
