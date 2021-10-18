#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct mydetail
{
    char name[100];
    int age;
};

int main()
{
    struct mydetail *ptr;
    ptr=(struct mydetail *)malloc(sizeof(struct mydetail));
    printf("enter your name:\n");
    scanf("%s",ptr->name);
    printf("enter your age:\n");
    scanf("%d",&ptr->age);
    printf("your details are:\n");
    printf("your name is %s",ptr->name);
    printf("\n");
    printf("your age is %d",ptr->age);
    return 0;
}
