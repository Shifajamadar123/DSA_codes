#include <stdio.h>
#include <stdlib.h>

void read(int a[])
{
    int i;
    printf("\nEnter marks of 10 students:");
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
}

void average(int a[])
{
    int i;
    int p=0;
    int q=0;
    float av=0;
    for(i=0;i<10;i++)
    {
        av=(av+a[i]);
    }
    av=av/10;
    for(i=0;i<10;i++)
    {
        if(a[i]>av)
            p++;
        else
            q++;
    }
    printf("\nAverage:%f\n",av);
    printf("Above average:%d   Below average:%d",p,q);
}

int main()
{
    int a[10];
    read(a);
    average(a);
    return 0;
}
