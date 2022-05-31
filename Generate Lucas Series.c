#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d",&n);
    int f1=2,f2=1,f3,i;
    if(n>=0 && n<=40)
    {
        if(n==0)
            return 0;
        else if(n==1)
            printf("%d ",f1);
        else if(n==2)
            printf("%d ",f2);
        else
        {
            printf("%d ",f1);
            printf("%d ",f2);
        }  
        for(i=2;i<n;i++)
        {
            f3=f1+f2;
            printf("%d ",f3);
            f1=f2;
            f2=f3;
        }
    }
    else
        printf("Invalid input");
    return 0;
}
