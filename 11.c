#include <stdio.h>
#include <stdlib.h>

void read(int a[],int n)
{
    int i;
    printf("\nEnter units of %d flats:",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}

void calc(int a[],int n)
{
    int i;
    float s;
    for(i=0;i<n;i++)
    {
        if(a[i]>0  && a[i]<100)
        {
            s=1.5*a[i];
            printf("The bill of flat %d is:%f\n",i+1,s);
        }
        if(a[i]>100  && a[i]<250)
        {
            s=2.3*a[i];
            printf("The bill of flat %d is:%f\n",i+1,s);
        }
        if(a[i]>250  && a[i]<600)
        {
            s=4*a[i];
            printf("The bill of flat %d is:%f\n",i+1,s);
        }
        if(a[i]>600)
        {
            s=5.5*a[i];
            printf("The bill of flat %d is:%f\n",i+1,s);
        }
    }
}

int main()
{
    int n;
    int a[100];
    printf("\nEnter number of flats n:");
    scanf("%d",&n);
    read(a,n);
    calc(a,n);
    return 0;
}
