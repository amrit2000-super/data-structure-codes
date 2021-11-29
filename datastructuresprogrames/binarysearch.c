#include <stdio.h>
#include <stdlib.h>
#define N 6

int key;
int s[N];
int mid;

int find(int low,int high)
{
    if(low>high)
    {
        return 0;
    }
    else
    {
        if(low<=high)
        {
            mid=(low+high)/2;
            if(key==s[mid])
            {
                return 1;
            }
            else if(key>s[mid])
            {
                low=mid+1;
               return find(low,high);
            }
            else
            {
                high=mid-1;
               return find(low,high);
            }
            
        }
    }
}

void main()
{
    int low,high,i,x;
    low=0;
    high=N-1;
    printf("enter the elements of the array in increasing order\n");
    for(i=0;i<N;i++)
    {
        scanf("%d",&s[i]);
    }
    printf("enter the key element to be searched\n");
    scanf("%d",&key);
    x=find(low,high);
    if(x==1)
    {
        printf("element is found at %d\n",mid+1);
    }
    else
    {
        printf("element is not found\n");
    }
}
