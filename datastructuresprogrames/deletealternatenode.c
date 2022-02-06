#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
    int num;
    struct Tree *next;  
}Tree;

Tree *head,*tail,*before,*p,*p1,*newnode,*searchptr,*after;

Tree *createnewnode()
{
    Tree *node=(Tree *)malloc(sizeof(Tree));
    node->next=NULL;
    return node;
}

Tree *insertbefore()
{
    int number;
    searchptr=head;
    printf("enter the number before whom you want to insert\n");
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
        printf("number not found\n");
    }

    else if(searchptr==head)
    {
        printf("you are inserting before the head node\n");
        newnode=createnewnode();
        newnode->next=head;
        head=newnode;
        printf("enter the number you want to insert:\n");
        scanf("%d",&newnode->num);
    }

    else if(searchptr==tail)
    {
        printf("you are inserting before the tail node\n");
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
        printf("you are inserting somewhere:\n");
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

Tree *insertafter()
{
    int number;
    searchptr=head;
    printf("enter the number after whom you want to insert\n");
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
        printf("number not found\n");
    }

    else if(searchptr==head && head==tail)
    {
        printf("you are inserting after head node\n");
        newnode=createnewnode();
        searchptr->next=newnode;
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
        tail->next=newnode;
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

Tree *insert()
{
    if(head==NULL)
    {
        newnode=createnewnode();
        head=tail=newnode;
        printf("enter the number you want to insert:\n");
        scanf("%d",&newnode->num);
    }

    else
    {
        int x;
        printf("enter 0 if you want to insert before a particular node or 1 if you want to insert after a particular node:\n");
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

Tree *deletealternatenodes()
{
    if(head==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        p=head;
        while(p->next!=NULL)
        {
            before=p;
            after=p->next;
            if(after==tail)
            {
                p1=after;
                tail=before;
                before->next=NULL;
                p=before;
                free(p1);
            }
            else
            {
                p1=after;
                before->next=after->next;
                p=after;
            }
        }
    }
    printf("\n");
}

Tree *display()
{
    if(head==NULL)
    {
        printf("list is empty\n");
    }

    else
    {
        p1=head;
        printf("the contents of the list are:\n");
        while(p1!=NULL)
        {
            printf("%d\t",p1->num);
            p1=p1->next;
        }
    }
    printf("\n");
}

void main()
{
    int choice;
    head,tail,before,p,p1,newnode,searchptr,after=NULL;
    while(1)
    {
        printf("enter the choice:\n");
        printf("1:insert\n 2:deletealternatenodes\n 3:display\n 4:exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            insert();
            break;

            case 2:
            deletealternatenodes();
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
