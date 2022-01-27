#include <stdio.h>
#include <stdlib.h>
int x;
int y;

void swap1(int a,int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
    printf("the values of a and b(local) after swapping are %d and %d respectively",a,b);
}
void swap2(int x,int y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
    printf("the values of x and y(global) after swapping are %d and %d respectively",x,y);
}

int main()
{
    int a,b;
    printf("enter the values of a and b(local) respectively\n");
    scanf("%d %d",&a,&b);
    printf("enter the values of x and y respectively(global)\n");
    scanf("%d %d",&x,&y);
    printf("the values of a and b(local) before swapping are %d and %d respectively",a,b);
    swap1(a,b);
    printf("\n");
    printf("the values of x and y(global) before swapping are %d and %d respectively",x,y);
    swap2(x,y);
    return 0;
}
