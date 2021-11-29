int x;

struct detail
{
    int rollno;
    struct detail *prev;
    struct detail *next;
}*after,*before,*searchptr,*p1,*pointer,*p,*newnode,*tail,*ptr1,*head;

struct detail * createnewnode()
{
    p=head;
    newnode=(struct detail *)malloc(sizeof(struct detail));
    newnode->prev=NULL;
    newnode->next=NULL;
}
struct detail * display()
{
    ptr1=head;
    if(head==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
       printf("the list before reversal is :\n");
    while(ptr1!=NULL)
    {
        printf("%d\t",ptr1->rollno);
        ptr1=ptr1->next;
    }
        printf("\n");
        printf("list after reversal is :\n");
        ptr1=tail;
        while(ptr1!=NULL)
    {
        printf("%d\t",ptr1->rollno);
        ptr1=ptr1->prev;
    }
        printf("\n");
    }
}
void insertbefore()
{
    int rollno,flg;
    searchptr=pointer;
    printf("enter the rollno before whom you want to insert\n");
        scanf("%d",&rollno);
        while(searchptr->next!=NULL)
        {
            if(searchptr->rollno==rollno)
            {
                flg=1;
                break;
            }
            else
            {
                searchptr=searchptr->next;
            }
        }
        if(searchptr->rollno!=rollno)
    {
        printf("roll no of the student is not found\n");
    }
    else
    {
    if(searchptr==head)
    {
        printf("you are inserting before head node\n");
        createnewnode();
        newnode->next=p;
        p->prev=newnode;
       searchptr=pointer= head=newnode;
        printf("enter the roll no of the student:\n");
        scanf("%d",&newnode->rollno);
    }
    
    else if(searchptr==tail)
    {
        printf("you are inserting before tail node\n");
        createnewnode();
        before=tail->prev;
        before->next=newnode;
        newnode->prev=before;
        newnode->next=tail;
        tail->prev=newnode;
        printf("enter the roll no of the student:\n");
        scanf("%d",&newnode->rollno);
    }
    else
    {
        printf("you are inserting somewhere\n");
        createnewnode();
        before=searchptr->prev;
        before->next=newnode;
        newnode->prev=before;
        newnode->next=searchptr;
        searchptr->prev=newnode;
        printf("enter the roll no of the student:\n");
        scanf("%d",&newnode->rollno);
    }
}
}

struct detail *insertafter()
{
    int rollno,flg;
    searchptr=pointer;
    printf("enter the rollno after whom you want to insert\n");
        scanf("%d",&rollno);
        while(searchptr->next!=NULL)
        {
            if(searchptr->rollno==rollno)
            {
                flg=1;
                break;
            }
            else
            {
                searchptr=searchptr->next;
            }
        }
        if(searchptr->rollno!=rollno)
    {
        printf("roll no of the student is not found\n");
    }
    else
    {
    if(searchptr==head)
    {
        printf("you are inserting after head node\n");
        createnewnode();
        if(head->next==NULL)
        {
            head->next=newnode;
            newnode->prev=head;
            while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    tail=newnode;
        printf("enter the roll no of the student:\n");
        scanf("%d",&newnode->rollno);
    }
        else
        {
            printf("you are inserting after head node\n");
        createnewnode();
        after=head->next;
        head->next=newnode;
        newnode->prev=head;
        newnode->next=after;
        after->prev=newnode;
        printf("enter the roll no of the student:\n");
        scanf("%d",&newnode->rollno);
        }
    }
    
    else if(searchptr==tail)
    {
        printf("you are inserting after tail node\n");
        createnewnode();
        tail->next=newnode;
        newnode->prev=tail;
        tail=tail->next;
        printf("enter the roll no of the student:\n");
        scanf("%d",&newnode->rollno);
    }
    else
    {
        printf("you are inserting somewhere\n");
        createnewnode();
        after=searchptr->next;
        searchptr->next=newnode;
        newnode->prev=searchptr;
        newnode->next=after;
        after->prev=newnode;
    }
    } 
}
struct detail *delete()
{
    int rollno,flg;
    printf("enter the rollno you want to delete\n");
    scanf("%d",&rollno);
    searchptr=pointer;
    while(searchptr->next!=NULL)
        {
            if(searchptr->rollno==rollno)
            {
                flg=1;
                break;
            }
            else
            {
                searchptr=searchptr->next;
            }
        }
        if(searchptr->rollno!=rollno)
    {
        printf("roll no of the student is not found\n");
    }
    else
    {
        if(head==NULL)
        {
            printf("list is empty\n");
        }
    else if(searchptr==head)
    {
        if(head->next==NULL)
        {
            printf("deleting head node\n");
            p1=head;
            head=NULL;
            free(p1);
        }
        else
{
        printf("deleting head node\n");
        p1=head;
        head=head->next;
        free(p1);
    }
}
    else if(head==tail && head!=NULL)
    {
        printf("last node left\n");
        p1=head;
        head=NULL;
        free(p1);
    }
    else if(searchptr==tail)
    {
        printf("deleting tail node\n");
        before=tail->prev;
        p1=tail;
        before->next=NULL;
        tail=before;
        free(p1);
    }
    
    else
    {
        printf("deleting somewhere\n");
        p1=searchptr;
        before=searchptr->prev;
        after=searchptr->next;
        before->next=after;
        after->prev=before;
        free(p1);
    }
}
}

struct detail * insert()
{
    if(head==NULL)
    {
        createnewnode();
       pointer= head=tail=p=p1=newnode;
        printf("very first to enroll\n");
        printf("enter the roll no of the student:\n");
        scanf("%d",&newnode->rollno);
    }
    
    else
    {
     printf("enter 0 if you want to insert before or 1 if you ant to insert after a particular roll no:\n");
     scanf("%d",&x);
    
    if(x==0)
    {
        insertbefore();
    }
    else
    {
        insertafter();
    }
    }
}