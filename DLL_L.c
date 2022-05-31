#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node* getnode()
{
    return(malloc(sizeof(struct node)));
}

void addNode(struct node **first,int p,int x)
{
    struct node *nw,*cur;
    int i;
    nw=getnode();
    nw->data=x;
    if(*first==NULL && p>0)
        return;
    if(p==0)
    {
        nw->prev=NULL;
        nw->next=*first;
        (*first)->prev=nw;
        (*first)=nw;
        return;
    }
    else
    {
        for(cur=*first,i=0;i<p-1 && cur->next!=NULL;cur=cur->next,i++);
        if(cur->next==NULL)
        {
            cur->next=nw;
            nw->next=NULL;
            nw->prev=cur;
            return;
        }
        else
        {
            nw->next=cur->next;
            cur->next->prev=nw;
            cur->next=nw;
            nw->prev=cur;
            return;
        }
    }
}

void display(struct node *first)
{
    struct node *temp;
    for(temp=first;temp!=NULL;temp=temp->next)
    {
        printf("%d  ",temp->data);
    }
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


int main() {

    int n,i,p,x;
    struct node *first=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        first=insert(first);
    }
    scanf("%d%d",&p,&x);
    if(p>=0 && p<n)
    {
        addNode(&first,p,x);
    }
    display(first);
    return 0;
}
