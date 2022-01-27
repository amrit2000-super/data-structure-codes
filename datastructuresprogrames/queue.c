#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int rear;
int front;
int s[SIZE];
int item;
int k=0;
int k1;


void insert()
{
    if(rear == SIZE-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        printf("enter the item to be inserted:\n");
        scanf("%d",&item);
        s[++rear]=item;
        k++;
    }
}
int pop()
{
    int item_deleted;
    if(rear ==-1)
    {
        printf("Queue is empty\n");
    }
    else{
        item_deleted=s[++front];
        rear--;
        return item_deleted;
    }
}

void display()
{
    int i;
    if(rear ==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("contents of queue are :\n");
        if(front==-1)
        {
        for(i=front+1;i<=rear;i++)
        {
            printf("%d\t",s[i]);
        }
        printf("\n");
        }
        else
        {
            for(i=front;i<k-1;i++)
            {
                printf("%d\t",s[i+1]);
            }
            printf("\n");
            }
        }
}

void main()
{
    int choice,item_deleted,i;
    i=0;
    k1=0;
    front=rear=-1;
    for(;;)
    {
    printf("enter the choice:\n");
    printf("1:insert\n 2:pop\n 3:display\n 4:exit\n");
    scanf("%d",&choice);
    
        switch(choice)
    {
        case 1:
        insert();
        break;
        
        case 2:
        item_deleted=pop();
        if(k1>=0 && rear>=-1)
        {
        printf("%d is removed at %d\n",item_deleted,k1);
        k1++;
        }
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
