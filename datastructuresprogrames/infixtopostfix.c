#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int top=-1;

void push(char symbol,char s[])
{
    s[++top]=symbol;
}

char pop(char s[])
{
    char item_deleted;
    item_deleted=s[top];
    top--;
    return item_deleted;
}

int priority(char symbol)
{
    switch(symbol)
    {
        case '#':
        return 0;
        break;

        case '(':
        return 1;
        break;

        case '+':
        case '-':
        return 2;
        break;

        case '*':
        case '/':
        return 3;
        break;

        case '^':
        case '$':
        return 4;
        break;
    }
}

void main()
{
    int i,j;
    char infix[80],postfix[80],s[80];
    char symbol,symbol1;
    top=-1;
    j=0;

    push('#',s);
    printf("enter the valid infix expression:\n");
    scanf("%s",infix);

    for(i=0;infix[i]!='\0';i++)
    {
        symbol=infix[i];
        if(symbol=='(')
        {
            push(symbol,s);
        }

        else if(symbol==')')
        {
            while(s[top]!='(')
            {
                postfix[j++]=pop(s);
            }
            symbol1=pop(s);
        }

        else if(isalnum(symbol))
        {
            postfix[j++]=symbol;
        }

        else
        {
            while(priority(s[top])>=priority(symbol))
            {
                postfix[j++]=pop(s);
            }
            push(symbol,s);
        }
    }

    while(s[top]!='#')
    {
        postfix[j++]=pop(s);
    }

    printf("the postfix expression is:%s\n",postfix);
}