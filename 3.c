#include <stdio.h>
#include <stdlib.h>

void read(int a[],int n)
{
    int i;
    printf("\nEnter age of %d employees:",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}

void bonus(int a[],int n)
{
    int i,B;
    for(i=0;i<n;i++)
    {
        if(a[i]>=5 && a[i]<=7)
        {
            B=1060;
            printf("Bonus of employee %d: %d\n",i+1,B);
        }
        if(a[i]>=8 && a[i]<=10)
        {
            B=4260;
            printf("Bonus of employee %d: %d\n",i+1,B);
        }
        if(a[i]>10)
        {
            B=9630;
            printf("Bonus of employee %d: %d\n",i+1,B);
        }
        if(a[i]<5)
            printf("Invalid age of employee %d\n",i+1);
    }
}

void salary(int a[],int n)
{
    int i,s;
    for(i=0;i<n;i++)
    {
        if(a[i]>=5 && a[i]<=7)
        {
            s=10600+1060;
            printf("Salary of employee %d: %d\n",i+1,s);
        }
        if(a[i]>=8 && a[i]<=10)
        {
            s=21300+4260;
            printf("Salary of employee %d: %d\n",i+1,s);
        }
        if(a[i]>10)
        {
            s=32100+9630;
            printf("Salary of employee %d: %d\n",i+1,s);
        }
        if(a[i]<5)
            printf("Invalid age of employee %d\n",i+1);
    }
}




int main()
{
    int n;
    int a[100];
    printf("\nEnter number of employees n:");
    scanf("%d",&n);
    read(a,n);
    bonus(a,n);
    salary(a,n);
    return 0;
}
