#include<stdio.h>

void spiral(int m,int n,int arr[][n])
{
    int rl=0 , rh = n, cl = 1, ch = m, i=0,j=0;
    while(rl<rh && cl<=ch)
    {
        for(i=rl;i<rh;i++)
        {
            printf("%d ",arr[j][i]);
        }
        rh--;
        i--;
        for(j=cl;j<ch;j++)
        {
            printf("%d ",arr[j][i]);
        }
        ch--;
        j--;
        if(cl>ch)
            break;
        for(i=rh-1;i>=rl;i--)
        {
            printf("%d ",arr[j][i]);
        }
        rl++;
        i++;
        if(rl>=rh)
            break;
        for(j=ch-1;j>=cl;j--)
        {
            printf("%d ",arr[j][i]);
        }
        cl++;
        j++;
    }
}

int main()
{
    int m=4,n=5,count=0,i,j;
    int arr[m][n];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            count++;
            arr[i][j]=count;
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%2d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    spiral(m,n,arr);
}
