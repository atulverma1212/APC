#include<iostream>
using namespace std;

void max_heapify(int *arr, int i, int n)
{
    int l = 2*i;
    int r = 2*i+1;
    int largest=i;
    if(l<=n && arr[l]>arr[i])
        largest=l;
    if(r<=n && arr[r]>arr[largest])
        largest=r;
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        max_heapify(arr, largest, n);
    }
}

void heap_sort(int *arr, int n)
{
    for(int i=n/2;i>=0;i--)
        max_heapify(arr, i, n);
    for (int i=n; i>0; i--)
    {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i-1);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    heap_sort(arr,n-1);
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;
}

