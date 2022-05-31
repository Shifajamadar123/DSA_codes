#include <stdio.h>
#include <stdlib.h>

void read(int a[],int n)
{
    int i;
    printf("\nEnter rankings of %d students:",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}

void arrange(int a[],int n)
{
    int i,j;
    int temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j+1]<a[j])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("\nArranged rankings:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    printf("\nLowest rank:%d  Highest rank:%d",a[i-1],a[0]);
}

int main()
{
    int n;
    int a[100];
    printf("\nEnter number of students n:");
    scanf("%d",&n);
    read(a,n);
    arrange(a,n);
    return 0;
}
