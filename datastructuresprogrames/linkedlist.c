#include <stdio.h>
#include <stdlib.h>

struct detail
{
    char name[30];
    int age;
    struct detail *link;
}*p,*p1;


int main()
{
    int i;
    p=NULL;
    p=(struct detail *)malloc(5*sizeof(struct detail));
    p1=p;
    for(i=0;i<2;i++)
    {
        printf("enter the name\n");
        scanf("%s",p->name);
        printf("enter your age\n");
        scanf("%d",&p->age);
        p->link=p+1;
        p=p->link;
    }
    for(i=0;i<2;i++)
    {
        p->link=p1;
        printf("your name is %s\n",p1->name);
        printf("your age is %d\n",p1->age);
        p1++;
    }
    return 0;
}
