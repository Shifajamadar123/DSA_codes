#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node * deletef(struct node *head)
{
    struct node *cur;
    if(head==NULL)
    {
        printf("\nList is empty");
        return(head);
    }
    cur=head;
    head=head->next;
    free(cur);
    return(head);

}

struct node * deleter(struct node *head)
{
    struct node *p1,*p2;
    if(head==NULL)
    {
        printf("\nList is empty");
        return(head);
    }
    if(head->next==NULL)
    {
        p2=head;
        head=NULL;

    }
    else
    {
        for(p1=NULL,p2=head;p2->next!=NULL;p1=p2,p2=p2->next);
        p1->next=NULL;
    }
    free(p2);
    return(head);

}

struct node * deleteany(struct node *head)
{
    struct node *p1,*cur;
    int dat;
    printf("\nEnter data to delete:");
    scanf("%d",&dat);
    if(head==NULL)
    {
        printf("\nList is empty");
        return(head);
    }
    for(p1=NULL,cur=head;cur!=NULL && cur->data!=dat;p1=cur,cur=cur->next);
    if(cur==NULL)
    {
        printf("\nNode not found");
        return(head);
    }
    if(cur==head)
        head=head->next;
    else
        p1->next=cur->next;
    free(cur);
    return(head);
}




struct node * insertf(struct node *head)
{
    struct node *nw;
    nw=(struct node *)malloc(sizeof(struct node));
    if(nw==NULL)
    {
        printf("\nMemomry not allocated");
        exit(0);
    }
    printf("\nEnter data:");
    scanf("%d",&nw->data);
    nw->next=head;
    head=nw;
    return(head);

}

struct node * insertr(struct node *head)
{
    struct node *nw,*temp;
    nw=(struct node *)malloc(sizeof(struct node));
    nw->next=NULL;
    if(nw==NULL)
    {
        printf("\nMemomry not allocated");
        exit(0);
    }
    printf("\nEnter data:");
    scanf("%d",&nw->data);
    if(head==NULL)
    {
        head=nw;
    }
    else
    {
        for(temp=head;temp->next!=NULL;temp=temp->next);
        temp->next=nw;
    }
    return(head);
}

void insertany(struct node *head)
{
   struct node *nw,*cur,*prev;
   int dat;
   printf("\nEnter data after which u want to add a node: ");
   scanf("%d",&dat);
   for(prev=head;prev->data!=dat && prev->next!=NULL;prev=prev->next);
   cur=prev->next;
   if(prev==NULL)
   {
       printf("\nData not found");
       exit(0);
   }

    nw=(struct node *)malloc(sizeof(struct node));
    if(nw==NULL)
    {
        printf("\nMemomry not allocated");
        exit(0);
    }
    printf("\nEnter data:");
    scanf("%d",&nw->data);
    prev->next=nw;
    nw->next=cur;
}

void disp(struct node *head)
{
    struct node *temp;
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        printf("\n%d",temp->data);
    }
}

int main()
{
    struct node *head;
    int n,i,ch;
    head=NULL;
    printf("\nEnter n: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        head=insertr(head);
    while(1)
    {
        printf("\nEnter 1-->insert front  2-->end   3-->any 4-->display 5-->delete front 6-->end 7-->any  8-->exit:  ");
        scanf("%d",&ch);
        switch(ch)
       {
           case 1 : head=insertf(head);  break;
           case 2 : head=insertr(head);  break;
           case 3 : insertany(head);  break;
           case 4 : disp(head); break;
           case 5 : head=deletef(head);  break;
           case 6 : head=deleter(head);  break;
           case 7 : head=deleteany(head);  break;
           case 8 : exit(0);

       }
    }
    return 0;
}
