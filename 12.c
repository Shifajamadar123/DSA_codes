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

void check(int a[],int n)
{
    int i,s=0,temp;
    for(i=0;i<n;i++)
    {
        s=0;
        temp=a[i]%10;
        while(a[i]!=0)
        {
          s=s+(a[i]%10);
          a[i]=a[i]/10;
          if(temp<(a[i]%10))
              temp=a[i]%10;
        }
        printf("\nMax digit in a[%d]:%d   Sum of digits:%d",i,temp,s);
    }
}

int main()
{
    int n;
    int a[100];
    printf("\nEnter n:");
    scanf("%d",&n);
    read(a,n);
    disp(a,n);
    check(a,n);
    return 0;
}
