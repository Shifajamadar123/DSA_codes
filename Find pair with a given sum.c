#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *prev,*next;
};

struct node *insert(struct node *first,int d)
{
    struct node  *temp = malloc(sizeof(struct node));
    struct node *cur=first;
    temp->data=d;
    temp->prev=temp->next=NULL;
    if(first==NULL)
        return temp;
    while(cur->next!=NULL)
        cur = cur->next;
    cur->next = temp;
    temp->prev = cur;
    return first;
}

int pair(struct node *first,int k)
{
    struct node *temp,*cur;
    for(temp=first;temp!=NULL;temp=temp->next)
    {
        for(cur=first;cur!=NULL;cur=cur->next)
        {
            if(temp->data+cur->data==k)
            {
                printf("YES\n");
                return(1);
            }
        }
    }
    return(0);
}

int main()
{
    struct node *first[50] = {NULL};
    int t,i;
    int d,flag=0;
    int k[50];
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        while(1)
        {
             scanf("%d",&d);
             if(d==-1)
                break;
             first[i] = insert(first[i],d);
        }
        scanf("%d",&k[i]);
    }
    for(i=0; i<t; i++)
    {
        flag=pair(first[i],k[i]);
        if(flag==0)
        {
            printf("NO\n");
        }
        flag=0;
    }
    return 0;
}
