#include<stdio.h>
#include<math.h>
#include<stdlib.h>

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
    int i,z;
    for(i=0;i<n;i++)
    {
        z=sqrt(a[i]);
        if(a[i]==z*z)
        {
            printf("a[%d] is a perfect square\n",i);
        }
        else
            printf("a[%d] is not a perfect square\n",i);
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
