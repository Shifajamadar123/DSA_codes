#include <stdio.h>
#include <stdlib.h>

void read(int a[],int n)
{
    int i;
    printf("\nEnter %d numbers:",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}

void sum(int a[],int n)
{
    int i=0,s=0,m,j;
    printf("\nEnter m:");
    scanf("%d",&m);
    for(i=0;i<n;i=i+m)
    {
        s=0;
        for(j=i;j<i+m && j<n;j++)
        {
            s=s+a[j];
        }
        printf("sum:%d\n",s);
    }
}

int main()
{
    int n;
    int a[100];
    printf("\nEnter n:");
    scanf("%d",&n);
    read(a,n);
    sum(a,n);
    return 0;
}
