#include<iostream>
#include<stack>

using namespace std;

void printNGE(int *arr, int n)
{
    stack<int> str;
    str.push(arr[0]);

    for(int i=1;i<n;i++)
    {
        if(str.empty())
        {
            str.push(arr[i]);
            continue;
        }
        while(!str.empty() && str.top()<arr[i])
        {
            cout << str.top() << "-->" << arr[i] << endl;
            str.pop();
        }
        str.push(arr[i]);
    }
    while(!str.empty())
    {
        cout << str.top() << "-->" << -1 << endl;
        str.pop();
    }
}

/* Driver program to test above functions */
int main() {
  int arr[] = {11, 13, 21, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  printNGE(arr, n);
  return 0;
}
