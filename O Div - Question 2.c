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

Node getnode(int data)
{
    Node nw;
    nw=(Node)malloc(sizeof(struct node));
    if(nw==NULL)//Stack full
    {
        return(nw);
    }
    nw->data=data;
    return(nw);
}

Node push(Node first,int data)
{
   Node temp,nw;
    nw=getnode(data);
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
    Node temp=first,prev;
    if(first==NULL)
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
        for(prev=NULL,temp=first;temp->next!=NULL;prev=temp,temp=temp->next);
        free(temp);
        prev->next=NULL;
        return(first);
    }
}

void display(Node first)
{
    Node temp;
    if(first==NULL)
        return;
    for(temp=first;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->data);
    }
}

void exchange(Node *first1,Node *first2)
{
    Node temp1,nf=NULL;
    for(temp1=*first1;temp1!=NULL;temp1=temp1->next)
    {
        nf=push(nf,temp1->data);
    }
    *first1=NULL;
    for(temp1=*first2;temp1!=NULL;temp1=temp1->next)
    {
        *first1=push(*first1,temp1->data);
    }
    *first2=NULL;
    for(temp1=nf;temp1!=NULL;temp1=temp1->next)
    {
        *first2=push(*first2,temp1->data);
    }
    
}

int main() 
{
    int n1,n2,i,data;
    int x1,x2;
    Node first1=NULL,first2=NULL;
    scanf("%d",&n1);
    scanf("%d",&n2);
    for(i=0;i<n1;i++)
    {
        scanf("%d",&data);
        first1=push(first1,data);
    } 
    for(i=0;i<n2;i++)
    {
        scanf("%d",&data);
        first2=push(first2,data);
    }
    scanf("%d%d",&x1,&x2);
    for(i=0;i<x1;i++)
    {
        first1=pop(first1);
    }
    for(i=0;i<x2;i++)
    {
        first2=pop(first2);
    }
    exchange(&first1,&first2);
    display(first1);
    printf("\n");
    display(first2);
    return 0;
}
