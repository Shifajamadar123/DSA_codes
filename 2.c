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

void check(int a[],int n)
{
    int i;
    int key;
    printf("\nEnter key:");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            printf("\nKey found at index %d",i);
            break;
        }
        else
            continue;
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
