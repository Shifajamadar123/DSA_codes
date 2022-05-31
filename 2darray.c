#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void multiply(int **a1,int **a2,int n)
{
    int **c;
    int i,j,k;
    c=malloc(sizeof(int *)*n);
    c[0]=malloc(sizeof(int)*(n*n));
    for(i=1;i<n;i++)
        c[i]=c[i-1]+n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            c[i][j]=0;    
            for(k=0;k<n;k++)    
            {    
                c[i][j]+=a1[i][k]*a2[k][j];    
            }   
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",c[i][j]);
    }
    
    
}

int main() {

    int **a1,**a2;
    int T,n1,i,j,k;
    scanf("%d",&T);
    for(k=0;k<T;k++)
    {
        scanf("%d",&n1);
        a1=malloc(sizeof(int *)*n1);
        a1[0]=malloc(sizeof(int)*(n1*n1));
        for(i=1;i<n1;i++)
            a1[i]=a1[i-1]+n1;
        for(i=0;i<n1;i++)
        {
            for(j=0;j<n1;j++)
                scanf("%d",&a1[i][j]);
        }
        a2=malloc(sizeof(int *)*n1);
        a2[0]=malloc(sizeof(int)*(n1*n1));
        for(i=1;i<n1;i++)
            a2[i]=a2[i-1]+n1;
        for(i=0;i<n1;i++)
        {
            for(j=0;j<n1;j++)
                scanf("%d",&a2[i][j]);
        }
        multiply(a1,a2,n1);
        printf("\n");
    }
    return 0;
}
