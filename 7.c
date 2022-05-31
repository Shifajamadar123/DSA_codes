#include <stdio.h>
#include <stdlib.h>

void read(int a[],int n)
{
    int i;
    printf("\nEnter tax of %d taxpayers:",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}

void calc(int a[],int n)
{
    int sum=0,i;
    int p=0;
    int q=0;
    float av;
    for(i=0;i<n;i++)
    {
        if(a[i]>250000)
            p++;
        if(50000<a[i] && a[i]<150000)
            q++;
        sum=sum+a[i];
    }
    av=sum/n;
    printf("\nGreater than 2.5 lakhs:%d   Between 50000 anada 150000:%d  Average tax:%f ",p,q,av);
}

int main()
{
    int n;
    int a[100];
    printf("\nEnter number of taxpayers n:");
    scanf("%d",&n);
    read(a,n);
    calc(a,n);
    return 0;
}
