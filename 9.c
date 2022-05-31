#include <stdio.h>
#include <stdlib.h>

void read(int a[],int n)
{
    int i;
    printf("\nEnter marks of %d students:",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}

void calc(int a[],int n)
{
    int i;
    int p=0;
    int q=0;
    int f=0;
    for(i=0;i<n;i++)
    {
        if(a[i]%2==0)
            p++;
        else
            q++;
        if(a[i]==10)
        {
            f++;
            printf("\nStudent %d has scored 100%",i+1);
        }
    }
    printf("\nEven marks:%d   Odd marks:%d",p,q);
}

int main()
{
    int n;
    int a[100];
    printf("\nEnter number of students n:");
    scanf("%d",&n);
    read(a,n);
    calc(a,n);
    return 0;
}
