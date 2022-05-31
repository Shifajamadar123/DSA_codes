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

NODE pushh(NODE top, int item)
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

NODE popp(NODE top)
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

void inc(NODE top, int k,int v, int d)
{
    NODE cur;
    if(top==NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        cur = top;
        int i =0;
        while(cur != NULL)
        {
            if(i>=(d-k))
                cur->data += v;
            printf("%d ", cur->data);
            i++;
            cur = cur->next;
        }
        printf("\n");
    }
}

int main() 
{
    int push,pop,k,v,d,i;
    NODE top=NULL;
    scanf("%d",&push);
    scanf("%d",&pop);
    scanf("%d",&k);
    scanf("%d",&v);
    for(i=0; i<push; i++)
    {
        scanf("%d", &d);
        top = pushh(top, d);
    }
    for(i=0; i<pop; i++)
        top = popp(top);
    d =push -pop;
    inc(top, k, v, d);
    return 0;
}
