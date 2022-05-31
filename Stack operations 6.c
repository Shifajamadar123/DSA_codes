#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int a[100000],n,k,i;
    int max=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    // top=n-1;
    if(k%2==0)
    {
        
        for(i=0;i<=k%n;i+=2)
            if(a[i]>max)
                max=a[i];
    }
    
    else
    {
        
        for(i=1;i<=k%n;i+=2)
            if(a[i]>max)
                max=a[i];
    }
    
    printf("%d",max);
    
    return 0;
}
