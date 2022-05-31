#include <stdio.h>
#include <stdlib.h>

void read(int a[],int b[],int n)
{
    int i;
    printf("\nEnter a:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEnter b:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
}

void disp(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d  ",a[i]);
}

void exchange(int a[],int b[],int n)
{
    int i;
    int temp;
    for(i=0;i<n;i++)
    {
        temp=a[i];
        a[i]=b[i];
        b[i]=temp;
    }
    printf("\nElements of a:\n");
    disp(a,n);
    printf("\nElements of b:\n");
    disp(b,n);
}

int main()
{
    int n;
    int a[100],b[100];
    printf("\nEnter n:");
    scanf("%d",&n);
    read(a,b,n);
    exchange(a,b,n);
    return 0;
}
