#include <stdio.h>
#include <stdlib.h>

void read(int a[])
{
    int i;
    printf("\nEnter expenditures in all months:");
    for(i=0;i<12;i++)
    {
        scanf("%d",&a[i]);
    }
}

void calc(int a[])
{
    int i;
    int pen;
    int max=a[0];
    float av=0;
    int min=a[0];
    for(i=0;i<12;i++)
    {
        if(a[i]>max)
            max=a[i];
        if(a[i]<min)
            min=a[i];
        av=av+a[i];
    }
    av=av/12;
    for(i=0;i<12;i++)
    {
        if(a[i]==max)
            printf("Max in month %d\n",i+1);
        if(a[i]==min)
            printf("Min in month %d\n",i+1);
        if(a[i]>35000)
        {
            printf("More than 35000 in month %d\n",i+1);
        }
    }
    printf("\nAvg expenditure:%f",av);
}

int main()
{
    int a[12];
    read(a);
    calc(a);
    return 0;
}
