#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* creatlist(struct node *first)
{
    struct node *nw,*temp;
    int n,i;
    printf("\nEnter n:  ");
    scanf("%d",&n);
    if(n==0)
        return(first);
    first=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter data 1:  ");
    scanf("%d",&first->data);
    temp=first;
    for(i=2;i<=n;i++)
    {
        nw=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter data %d:  ",i);
        scanf("%d",&nw->data);
        temp->next=nw;
        nw->next=NULL;
        temp=temp->next;
    }
    return(first);
}
void display(struct node *first)
{
    printf("-----------------------------------------\n");
    while(first!=NULL)
    {
        printf("%d  ",first->data);
        first=first->next;
    }
    printf("\n-----------------------------------------\n");
}

struct node* reverse(struct node *first)
{
    struct node *t1,*t2,*t3;
    if(first==NULL)
    {
        printf("\nList empty");
        return(first);
    }
    t1=first;
    t2=t1->next;
    t3=t2->next;
    while(t2!=NULL)
    {
        t2->next=t1;
        t1=t2;
        t2=t3;
        if(t3!=NULL)
            t3=t3->next;
    }
    first->next=NULL;
    first=t1;
    return(first);
}

int main()
{
    struct ndoe *first=NULL;
    first=creatlist(first);
    printf("\nBefore reversing:\n");
    display(first);
    first=reverse(first);
    display(first);
    return 0;
}
