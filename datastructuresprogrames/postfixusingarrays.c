#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int top=-1;

void push(char stack[],char symbol)
{
    stack[++top]=symbol;
}

char pop(char stack[])
{
    char item_deleted;
    item_deleted=stack[top];
    top--;
    return item_deleted;
}

int evaluate(char stack[],char symbol)
{
    int op1,op2;
    op1=pop(stack)-48;
    op2=pop(stack)-48;

    switch(symbol)
    {
        case '+':
        return op1+op2;
        break;

        case '-':
        return op1-op2;
        break;

        case '*':
        case '$':
        return op1*op2;
        break;

        case '/':
        return op2/op1;
        break;
    }
}

void main()
{
    char postfix[80],symbol;
    char stack[80];
    int i,res;
    printf("enter the valid postfix expression:\n");
    scanf("%s",postfix);

    for(i=0;postfix[i]!='\0';i++)
    {
        symbol=postfix[i];
        if(isdigit(symbol))
        {
            push(stack,symbol);
        }

        else
        {
           res= evaluate(stack,symbol);
           push(stack,res+48);
        }
    }
    printf("%c",stack[top]);
}