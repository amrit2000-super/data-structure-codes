#include <stdio.h>
#include <stdlib.h>

struct myList
{
    int num;
    struct myList *prev;
    struct myList *next;
}*head,*tail,*p1,*p,*searchptr,*newnode,*after,*before,*after1;

struct myList *createnewnode()
{
    p=head;
    newnode=(struct myList *)malloc(sizeof(struct myList));
    newnode->prev=NULL;
    newnode->next=NULL;
}

struct myList *insertbefore()
{
    int number;
    searchptr=head;
    printf("enter the number before whom u want to insert:\n");
    scanf("%d",&number);
    
    while(searchptr->next!=NULL)
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
        printf("number not found pls enter correctly\n");
    }
    else if(searchptr==head)
    {
        createnewnode();
        newnode->next=searchptr;
        searchptr->prev=newnode;
        head=newnode;
        printf("enter the number:\n");
        scanf("%d",&newnode->num);
    }
    else if(searchptr==tail)
    {
        createnewnode();
        before=searchptr->prev;
        before->next=newnode;
        newnode->prev=before;
        newnode->next=tail;
        tail->prev=newnode;
        printf("enter the number:\n");
        scanf("%d",&newnode->num);
    }
    else
    {
        createnewnode();
        before=searchptr->prev;
        before->next=newnode;
        newnode->prev=before;
        newnode->next=searchptr;
        searchptr->prev=newnode;
        printf("enter the number:\n");
        scanf("%d",&newnode->num);
    }
    
}

struct myList *insertafter()
{
    searchptr=head;
    int number;
    printf("enter the number after whom u want to insert:\n");
    scanf("%d",&number);
    
    while(searchptr->next!=NULL)
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
        printf("number not found pls enter correctly\n");
    }
    
    else if(searchptr==head && searchptr->next==NULL)
    {
        createnewnode();
        searchptr->next=newnode;
        newnode->prev=searchptr;
        tail=newnode;
        printf("enter the number:\n");
        scanf("%d",&newnode->num);
    }
    else if(searchptr==head && searchptr->next!=NULL)
    {
        createnewnode();
        after=searchptr->next;
        searchptr->next=newnode;
        newnode->prev=searchptr;
        newnode->next=after;
        after->prev=newnode;
        printf("enter the number:\n");
        scanf("%d",&newnode->num);
    }
    else if(searchptr==tail)
    {
        createnewnode();
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
        printf("enter the number:\n");
        scanf("%d",&newnode->num);
    }
    else
    {
        createnewnode();
        after=searchptr->next;
        searchptr->next=newnode;
        newnode->prev=searchptr;
        newnode->next=after;
        after->prev=newnode;
        printf("enter the number:\n");
        scanf("%d",&newnode->num);
    }
}

struct myList *deletealternatenode()
{
    if(head==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        searchptr=head;
        if(searchptr->next==NULL && head==tail)
        {
            printf("No alternate node to delete\n");
        }
        else
        {
            while(searchptr->next!=NULL)
            {
            after=searchptr->next;
            if(after->next==NULL)
            {
                p1=after;
                tail=after->prev;
                head->next=NULL;
                free(p1);
            }
            else
            {
                p1=after;
                before=after->prev;
                after1=after->next;
                before->next=after1;
                after1->prev=before;
                searchptr=after1;
                free(p1);
            }
            }
        }
    }
}


struct myList *insert()
{
    if(head==NULL)
    {
        createnewnode();
        head=tail=newnode;
        printf("very first to enroll\n");
        printf("enter the number:\n");
        scanf("%d",&newnode->num);
    }
    else
    {
        int x;
        printf("enter 0 if u want to insert before any node or 1 if u want to insert after any node:\n");
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

struct myList *display()
{
    if(head==NULL)
    {
        printf("list is empty:\n");
    }
    else
    {
        searchptr=head;
        printf("the contents of the list are:\n");
        while(searchptr!=NULL)
        {
            printf("%d\t",searchptr->num);
            searchptr=searchptr->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    head=tail=p1=p=searchptr=newnode=after=before=after1=NULL;
    while(1)
    {
        printf("enter the choice:\n");
        printf("1:insert\n 2:deletealternatenode\n 3:display\n 4:exit\n");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
            insert();
            break;
            
            case 2:
            deletealternatenode();
            break;
            
            case 3:
            display();
            break;
            
            default:
            exit(0);
            break;
        }
    }

    return 0;
}