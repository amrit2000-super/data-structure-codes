#include <stdio.h>
#include <stdlib.h>

int gcd(int x,int y)
{
    int rem;
    rem=x%y;
    x=y;
    y=rem;
    if(y==0)
    {
        return x;
    }
    else
    {
        return gcd(x,y);
    }
}

int main()
{
    int x,y,x1;
    printf("enter the values of x and y:\n");
    scanf("%d %d",&x,&y);
    x1=gcd(x,y);
    printf("gcd of %d and %d is %d",x,y,x1);
    return 0;
}
