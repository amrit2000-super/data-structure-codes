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
    struct mydetail p;
    printf("enter your name:\n");
    scanf("%s",p.name);
    printf("enter your age:\n");
    scanf("%d",&p.age);
    printf("your details are:\n");
    printf("your name is %s",p.name);
    printf("\n");
    printf("your age is %d",p.age);
    return 0;
}
