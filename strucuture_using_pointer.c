#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee
{
    int id;
    char name[50];
};

void read(struct employee *p)
{
    int i;
    printf("\nEnter details:  ");
    for(i=0;i<10;i++)
    {
        scanf("%d%s",&p->id,p->name);
        p++;
    }
}

void print(struct employee *p)
{
    int i;
    printf("\nEntered details:  ");
    for(i=0;i<10;i++)
    {
        printf("%d  %s\n",p->id,p->name);
        p++;
    }
}

int main()
{
    struct employee a[10],*p;
    p=a;
    read(p);
    print(p);
    return 0;
}
