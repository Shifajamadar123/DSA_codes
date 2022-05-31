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
    int i,j,s=1;
    for(i=0;i<n;i++)
    {
        s=1;
        for(j=2;j<=(a[i]/2);j++)
        {
            if(a[i]%j==0)
            {
                s=0;
            }
        }
        if(s==1)
            printf("\n%d",a[i]);

    }
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


