#include <stdio.h>
#include <stdlib.h>

int SIZE;
int l=0;

typedef struct CLL
{
    int num;
    struct CLL *next;
}CLL;

CLL *head,*tail,*p,*p1,*newnode;

CLL *createnewnode()
{
    CLL *node=(CLL *)malloc(sizeof(CLL));
    node->next=NULL;
    return node;
}

CLL *insert()
{
    if(l==SIZE)
    {
        printf("queue is full\n");
    }

    else
    {
        if(head==NULL)
        {
            newnode=createnewnode();
            head=tail=newnode;
            newnode->next=newnode;
            printf("enter the number you want to insert:\n");
            scanf("%d",&newnode->num);
            l++;
        }

        else
        {
            newnode=createnewnode();
            tail->next=newnode;
            newnode->next=head;
            tail=newnode;
            printf("enter the number you want to insert:\n");
            scanf("%d",&newnode->num);
            l++;
        }  
    }
}

CLL *delete()
{
    if(l==0)
    {
        printf("queue is empty\n");
    }

    else
    {
        if(head==tail)
        {
            p=head;
            head=tail=NULL;
            l--;
            free(p);
        }

        else
        {
            p=head;
            head=head->next;
            tail->next=head;
            l--;
            free(p);
        }
    }
}

CLL *display()
{
    if(l==SIZE)
    {
        printf("queue is full\n");
        p1=head;
        printf("the contents of the queue are:\n");
        while(p1->next!=head)
        {
            printf("%d\t",p1->num);
            p1=p1->next;
        }
        printf("%d\t",p1->num);
        printf("\n");
    }

    else if(l==0)
    {
        printf("queue is empty\n");
    }

    else
    {
        p1=head;
        printf("the contents of the queue are:\n");
        while(p1->next!=head)
        {
            printf("%d\t",p1->num);
            p1=p1->next;
        }
        printf("%d\t",p1->num);
        printf("\n");
    }
}

void main()
{
    head,tail,p,p1,newnode=NULL;
    int choice;
    printf("enter the size of the queue:\n");
    scanf("%d",&SIZE);
    while(1)
    {
    printf("enter the choice:\n");
    printf("1:insert\n 2:delete\n 3:display\n 4:exit\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
        insert();
        break;

        case 2:
        delete();
        break;

        case 3:
        display();
        break;

        default:
        exit(0);
        break;
    }
    }
}