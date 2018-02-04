#include<stdio.h>

void spiral(int n,int rl,int rh,int cl,int ch,int arr[][n])
{
    if(rl>rh || cl>ch)
        return;
    printf("rl: %d  rh: %d  cl: %d  ch: %d  \n",rl,rh,cl,ch);
    spiral(n,rl+1,rh-1,cl+1,ch-1,arr);
    static int i,j;
    if(j==0)
        j=ch;
    if(ch!=cl)
    {
        for(i=rl;i<rh;i++)
        {
            printf("%d ",arr[j][i]);
        }
    }

    for(j=ch;j>cl;j--)
    {
        printf("%d ",arr[j][i]);
    }
    if(j<0)
        return;
    for(i=rh;i>=rl;i--)
    {
        printf("%d ",arr[j][i]);
    }
    cl--;
    if(i<0)
        return;
    for(j=cl+1;j<=ch;j++)
    {
        printf("%d ",arr[j][i]);
    }
    rh--;
    i--;
}

int main()
{
    int m=5,n=3,count=0,i,j;
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
    spiral(n,0,n-1,0,m-1,arr);
}


