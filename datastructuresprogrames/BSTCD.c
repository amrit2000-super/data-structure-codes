#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct BST
{
    int num;
     struct BST *left;
     struct BST *right;
}BST;

BST *createTree(int value,BST *root)
{
    if(root==NULL)
    {
        BST *node=(BST *)malloc(sizeof(BST));
        node->left=NULL;
        node->right=NULL;
        node->num=value;
        return node;
    }
    
    else
    {
     if(value<root->num)
    {
        root->left=createTree(value,root->left);
    }
    
    else if(value>root->num)
    {
        root->right=createTree(value,root->right);
    }
    
    else
    {
        printf("No duplicates\n");
    }
    return root;
    }
}

BST *Inorder(BST *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    
    Inorder(root->left);
    printf("%d\t",root->num);
    Inorder(root->right);
}

BST *Postorder(BST *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    
    Postorder(root->left);
    Postorder(root->right);
    printf("%d\t",root->num);
}

BST *Preorder(BST *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    
    printf("%d\t",root->num);
    Preorder(root->left);
    Preorder(root->right);
}

void main()
{
    int value,i,nodes;
    BST *root=NULL;
    printf("enter the no of nodes:");
    scanf("%d",&nodes);
    printf("\n");
    for(i=0;i<nodes;i++)
    {
        printf("enter the value:");
        scanf("%d",&value);
        root=createTree(value,root);
    }
    printf("inorder traversal:");
    Inorder(root);
    printf("\n");
    printf("postorder traversal:");
    Postorder(root);
    printf("\n");
    printf("preorder traversal:");
    Preorder(root);
    printf("\n");
}
