#include <stdio.h>
#include <stdlib.h>

struct Tree
{
    int num;
    struct Tree *left;
    struct Tree *right;
};

struct Tree *createnewnode(struct Tree *root)
{
    int n;
    printf("enter the number\n");
    scanf("%d",&n);
    if(n==-1)
    {
        return NULL;
    }
    else
    {
        root=(struct Tree *)malloc(sizeof(struct Tree));
        root->left=NULL;
        root->right=NULL;
        root->num=n;
        return root;
    }
}

struct Tree *createTree(struct Tree *root)
{
    root=createnewnode(root);
    if(root==NULL)
    {
        return NULL;
    }
    root->left=createTree(root->left);
    root->right=createTree(root->right);
    return root;
}

struct Tree *Preorder(struct Tree *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    printf("%d",root->num);
    Preorder(root->left);
    Preorder(root->right);
}

struct Tree *Inorder(struct Tree *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    Inorder(root->left);
    printf("%d",root->num);
    Inorder(root->right);
}

struct Tree *Postorder(struct Tree *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    Postorder(root->left);
    Postorder(root->right);
    printf("%d",root->num);
}

int main()
{
    struct Tree *root=NULL;
    root=createTree(root);
    printf("preorder:");
    Preorder(root);
    printf("\n");
    printf("inorder:");
    Inorder(root);
    printf("\n");
    printf("postorder:");
    Postorder(root);
    printf("\n");

    return 0;
}