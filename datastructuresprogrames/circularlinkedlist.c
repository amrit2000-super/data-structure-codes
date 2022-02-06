#include <stdio.h>
#include <stdlib.h>

typedef struct CLL
{
    int num;
    struct CLL *next;
}CLL;

CLL *head,*tail,*newnode,*p,*p1,*searchptr,*before,*after;

CLL *createnewnode()
{
    CLL *node=(CLL *)malloc(sizeof(CLL));
    node->next=NULL;
    return node;
}

CLL *insertbefore()
{
    int number;
    searchptr=head;
    printf("enter the number before whom you want to insert:\n");
    scanf("%d",&number);
    
    while(searchptr->next!=head)
    {
        if(searchptr->num==number)
        {
            break;
        }

        else
        {
            searchptr=searchptr->next;
        }
    }

    if(searchptr->num!=number)
    {
        printf("number not found\n");
    }

    else if(searchptr==head)
    {
        printf("you are inserting before head node\n");
        newnode=createnewnode();
        newnode->next=head;
        head=newnode;
        tail->next=newnode;
        printf("enter the number you want to insert:\n");
        scanf("%d",&newnode->num);
    }

    else if(searchptr==tail)
    {
        printf("you are inserting before tail node\n");
        newnode=createnewnode();
        before=head;

        while(before->next!=searchptr)
        {
            before=before->next;
        }
        
        before->next=newnode;
        newnode->next=searchptr;
        printf("enter the number you want to insert:\n");
        scanf("%d",&newnode->num);
    }

    else
    {
        printf("you are insertingg somewhere\n");
        newnode=createnewnode();
        before=head;

        while(before->next!=searchptr)
        {
            before=before->next;
        }
        
        before->next=newnode;
        newnode->next=searchptr;
        printf("enter the number you want to insert:\n");
        scanf("%d",&newnode->num);
    }
}

CLL *insertafter()
{
    int number;
    searchptr=head;
    printf("enter the number after whom you want to insert:\n");
    scanf("%d",&number);
    
    while(searchptr->next!=head)
    {
        if(searchptr->num==number)
        {
            break;
        }

        else
        {
            searchptr=searchptr->next;
        }
    }

    if(searchptr->num!=number)
    {
        printf("number not found\n");
    }

    else if(searchptr==head && head==tail)
    {
        printf("you are inserting after head node\n");
        newnode=createnewnode();
        searchptr->next=newnode;
        newnode->next=searchptr;
        tail=newnode;
        printf("enter the number you want to insert:\n");
        scanf("%d",&newnode->num);
    }

    else if(searchptr==head && head!=tail)
    {
        printf("you are inserting after head node\n");
        newnode=createnewnode();
        newnode->next=searchptr->next;
        searchptr->next=newnode;
        printf("enter the number you want to insert:\n");
        scanf("%d",&newnode->num);
    }

    else if(searchptr==tail)
    {
        printf("you are inserting after tail node\n");
        newnode=createnewnode();
        searchptr->next=newnode;
        newnode->next=head;
        tail=newnode;
        printf("enter the number you want to insert:\n");
        scanf("%d",&newnode->num);
    }

    else
    {
        printf("you are inserting somewhere\n");
        newnode=createnewnode();
        newnode->next=searchptr->next;
        searchptr->next=newnode;
        printf("enter the number you want to insert:\n");
        scanf("%d",&newnode->num);
    }
}

CLL *insert()
{
    if(head==NULL)
    {
        newnode=createnewnode();
        head=tail=newnode;
        newnode->next=newnode;
        printf("enter the number you want to insert:\n");
        scanf("%d",&newnode->num);
    }

    else
    {
        int x;
        printf("enter 0 if you want to insert before a particular node or 1 if you want to insert after a particular node\n");
        scanf("%d",&x);

        if(x==0)
        {
            insertbefore();
        }

        else
        {
            insertafter();
        }
    }
}

CLL *delete()
{
    searchptr=head;
    int number;
    if(head==NULL)
    {
        printf("list is empty\n");
    }

    else
    {
        printf("enter the number you want to delete\n");
        scanf("%d",&number);
    
    while(searchptr->next!=head)
    {
        if(searchptr->num==number)
        {
            break;
        }

        else
        {
            searchptr=searchptr->next;
        }
    }

    if(searchptr->num!=number)
    {
        printf("number not found\n");
    }

    else if(searchptr==head && head==tail)
    {
        p1=head;
        head=tail=NULL;
        free(p1);
    }

    else if(searchptr==head && head!=tail)
    {
        p1=head;
        head=head->next;
        tail->next=head;
        free(p1);
    }

    else if(searchptr==tail)
    {
        before=head;
        while(before->next!=tail)
        {
            before=before->next;
        }
        p1=tail;
        tail=before;
        tail->next=head;
        free(p1);
    }

    else
    {
        before=head;
        while(before->next!=searchptr)
        {
            before=before->next;
        }
        p1=searchptr;
        before->next=searchptr->next;
        free(p1);
    }   
    }
}

CLL *display()
{
    p=head;
    if(head==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
     printf("the contents of the list are:\n");
    while(p!=tail)
    {
        printf("%d\t",p->num);
        p=p->next;
    }
    printf("%d",p->num);
    printf("\n");
    }
}

void main()
{
    head,tail,newnode,p,p1,searchptr,before,after=NULL;
    int choice;
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