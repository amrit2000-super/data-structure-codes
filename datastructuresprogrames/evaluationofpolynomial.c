#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SIZE=0;
int SIZE1=0;
int SIZE2=0;

typedef struct Tree
{
    int num;
     struct Tree *next;
}Tree;

Tree *head,*tail,*newnode;

Tree *createnewnode()
{
    Tree *node=(Tree *)malloc(sizeof(Tree));
    node->next=NULL;
    return node;
}

void push()
{
    if(head==NULL)
    {
        newnode=createnewnode();
        head=tail=newnode;
        printf("enter the coefficient of x^%d\t",SIZE);
        scanf("%d",&newnode->num);
    }
    else
    {
        if(head==tail)
        {
            newnode=createnewnode();
            head->next=newnode;
            tail=newnode;
            printf("enter the coefficient of x^%d\t",SIZE);
            scanf("%d",&newnode->num);
        }
        else
        {
            newnode=createnewnode();
            tail->next=newnode;
            tail=newnode;
            printf("enter the coefficient of x^%d\t",SIZE);
            scanf("%d",&newnode->num);
        }
    }
    printf("\n");
}

void display()
{
    Tree *p=head;
    printf("the polynomial is:");
    while(p->next!=NULL)
    {
        printf("%dx^%d",p->num,SIZE1);
        printf("+");
        p=p->next;
        SIZE1--;
    }
    printf("%dx^%d",p->num,SIZE1);
    SIZE1--;
    printf("\n");
}
void evaluate()
{
     Tree *p1=head;
     int x,sum=0;
     printf("enter the value of x:\n");
     scanf("%d",&x);
     while(p1!=NULL)
     {
         sum=sum+((p1->num)*pow(x,SIZE2));
         SIZE2--;
          p1=p1->next;
     }
     printf("the value of polynomial at x=%d is %d",x,sum);
     printf("\n");
}

void main()
{
    head,tail,newnode=NULL;
    while(1)
    {
        int x=0;
        printf("enter the degree of the polynomial:\n");
        scanf("%d",&SIZE);
        SIZE1=SIZE2=SIZE;
        while(SIZE>-1)
        {
            push();
            SIZE--;
        }
        display();
        evaluate();
        printf("do you wish to exit,if yes enter 1\n");
        scanf("%d",&x);
        if(x==1)
        {
            exit(0);
        }
    }
}