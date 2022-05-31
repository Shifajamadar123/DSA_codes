#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    char data[1000];
    struct node *next,*prev;
};
struct node* getnode();
struct node* insert(struct node *);
void display(struct node *);
struct node *delette(struct node *,struct node *);

int main() {

    int n,i,q;
    char dat[1000];
    struct node *first=NULL,*temp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        first=insert(first);
    scanf("%d",&q);
    if(q>=1 && q<=n)
    {
        for(i=0;i<q;i++)
        {
            scanf("%s",dat);
            for(temp=first;temp!=NULL;temp=temp->next)
            {
                if(strcmp(temp->data,dat)==0)
                {
                    first=delette(first,temp);
                    break;
                }
            }
        }
    }
    display(first);
    return 0;
}
void display(struct node* first)
{
    struct node *temp;
    for(temp=first;temp!=NULL;temp=temp->next)
    {
        printf("%s ",temp->data);
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
    scanf("%s",nw->data);
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

struct node* delette(struct node *first,struct node *temp)
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
        temp->prev->next=NULL;
    }
    else
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
    free(cur);
    return(first);
}
