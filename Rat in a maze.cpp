#include<iostream>
using namespace std;

bool isPossible(int arr[4][4],int m,int n,int x,int y)
{
    return (x<m && y<n && arr[x][y]==1);
}

int traverse(int arr[4][4],int m,int n,int x,int y,int sol[4][4])
{
    int movex[2] = {0,1};
    int movey[2] = {1,0};
    if(x==m-1 && y==n-1)
    {
        sol[0][0]=1;
        sol[x][y]=1;
        return true;
    }
    for(int i=0;i<2;i++)
    {
        int nextx = x+movex[i];
        int nexty = y+movey[i];
        if(isPossible(arr,m,n,nextx,nexty)==true)
        {
            sol[nextx][nexty]=1;
            if(traverse(arr,m,n,x+movex[i],y+movey[i],sol)==true)
                return true;
            else
                sol[nextx][nexty]=0;
        }
    }
    return false;
}

int main()
{
    int m=4,n=4;
    int arr[4][4] = { {1, 0, 0, 0},
                {1, 1, 0, 1},
                {1, 0, 0, 0},
                {1, 1, 1, 1} };
    int sol[4][4] = {0};
    if(traverse(arr,m,n,0,0,sol))
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
                cout << sol[i][j] << " ";
            cout << endl;
        }
    }
    else
    {
        cout << "Not Possible";
    }

}
