#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int front=-1;
int rear=-1;

struct PQ
{
    int number;
    int priority;
};

struct PQ p[1000];

void enQueue(int number,int priority)
{
    int i,j,temp;
    if(front==SIZE-1)
    {
        printf("queue is full\n");
    }
    
    else
    {
        rear++;
        p[rear].number=number;
        p[rear].priority=priority;
        rear++;
        for(i=front+1;i<rear;i++)
        {
            for(j=front+1;j<rear-i-1;j++)
            {
                if(p[j].priority<p[j+1].priority)
                {
                    temp=p[j].priority;
                    p[j].priority=p[j+1].priority;
                    p[j+1].priority=temp;
                    
                    temp=p[j].number;
                    p[j].number=p[j+1].number;
                    p[j+1].number=temp;
                }
            }
        }
        rear--;
    }
}

void deQueue()
{
    if((front==-1 && rear==-1) || (front==rear))
    {
        printf("Queue is empty\n");
    }
    
    else
    {
        front++;
        printf("value %d and priority %d is deleted",p[front].number,p[front].priority);
    }
}

void display()
{
    int i;
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty\n");
    }
    
    else
    {
        if(front==-1 && rear==SIZE-1)
        {
            printf("queue is full\n");
            printf("the contents of the queue are:");
            for(i=0;i<=rear;i++)
            {
                printf("number:%d\t",p[i].number);
                printf("priority:%d\t",p[i].priority);
            }
            printf("\n");
        }
        
        else
        {
            printf("the contents of the queue are:");
            for(i=front+1;i<=rear;i++)
            {
                printf("number:%d\t",p[i].number);
                printf("priority:%d\t",p[i].priority);
            }
            printf("\n");
        }
    }
}

void main()
{
    int choice,number,priority;
    while(1)
    {
        printf("enter the choice:\n");
        printf("1:insert\n 2:delete\n 3:display\n 4:exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("enter the number u want to insert\n");
            scanf("%d",&number);
            printf("enter the priority of the number you want to insert\n");
            scanf("%d",&priority);
            enQueue(number,priority);
            break;
            
            case 2:
            deQueue();
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
