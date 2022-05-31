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
struct node* rotate(struct node *,int);
void display(struct node *);

int main() {

    int n,i,k;
    struct node *first=NULL;
    scanf("%d",&n);
    scanf("%d",&k);
    for(i=0;i<n;i++)
        first=insert(first); 
    if(k>=1)
        first=rotate(first,k);
    display(first);
    return 0;
}

void display(struct node* first)
{
    struct node *temp;
    for(temp=first;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->data);
    }
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

struct node *rotate(struct node *first,int k)
{
    if(first==NULL)
        return first;
    int c = 0;
    struct node *cur=first,*nex=NULL,*newhead=NULL;
    while(cur!=NULL && c<k)
    {
        nex= cur->next;
        cur->next=newhead;
        newhead=cur;
        cur=nex;
        c++;
    }
    if (nex !=  NULL)
       first->next =rotate(nex,k);
    return (newhead);
}
