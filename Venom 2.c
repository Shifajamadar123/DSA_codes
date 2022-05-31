#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    char name[20];
    int age;
    struct node *next;
};

struct node* insert(struct node *,struct node *);
struct node* newline(struct node *,struct node *,int);
void display(struct node *);
void position(struct node *);
void sum(struct node *,int);

int main() {

    int n,i,k;
    struct node *first=NULL,*nw,*head2=NULL;
    scanf("%d",&n);
    scanf("%d",&k);
    if(n>=1)
    {
        for(i=0;i<n;i++)
        {
            nw=malloc(sizeof(struct node));
            if(nw==NULL)
            {
                break;
            }
            scanf("%s%d",nw->name,&nw->age);
            first=insert(first,nw);
        }
        if(k>=0 && k<=(n/2))
        {
            head2=newline(head2,first,k);
        }
        display(head2);
        position(head2);
        sum(head2,n);
    }
    else
    {
        printf("N should be greater than 0");
    }
    return 0;
}


struct node* insert(struct node *first,struct node *nw)
{
    struct node *temp;
    if(first==NULL)
    {
        first=nw;
        nw->next=NULL;
    }
    else
    {
        for(temp=first;temp->next!=NULL;temp=temp->next);
        temp->next=nw;
        nw->next=NULL;
    }
    return(first);
}

struct node* newline(struct node *head2,struct node *first,int k)
{
    struct node *temp,*nw;
    int i=0;
    for(temp=first;temp!=NULL;temp=temp->next)
    {
        if(temp->age>=18 && temp->age<=25)
        {
            i=i+1;
            nw=NULL;
            nw=malloc(sizeof(struct node));
            if(nw==NULL)
            {
                break;
            }
            strcpy(nw->name,temp->name);
            nw->age=temp->age;
            head2=insert(head2,nw);
        }
        if(i==k)
        {
            break;
        }
    }
    return(head2);
    
}

void display(struct node *head2)
{
    struct node *temp;
    for(temp=head2;temp!=NULL;temp=temp->next)
    {
        printf("%s %d\n",temp->name,temp->age);
    }
}

void position(struct node *head2)
{
    struct node *temp;
    char nam[20];
    int pos=0;
    scanf("%s",nam);
    for(temp=head2;temp!=NULL && strcmp(temp->name,nam)!=0;temp=temp->next,pos++);
    if(temp==NULL)
    {
        printf("0\n");
        return;
    }
    printf("%d\n",pos+1);
}

void sum(struct node *head,int n)
{
    int s=0,s1,i=0;
    struct node *temp;
    for(temp=head;temp!=NULL;temp=temp->next,s=s+300,i++);
    s1=(n-i)*300;
    printf("%d\n",s1);
    printf("%d\n",s);
}


