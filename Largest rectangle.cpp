#include<iostream>
#include<stack>
using namespace std;

int histogram(int *arr, int n)
{
    stack<int> str;
    int area = 0;
    int temp,i,pos;
    for(i=0;i<n;i++)
    {
        if(str.empty() || arr[i]>=arr[str.top()])
        {
            str.push(i);
            continue;
        }
        while(!str.empty() && arr[i]>arr[str.top()])
        {
            pos = str.top();
            str.pop();
            if(str.empty())
                temp = arr[pos]*i;
            else
                temp = arr[pos]*(i-str.top()-1);
            if(temp>area)
                area=temp;
        }
    }
    while(!str.empty())
    {
        pos = str.top();
        str.pop();
        if(str.empty())
            temp = arr[pos]*i;
        else
            temp = arr[pos]*(i-str.top()-1);
        if(temp>area)
            area=temp;
    }
    return area;
}

int main()
{
    int arr[] = {1,1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << histogram(arr,n);
}
