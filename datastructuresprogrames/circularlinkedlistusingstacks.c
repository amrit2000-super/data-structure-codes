#include <stdio.h>
#include <stdlib.h>

int SIZE;
int l=0;

typedef struct CLL
{
    int num;
    struct CLL *next;
}CLL;

CLL *head,*tail,*before,*p,*p1,*newnode,*tail1;

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
        printf("stack is full\n");
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
        printf("stack is empty\n");
    }

    else
    {
        before=head;
        if(before==head && head==tail)
        {
            p=head;
            head=tail=NULL;
            free(p);
            l--;
        }
        
        else
        {
            before=head;
            while(before->next!=tail)
            {
                before=before->next;
            }

            p=tail;
            tail=before;
            tail->next=head;
            free(p);
            l--;
        }
    }
}

CLL *display()
{
    if(l==SIZE)
    {
        printf("stack is full\n");
        printf("the contents of the stack are:\n");
        p1=head;
        before=head;
        tail1=tail;
        while(p1->next!=head)
        {
            before=head;
            if(before==head && head==tail1)
            {
                 printf("%d\n",tail1->num);
            }
            else
            {
                while(before->next!=tail1)
                {
                    before=before->next;
                }
                printf("%d\n",tail1->num);
                tail1=before;
            }
            p1=p1->next;
        }
        printf("%d\n",tail1->num);
        printf("\n");
    }

    else if(l==0)
    {
        printf("stack is empty\n");
    }

    else
    {
        p1=head;
        tail1=tail;
        printf("the contents of the list are:\n");
         while(p1->next!=head)
        {
            before=head;
            if(before==head && head==tail1)
            {
                 printf("%d\n",tail1->num);
            }
            else
            {
                while(before->next!=tail1)
                {
                    before=before->next;
                }
                printf("%d\n",tail1->num);
                tail1=before;
            }
            p1=p1->next;
        }
        printf("%d\n",tail1->num);    
    }
    printf("\n");
}

void main()
{
    head,tail,before,p,p1,newnode,tail1=NULL;
    int choice;
    printf("enter the size of the stack:\n");
    scanf("%d",&SIZE);
    while(1)
    {
    printf("enter the choice\n");
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
