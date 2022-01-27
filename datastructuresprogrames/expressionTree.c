#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 9

int top=-1;
int res;

struct eT
{
    char n;
    struct eT *left;
    struct eT *right;
};

struct eT *s[SIZE];

struct eT *createnewnode(char symbol)
{
    struct eT *root=(struct eT *)malloc(sizeof(struct eT));
    root->left=NULL;
    root->right=NULL;
    root->n=symbol;
    return root;
}

struct eT *push(struct eT *root)
{
    s[++top]=root;
}

struct eT *pop()
{
    struct eT *node=s[top];
    top--;
    return node;
}

struct eT *display(struct eT *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    display(root->left);
    printf("%c",root->n);
    display(root->right);
}

int evaluate(struct eT *root)
{
    if(isdigit(root->n))
    {
        return ((root->n)-48);
    }
    if(root->n=='+')
    {
        return (evaluate(root->left)+evaluate(root->right));
    }
    else if(root->n=='-')
    {
       return (evaluate(root->left)-evaluate(root->right));
    }
        
    else if(root->n=='*')
    {
        return (evaluate(root->left)*evaluate(root->right));
    }
        
    else
    {
        return evaluate(root->left)/evaluate(root->right);
    }
}


int main()
{
    char symbol,postfix[SIZE];
    struct eT *node=NULL;
    int i;
    printf("enter the valid postfix expression:\n");
    scanf("%s",postfix);
    for(i=0;postfix[i]!='\0';i++)
    {
        symbol=postfix[i];
        if(isdigit(symbol))
        {
            node=createnewnode(symbol);
            push(node);
        }
        else
        {
            node=createnewnode(symbol);
            struct eT *op1=pop();
            struct eT *op2=pop();
            node->left=op2;
            node->right=op1;
            push(node);
        }
    }
    display(node);
    printf("\n");
    res=evaluate(node);
    printf("the result is %d",res);
    return 0;
}