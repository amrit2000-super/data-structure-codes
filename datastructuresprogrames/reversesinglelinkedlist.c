#include <stdio.h>
#include <stdlib.h>

 struct SLL
{
    int num;
    struct SLL *next;
}*head,*tail,*p,*p1,*searchptr,*newnode,*before,*tail1;

struct SLL *createnewnode()
{
   struct  SLL *root=( struct SLL *)malloc(sizeof( struct SLL));
    root->next=NULL;
    return root;
}

struct SLL *insertbefore()
{
    int number;
    searchptr=head;
    printf("enter the number before whom you want to insert:\n");
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
        before=head;
        printf("you ate inserting before the tail node\n");

        while(before->next!=tail)
        {
            before=before->next;
        }

        newnode=createnewnode();
        before->next=newnode;
        newnode->next=tail;
        printf("enter the number you want to insert:\n");
        scanf("%d",&newnode->num);
    }

    else
    {
        before=head;
        printf("you ate inserting somewhere\n");

        while(before->next!=searchptr)
        {
            before=before->next;
        }

        newnode=createnewnode();
        before->next=newnode;
        newnode->next=searchptr;
        printf("enter the number you want to insert:\n");
        scanf("%d",&newnode->num);
    }
}

    struct SLL *insertafter()
    {
        int number;
    searchptr=head;
    printf("enter the number after whom you want to insert:\n");
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
        printf("you are inserting after the head node\n");
        newnode=createnewnode();
        searchptr->next=newnode;
        tail=newnode;
        printf("enter the number you want to insert:\n");
        scanf("%d",&newnode->num);
    }
    else if(searchptr==head && head!=tail)
    {
        printf("you are inserting after the head node\n");
        newnode=createnewnode();
        newnode->next=searchptr->next;
        searchptr->next=newnode;
        printf("enter the number you want to insert:\n");
        scanf("%d",&newnode->num);
    }

    else if(searchptr==tail)
    {
        printf("you ate inserting after the tail node\n");
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

    struct SLL *insert()
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
            printf("enter 0 if yyou want to insert before a particular node or 1 if you want to insert after a particular node:\n");
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

    struct SLL *delete()
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

            if(searchptr==head && head==tail)
            {
                printf("this is the last node\n");
                p=head;
                head=tail=NULL;
                free(p);
            }

            else if(searchptr==head && head!=tail)
            {
                printf("deleting head node\n");
                p=head;
                head=head->next;
                free(p);
            }

            else if(searchptr==tail)
            {
                printf("deleting tail node\n");
                before=head;
                while(before->next!=tail)
                {
                    before=before->next;
                }
                p=tail;
                tail=before;
                tail->next=NULL;
                free(p);
            }

            else
            {
                before=head;
                while(before->next!=searchptr)
                {
                    before=before->next;
                }
                p=searchptr;
                before->next=searchptr->next;
                free(p);
            }
        }
    }

    struct SLL *display()
    {
        if(head==NULL)
        {
            printf("list is empty\n");
        }

        else
        {
            p=head;
            printf("the contents of the list not in reverse order are:\n");
            while(p!=NULL)
            {
                printf("%d\t",p->num);
                p=p->next;
            }
            printf("\n");

            p1=head;
            before=head;
            tail1=tail;
            printf("the contents of the list in reverse order are:\n");
            while(p1!=NULL)
            {
                before=head;
                if(before==tail1)
                {
                    printf("%d\t",tail1->num);
                }
                else
                {
                    printf("%d\t",tail1->num);
                    while(before->next!=tail1)
                    {
                        before=before->next;
                    }
                    tail1=before;
                }
                p1=p1->next;
            }
            printf("\n");
        }
    }

    void main()
    {
        int choice;
        head,tail,p,p1,searchptr,newnode,before,tail1=NULL;
        while(1)
        {
            printf("enter the choice:\n");
            printf("1:insert\n 2:delete\n 3:display\n 4:exit\n");
            scanf("%d",&choice);

            switch (choice)
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
