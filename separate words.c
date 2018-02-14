#include<stdio.h>

char* strcpy(char *arr,int start,int end)
{
    //printf("%d  %d  %d\n",start,end,end-start+1);
    char *str = (char *)malloc((end-start+1)*sizeof(char));
    int i=start,j=0;
    while(i<end)
    {
        str[j++] = arr[i];
        i++;
    }
    str[j]='\0';
    return str;
}

void split(char *str,int *wc,int n,char *arr[n])
{
    int i=0,count=0,j=0;
    while(str[i]!='\0')
    {
        if(str[i]==' ' || str[i]==',' || str[i+1]=='\0')
        {
            if(count)
            {
                if(str[i+1]=='\0')
                    arr[j]= strcpy(str,i-count,i+1);
                else
                    arr[j] = strcpy(str,i-count,i);
                j++;
            }
            count=0;
        }
        else
        {
            count++;
        }
        i++;
    }
    *wc = j;
}

int main()
{
    char arr[] = "    Hello,,,,,,How    are you     ";
    char *ptr[10];
    int word_count=0;
    split(arr,&word_count,10,ptr);
    int i=0;
    while(i<word_count)
    {
        printf("%s\n",ptr[i]);
        i++;
    }
}
