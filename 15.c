#include <stdio.h>
#include <stdlib.h>

void read(float a[],float b[],int n)
{
    int i;
    printf("\nEnter arr:");
    for(i=0;i<n;i++)
    {
        scanf("%f",&a[i]);
    }
    printf("\nEnter dep:");
    for(i=0;i<n;i++)
    {
        scanf("%f",&b[i]);
    }
}

void check(float a[],float b[],int n)
{
    int i,j,s=0,k=0;
    for(i=0;i<n;i++)
    {
        s=0;
        for(j=0;j<n;j++)
        {
            if((b[j]>a[i] && b[j]<a[i+1])|| (a[i]>b[j] && a[i]<b[j+1]))
                s++;
        }
        if(s>k)
            k=s;
    }
    printf("\nPlatforms needed:%d",k);
}

int main()
{
    int n;
    float a[100],b[100];
    printf("\nEnter n:");
    scanf("%d",&n);
    read(a,b,n);
    check(a,b,n);
    return 0;
}
