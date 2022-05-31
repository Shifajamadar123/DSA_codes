#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next,*prev;
};
struct node* getnode();
struct node* insert(struct node *);
struct node* delette(struct node *,struct node *);
void display(struct node *);

int main()
{

    int n,i;
    struct node *first=NULL;
    struct node *temp,*cur;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        first=insert(first);
    }
    temp=first;
    while(temp!=NULL)
        {
            cur=temp->next;
            if(temp->data%2==0)
               first=delette(first,temp);
            temp=cur;
        }
        display(first);
    return 0;
}
void display(struct node *first)
{
    struct node *temp;
    printf("Final List=");
    for(temp=first;temp->next!=NULL;temp=temp->next)
    {
        printf("%d<=>",temp->data);
    }
    printf("%d",temp->data);
}

struct node* getnode()
{
    return(malloc(sizeof(struct node)));
}

struct node * insert(struct node* first)
{
    struct node *temp,*nw;
    nw=getnode();
    scanf("%d",&nw->data);
    if(first==NULL)
    {
        first=nw;
        first->prev=NULL;
        first->next=NULL;
        return(first);
    }
    else
    {
        for(temp=first;temp->next!=NULL;temp=temp->next);
        temp->next=nw;
        nw->next=NULL;
        nw->prev=temp;
        return(first);
    }
}

void freenode(struct node *cur)
{
    free(cur);
}

struct node * delette(struct node* first,struct node* temp)
{
    struct node *cur=temp;
    if(first==NULL || temp==NULL)
    {
        return(first);
    }
    if(temp==first)
    {
        first=temp->next;
    }
    else if(temp->next==NULL)
    {
        temp->prev=NULL;
    }
    else
    {
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
    }
    freenode(cur);
    return(first);
}
