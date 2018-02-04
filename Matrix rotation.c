#include<stdio.h>

void swap(int *a,int *b)
{
    int temp = *a; *a = *b; *b = temp;
}

void print(int arr[4][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%2d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void rotate(int m,int n,int arr[][n],int flag)
{
    int rl=0,rh=m-1,cl=0,ch=n-1;
    int p=n/2,i=0,j=0;
    if(!flag)
    {
        do{
            //printf("rl: %d  rh: %d  cl: %d  ch: %d\n",rl,rh,cl,ch);
            for(i=rl;i<rh;i++)
            {
                swap(&arr[cl][i],&arr[i][rh]);
            }
            //print(arr);
            for(j=0;j<ch-cl;j++)
            {
                swap(&arr[cl+j][rh],&arr[ch][ch-j]);
            }
            //print(arr);
            for(i=rh;i>rl;i--)
            {
                swap(&arr[ch][i],&arr[i][rl]);
            }
            //print(arr);
            rl++;
            rh--;
            cl++;
            ch--;
        }while(--p);
    }
}

int main()
{
    int m=10,n=10,count=0,i,j;
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
    rotate(m,n,arr,0);

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%2d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


