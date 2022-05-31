#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node * getNode(int d)
{
    struct node * n = (struct node *)malloc(sizeof(struct node));
    if(n==NULL)
        exit(0);
    n->data = d;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

struct node * sort(struct node * head, int k)
{
    if(head==NULL || head->next==NULL)
        return head;
    struct node *temp1,*temp2,*temp3,*i,*j;
    for(i = head->next; i!=NULL; i=i->next)
    {
        j = i;
        while(j->prev!=NULL && j->prev->data>j->data)
        {
            temp1 = j->prev->prev;
            temp2 = j->prev;
            temp3 = j->next;
            j->prev->next = temp3;
            j->prev->prev = j;
            j->prev = temp1;
            j->next = temp2;
            if(temp1 != NULL)
                temp1->next = j;
            if(temp3 != NULL)
                temp3->prev = temp2;
        }
        if(j->prev == NULL)
            head = j;
    }
    return head;
}

struct node * insert_end(struct node * head, int d)
{
    struct node *temp = getNode(d);
    if(head==NULL)
        return temp;
    struct node * cur = head;
    while(cur->next!=NULL)
        cur = cur->next;
    cur->next = temp;
    temp->prev = cur;
    return head;
}

void display(struct node * head)
{
    if(head==NULL)
        printf("Linked list is empty.\n");
    else
    {
        struct node * cur = head;
        while(cur!=NULL)
        {
            printf("%d ", cur->data);
            cur = cur->next;
        }
        printf("%d", -1);
    }
}

int main()
{
    struct node * head = NULL;
    int t, k;
    signed int d;
    scanf("%d", &t);
    scanf("%d", &k);
    while(1)
    {
        scanf("%d", &d);
        if(d==-1)
            break;
        head = insert_end(head,d);
    }
    head = sort(head,k);
    display(head);
    return 0;
}

