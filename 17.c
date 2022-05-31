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

void disp(int a[],int n)
{
    int i;
    printf("\nArray elements are: ");
    for(i=0;i<n;i++)
        printf("%d  ",a[i]);
}

void rev(int a[],int n)
{
    int temp,i;
    for(i = 0; i<n/2; i++)
    {
        temp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = temp;
    }
    disp(a,n);
}

int main()
{
    int n;
    int a[100];
    printf("\nEnter n:");
    scanf("%d",&n);
    read(a,n);
    rev(a,n);
    return 0;
}
