#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee
{
    int id;
    char name[50];
};

void read(struct employee a[])
{
    int i;
    printf("\nEnter details:  ");
    for(i=0;i<10;i++)
    {
        scanf("%d%s",&a[i].id,a[i].name);
    }
}

void print(struct employee a[])
{
    int i;
    printf("\nEntered details:  ");
    for(i=0;i<10;i++)
    {
        printf("%d  %s\n",a[i].id,a[i].name);
    }
}

int main()
{
    struct employee a[10];
    read(a);
    print(a);
    return 0;
}
