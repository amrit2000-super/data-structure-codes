#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Tree
{
    int num;
     struct Tree *left;
     struct Tree *right;
};

struct Tree *createbintree(int value,struct Tree *root)
{
    if(root==NULL)
    {
    struct Tree *root=(struct Tree *)malloc(sizeof(struct Tree));
    root->left=NULL;
    root->right=NULL;
    root->num=value;
    return root;
    }
    else
    {
        if(value<root->num)
        {
            root->left=createbintree(value,root->left);
        }
        else if(value>root->num)
        {
            root->right=createbintree(value,root->right);
        }
        else
        {
            printf("no duplicates\n");
        }
    }
    
}

struct Tree *findelement(int n,struct Tree *root)
{
    if(root->num==n)
    {
        return root;
    }
    else
    {
        if(n<root->num)
        {
            root->left=findelement(n,root->left);
        }
        else
        {
            root->right=findelement(n,root->right);
        }
    }
}

int main()
{
    int no_of_nodes,i,value;
    printf("enter the no of nodes:\n");
    scanf("%d",&no_of_nodes);
    struct Tree *root=NULL;
    struct Tree *node=NULL;
    for(i=0;i<no_of_nodes;i++)
    {
        printf("enter the value:");
        scanf("%d",&value);
        root=createbintree(value,root);
    }
    printf("enter value to be found:\n");
    scanf("%d",&value);
    node=findelement(value,root);
    if(node->num==value)
    {
        printf("element found\n");
    }
    else
    {
        printf("element not found\n");
    }
    
    return 0;
}
