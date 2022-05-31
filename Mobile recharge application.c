#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    long long int mobileno;
    int amt;
    char type[10];
    struct node *next;
};
struct node* enqueue(struct node *first,struct node *nw);
void display(struct node *);


int main() {

    struct node *first=NULL,*nw;
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        nw=malloc(sizeof(struct node));
        if(nw==NULL)
        {
            break;
        }
        scanf("%lld%d%s",&nw->mobileno,&nw->amt,nw->type);
        first=enqueue(first,nw);
    }
    display(first);
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

void display(struct node  *first)
{
    int sum1=0,sum2=0,flag1=0,flag2=0;
    struct node *cur=first;
    printf("Postpaid Requests\n");
    while(cur!=NULL)
    {
        if(strcmp(cur->type,"postpaid")==0)
        {
            sum1=sum1+cur->amt;
            flag1=1;
        }
        cur=cur->next;
    }
    if(flag1==1)
    {
        cur=first;
        while(cur!=NULL)
        {
             if(strcmp(cur->type,"postpaid")==0)
             {
                 printf("%lld %d %s\n",cur->mobileno,cur->amt,cur->type);
             }
             cur=cur->next;
        }
             printf("%d\n",sum1);
    }
    else
    {
       printf("Queue Empty\n0\n");
    }

    cur=first;
    printf("Prepaid Requests\n");

    while(cur!=NULL)
    {
            if(strcmp(cur->type,"prepaid")==0)
            {

                sum2=sum2+cur->amt;
                flag2=1;
            }
            cur=cur->next;
    }
    if(flag2==1)
    {
           cur=first;
           while(cur!=NULL)
           {
               if(strcmp("prepaid",cur->type)==0)
               {
                   printf("%lld %d %s\n",cur->mobileno,cur->amt,cur->type);
               }            cur=cur->next;
          }
           printf("%d\n",sum2);
    }
    else
    {
         printf("Queue Empty\n0\n");
    }
}

