#include<stdio.h>
// Newman-Conway sequence formula = P(n) = P(P(n - 1)) + P(n - P(n - 1))
int sequence(int n)
{
    int p[n],i;
    p[0]=0;
    p[1] = 1;
    p[2] = 1;

    printf("%d %d ",p[1],p[2]);

    for(i=3;i<=n;i++)
    {
        p[i] = p[p[i-1]]+p[i-p[i-1]];
        printf("%d ",p[i]);
    }
}

int main()
{
    int n,i;
    scanf("%d",&n);
    sequence(n);
}
