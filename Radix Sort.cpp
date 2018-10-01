#include<iostream>
using namespace std;

int getMax(int *arr, int n)
{
    int m=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>m)
            m=arr[i];
    }
    return m;
}

void countSort(int *arr, int exp, int n)
{
    int Count[10]={0};
    int output[n];
    for(int i=0;i<n;i++)
        Count[(arr[i]/exp)%10]++;
    for(int i=1;i<10;i++)
        Count[i]+=Count[i-1];
    for(int i=n-1;i>=0;i--)
    {
        output[Count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        Count[ (arr[i]/exp)%10 ]--;
    }
    for(int i=0;i<n;i++)
        arr[i]=output[i];
}

void radixsort(int *arr, int n)
{
    int m = getMax(arr, n);

    for(int exp=1; m/exp>0; exp*=10)
        countSort(arr, exp, n);
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixsort(arr, n);
    print(arr, n);
    return 0;
}


