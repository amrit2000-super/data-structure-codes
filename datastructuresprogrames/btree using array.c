#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 10

char ch[SIZE];

struct Tree 
{
    char symbol;
    struct Tree *left;
    struct Tree *right;
};

struct Tree *createnewnode(char c[],int n)
{
    if(isspace(c[n]) && n<SIZE)
    {
        return NULL;
    }
    else if(n>=SIZE)
    {
        return NULL;
    }
    else
    {
        struct Tree *newnode=(struct Tree *)malloc(sizeof(struct Tree));
        newnode->left=NULL;
        newnode->right=NULL;
        newnode->symbol=c[n];
    }
}

struct Tree *createTree(struct Tree *root,char c[],int n)
{
    root=createnewnode(c,n);
    if(root==NULL)
    {
        return NULL;
    }
        root->left=createTree(root->left,c,2*n+1);
        root->right=createTree(root->right,c,2*n+2);
        return root;       
}

struct Btree *display(struct Tree *root)
{
    if(root=NULL)
    {
        return NULL;
    }
    else
    {
        printf("%c",root->symbol);
        display(root->left);
        display(root->right);
    }
}

void main()
{
    struct Tree *root=NULL;
    int i=0;
    printf("enter the array\n");
    gets(ch);
    root=createTree(root,ch,0);
    display(root);
}