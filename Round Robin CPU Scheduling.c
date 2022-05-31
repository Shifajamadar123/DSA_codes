#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int number;
    int time;
    struct node *next;
};
struct node* enqueue(struct node *first,struct node *nw);
void display(struct node *,int);
int main() {

    struct node *first=NULL,*nw;
    int n,i,t,m,prod;
    char T[5],M[5];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        nw=malloc(sizeof(struct node));
        if(nw==NULL)
        {
            break;
        }
        scanf("%d%d",&nw->number,&nw->time);
        first=enqueue(first,nw);
    }
    scanf("%s%d%s%d",T,&t,M,&m);
    prod=t*m;
    display(first,prod);
    return 0;
}


struct node* enqueue(struct node *first,struct node *nw)
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

void display(struct node *first,int t)
{
    struct node *cur=first;
    int flag=0;
    int a[50];
    int l=0;
    int cnt=0;
    while(cur!=NULL)
    {
        cur->time-=t;
        cur=cur->next;
    }
    cur=first;
    while(cur!=NULL)
    {
        if(cur->time>0)
        {
            printf("%d %d\n",cur->number,cur->time);
            flag=1;
        }
        cur=cur->next;

    }
    if(flag==0)
        printf("Queue Empty\n");
    cur=first;
    flag=0;
    printf("Ready Queue\n");
    while(cur!=NULL)
    {
        if(cur->time<=0)
        {
            a[l]=cur->number;
            cnt++;
            l++;
            flag=1;
        }
        cur=cur->next;

    }
    if(flag==0)
        printf("Queue Empty");

    for(l=cnt-1;l>=0;l--)
    {
        printf("%d 0\n",a[l]);
    }
}
