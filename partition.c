#include<stdio.h>

void swap(int *p,int *q)
{
    int temp = *p;   *p = *q;  *q = temp;
}

int part(int *arr,int size,int num)
{
    int start=0,end=size-1;
    int i=0;
    while(start<end)
    {
        if(arr[i] < num)
        {
            swap(&arr[i],&arr[start]);
            start++;
        }
        if(arr[i]>num)
        {
            if(arr[end]>num)
            {
                end--;
                i--;
                continue;
            }
            swap(&arr[i],&arr[end]);
            end--;
        }
        i++;
    }
    return start;
}

int main()
{
    int arr[] = {1,5,2,4,3,9,6,7,3,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int n=5;
    printf("part: %d\n",part(arr,size,n));
    int i=0;
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
}

