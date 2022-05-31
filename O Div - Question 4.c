#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};
typedef struct stack* NODE;

NODE push(NODE top, int item)
{
    NODE tmp = (NODE)malloc(sizeof(struct stack));
    if(tmp==NULL)
    {
        printf("Memory error.\n");
        exit(0);
    }
    tmp->data = item;
    if(top==NULL)
        tmp->next = NULL;
    else
        tmp->next = top;
    return tmp;
}

NODE pop(NODE top)
{
    NODE tmp;
    if(top==NULL)
    {
        printf("Shelf is empty.\n");
    }
    else
    {
        tmp = top;
        top = top->next;
        free(tmp);
    }
    return top;
}

void display(NODE top, int k)
{
    NODE cur;
    int cw=0;
    int cl=0;
    if(top==NULL)
    {
        return;
    }
    else
    {
        cur = top;
        while(cur != NULL)
        {
            if(cur->data % k == 0)
            {
                printf("W ");
                cw++;
            }
            else
            {
                printf("L ");
                cl++;
            }
            cur = cur->next;
        }
        printf("\n%d\n%d", cw, cl);
    }
}

int main()
{
    int n, k, d;
    NODE top = NULL;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &d);
        top = push(top, d);
    }
    display(top, k);
    return 0;
}
