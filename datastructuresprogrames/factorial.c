#include <stdio.h>

int fact(int n)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}

void main()
{
    int n,x;
    printf("enter the number\n");
    scanf("%d",&n);
    x=fact(n);
    printf("the factorial of %d is %d",n,x);
}
