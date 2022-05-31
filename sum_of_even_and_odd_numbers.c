#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void sum(int a[],int n)
{
    int sum1=0;
    int sum2=0;
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]%2==0)
            sum1=sum1+a[i];
        else
            sum2=sum2+a[i];
    }
    printf("Sum of even numbers=%d",sum1);
    printf("\nSum of odd numbers=%d",sum2);
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    scanf("%d",&n);
    int i,*a;
    a=malloc(sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sum(a,n);
    return 0;
}
