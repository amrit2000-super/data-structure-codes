#include <stdio.h>
#include <stdlib.h>

typedef struct OLL
{
    int num;
    struct OLL *next;
}OLL;

OLL *head,*tail,*before,*newnode,*p;

OLL *createnewnode()
{
    OLL *node=(OLL *)malloc(sizeof(OLL));
     node->next=NULL;
    return node;
}

OLL *createTree()
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
        newnode=createnewnode();
        printf("enter the number you want to insert:\n");
        scanf("%d",&newnode->num);
        if((newnode->num)<(head->num))
        {
            newnode->next=head;
            head=newnode;
        }
        else
        {
            p=head;
            while(p!=NULL && ((newnode->num)>(p->num)))
            {
                before=p;
                p=p->next;
            }
            if(p==NULL)
            {
                before->next=newnode;
                tail=newnode;
            }
            else
            {
                before->next=newnode;
                newnode->next=p;
            }
        }
    }
}

OLL *display()
{
    p=head;
    printf("the contents of the list are:\n");
    while(p!=NULL)
    {
        printf("%d\t",p->num);
        p=p->next;
    }
    printf("\n");
}

void main()
{
    head,tail,before,newnode,p=NULL;
    int choice;
    while(1)
    {
        printf("enter the choice:\n");
        printf("1:createTree\n 2:display\n 3:exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            createTree();
            break;

            case 2:
            display();
            break;

            default:
            exit(0);
            break;
        }
    }
}
