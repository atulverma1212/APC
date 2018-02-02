#include<stdio.h>
#define R 3
#define C 3

int min(int a,int b,int c)
{
    return (a<b)? (a<c)? a:c : (b<c)? b:c;
}

int minCost(int cost[R][C],int m,int n)
{
    int tc[R][C],i,j;
    tc[0][0] = cost[0][0];

    //Initialize row and col of total cost array
    for(i=1;i<=m;i++)
        tc[i][0] = tc[i-1][0]+cost[i][0];
    for(i=1;i<=n;i++)
        tc[0][i] = tc[0][i-1]+cost[0][i];

    //populate remaining array
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            tc[i][j] = min(tc[i-1][j-1],tc[i-1][j],tc[i][j-1])+cost[i][j];

    return tc[m][n];
}

int main()
{
   int cost[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
    printf(" %d ", minCost(cost, 2, 2));
   return 0;
}