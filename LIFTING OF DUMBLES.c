#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int weight;
    struct node *next;
};

struct node * enqueue(struct node *,struct node *);
int game(struct node *,int);

int main() {

    int n,m,k1,k2,i;
    struct node *first=NULL,*nw;
    int score1,score2;
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d%d",&k1,&k2);
    for(i=0;i<n;i++)
    {
        nw=malloc(sizeof(struct node));
        if(nw==NULL)
        {
            break;
        }
        scanf("%d",&nw->weight);
        first=enqueue(first,nw);
    }
    if(m>=2)
    {
        score1=game(first,k1);
        printf("%d\n",score1);
        score2=game(first,k2);
        printf("%d\n",score2);
        if(score1>score2)
        {
            printf("The winner is King");
        }
        if(score2>score1)
            printf("The winner is Sultan");
    }
    else
        printf("Minimum number of players should be 2");
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

int game(struct node *first,int k)
{
    struct node *temp;
    int s=0;
    for(temp=first;temp->next!=NULL;temp=temp->next)
    {
        if((temp->weight)%k==0 && temp->weight>temp->next->weight)
            s=s+temp->weight;
    }
    if((temp->weight)%k==0 && temp->weight >first->weight)
    {
        s=s+temp->weight;
    }
    return(s);
}

