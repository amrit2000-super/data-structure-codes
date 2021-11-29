#include <stdio.h>
#include <stdlib.h>
#include "t.h"

int main()
{
    int choice;
    after=NULL;
    before=NULL;
    searchptr=NULL;
    p1=NULL;
    pointer=NULL;NULL;
    p=NULL;
    newnode=NULL;
    tail=NULL;
    head=NULL;
    for(;;)
    {
        printf("enter choice:\n");
        printf("1:insert\n 2:delete\n 3:display\n 4:exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            insert();
            break;

            case 2:
            delete();
            break;

            case 3:
            display();
            break;

            default:
            exit(0);
            break;
        }

    }
}
