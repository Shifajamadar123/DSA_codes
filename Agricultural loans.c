#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    char name[20];
    char type[20];
    int amount;
    struct node *next;
};
//Queue using list can be implemented using insert rear and delete front
struct node * insert(struct node *,struct node *);
void display(struct node *);
void displayinfo(struct node *);


int main() {

    int N,i;
    struct node *first=NULL,*nw;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        nw=malloc(sizeof(struct node));
        if(nw==NULL)
        {
            break;  //if queue is full dont insert
        }
        scanf("%s%s%d",nw->name,nw->type,&nw->amount);
        first=insert(first,nw);
    }
    display(first);
    
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

void display(struct node *first)
{
    int sum1=0,sum2=0,count=0;
    struct node *temp;
    printf("Short term Application details\n");
    for(temp=first;temp!=NULL;temp=temp->next)
    {
        if(strcmp(temp->type,"short")==0 && (temp->amount)<=50000)
        {
            displayinfo(temp);
            sum1=sum1+(temp->amount);
            count++;
        }
    }
    if(sum1==0)
    {
        printf("Queue Empty");
    }
    else
        printf("%d",sum1);
    printf("\nLong term Application details\n");
    for(temp=first;temp!=NULL;temp=temp->next)
    {
        if(strcmp(temp->type,"long")==0 && (temp->amount)<=100000)
        {
            displayinfo(temp);
            sum2=sum2+(temp->amount);
            count++;
        }
    }
    if(sum2==0)
    {
        printf("Queue Empty");
    }
    else
        printf("%d",sum2);
    printf("\n%d",count);
    
}

void displayinfo(struct node *temp)
{
    printf("%s %s %d\n",temp->name,temp->type,temp->amount);
}
