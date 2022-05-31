#include <stdio.h>
#include <stdlib.h>

void read(int a[],int n)
{
    int i;
    printf("\nEnter %d elements:",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}

void count(int a[],int n)
{
    int i;
    int o=0,p=0;
    for(i=0;i<n;i++)
    {
        if(a[i]<0)
            o++;
        else
            p++;
    }
    printf("\nPositive numbers:%d",p);
    printf("\nNegative numbers:%d",o);
}

int main()
{
    int n;
    int a[100];
    printf("\nEnter n:");
    scanf("%d",&n);
    read(a,n);
    count(a,n);
    return 0;
}
