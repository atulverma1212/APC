#include<iostream>
using namespace std;
int arr[10][10];

void print(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int N,int row,int col)
{
    for(int i=0;i<col;i++)
        if(arr[row][i])
            return false;

    for(int i=row,j=col;i>=0&&j>=0;i--,j--)
        if(arr[i][j])
            return false;

    for(int i=row,j=col;i<N && j>=0;i++,j--)
        if(arr[i][j])
            return false;

    return true;
}


bool arrange(int N,int col)
{
    if(col>=N)
        return true;
    for(int i=0;i<N;i++)
    {
        if(isSafe(N,i,col))
        {
            arr[i][col]=1;
            if(arrange(N,col+1))
                return true;
            else
                arr[i][col]=0;
        }
    }
    return false;
}

int main()
{
    int n = 4;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            arr[i][j] = 0;
    }
    if(arrange(n,0))
        print(n);
}
