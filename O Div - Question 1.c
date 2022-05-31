#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node* Node;

Node getnode()
{
    Node nw;
    nw=(Node)malloc(sizeof(struct node));
    if(nw==NULL)//Stack full
    {
        return(nw);
    }
    scanf("%d",&nw->data);
    return(nw);
}

Node push(Node first)
{
    Node temp,nw;
    nw=getnode();
    if(first==NULL)
    {
        first=nw;
        nw->next=NULL;
        return(first);
    }
    else
    {
        for(temp=first;temp->next!=NULL;temp=temp->next);
        temp->next=nw;
        nw->next=NULL;
        return(first);
    }
}

Node pop(Node first)
{
    Node temp=first;
    if(first==NULL)//stack empty
    {
        return(first);
    }
    else if(first->next==NULL)
    {
        free(temp);
        first=NULL;
        return(first);
    }
    else
    {
        first=first->next;
        free(temp);
        return(first);
    }
}

void operation(Node first,int i,int n)
{
    Node temp,cur;
    int j;
    int reverse=0,remainder=0;
    if(first==NULL)
        return;
    for(temp=first,j=i;j<n-i-1 && temp!=NULL;temp=temp->next,j++);
    for(cur=first,j=0;j<i && cur->next!=NULL;cur=cur->next,j++);
    while (temp->data != 0)
    {
       remainder = temp->data % 10;
       reverse = reverse * 10 + remainder;
       temp->data /= 10;
    }
    temp->data=reverse;
    remainder=0;
    reverse=0;
    while (cur->data != 0)
    {
       remainder = cur->data % 10;
       reverse = reverse * 10 + remainder;
       cur->data /= 10;
    }
    cur->data=reverse;
}

void display(Node first)
{
    Node temp;
    for(temp=first;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->data);
    }
}

int main()
{
    int n,i,p,t,reverse=0,remainder=0;
    Node first=NULL,temp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        first=push(first);
    }
    scanf("%d",&p);
    for(i=0;i<p;i++)
    {
        first=pop(first);
    }
    t=(n-p)/2;
    if(first!=NULL)
    {
        for(i=0;i<t;i++)
        {
            operation(first,i,n-p);
        }
    }
    if(t%2!=0)
    {
        for(temp=first,i=0;temp!=NULL && i!=t;temp=temp->next,i++);
        while (temp->data != 0)
        {
           remainder = temp->data % 10;
           reverse = reverse * 10 + remainder;
           temp->data /= 10;
        }
        temp->data=reverse;
    }
    display(first);
    return 0;
}


