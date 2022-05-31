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

void check(int a[],int n)
{
    int i,j,k;
    int x=0,y=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            x=x+a[j];
        }
        for(k=n-1;k>i+1;k--)
        {
            y=y+a[k];
        }
        if(x==y)
        {
            printf("\nEquilibrium index:%d",i);
            exit(0);
        }

    }
    printf("\nNo equilibrium index");
}

int main()
{
    int n;
    int a[100];
    printf("\nEnter n:");
    scanf("%d",&n);
    read(a,n);
    check(a,n);
    return 0;
}
