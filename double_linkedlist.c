//Program to simulate the working for a Double Linked List BY Vinu J Isaac
//insert and delete front only, the rest is just same like other linked list. 
 

#include <stdio.h>
#include <stdlib.h>
#include <process.h>

struct node{
int info;
struct node *rlink;
struct node *llink;
};

typedef struct node N;

N *getnode()
{
   N *p;
   p=(N *) malloc(sizeof(N));
   if(p==NULL)
   {
       printf("\n Memory is not available");
       exit(0);
   }
   return p;
}

N *insert_front(int item,N *start)
{
    N *temp;
    temp=getnode();
    temp->info=item;
    temp->rlink=NULL;
    temp->llink=NULL;

    if(start==NULL)
    {
        start=temp;
        return start;
    }

    start->llink=temp;
    temp->rlink=start;
    start=temp;
    return start;
}

N *delete_front(N *start)
{
    N *temp;
    temp=start;

    if(start==NULL)
    {
        printf("List is empty");
        exit(0);
    }

    start=start->rlink;
    start->llink=NULL;
    free(temp);
    return start;
}

void display(N *start)
{
    N *temp;
    //temp=start;
    if(start==NULL)
    {
        printf("List is Empty");
        exit(0);
    }
    temp=start;
    printf("\nElements of the list:");
    while(temp!=NULL)
    {
        printf("%d=>",temp->info);
        temp=temp->rlink;
    }
}


void main()
{
    N *start=NULL;
    //start=getnode();

    int ch,item;
    for(;;)
    {
        printf("\n1. Insert Front");
        printf("\n2. Delete Front");
        printf("\n3. Delete Front");
        printf("\n4. Delete Rear");
        printf("\n Enter ur choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\n Enter the element to be inserted:");
                    scanf("%d",&item);
                    start=insert_front(item,start);
                    display(start);
                    break;
            case 2: start=delete_front(start);
                    display(start);
        }

    }
}
