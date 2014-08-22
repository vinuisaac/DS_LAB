//Program to simulate the working of a Double Ended Queue BY Vinu J Isaac

#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <conio.h>
#define qz 5
int f,r,ch,item,q[20];

void main()
{
    f=0;r=-1;
    for(;;)
    {
    printf("\n1.Insert Rear");
    printf("\n2.Insert Front");
    printf("\n3.Delete Front");
    printf("\n4.Delete Rear");
    printf("\n5.Display");
    printf("\nEnter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("\nenter the element");
                scanf("%d",&item);
                insert_rear();
                break;
        case 2: printf("\nenter the element");
                scanf("%d",&item);
                insert_front();
                break;
        case 3: delete_front();
                break;
        case 4: delete_rear();
                break;
        case 5: display();
                break;

    }

    }

}

void insert_rear()
{
    if(r==qz-1)
    {
        printf("Overflow");
        exit(0);
    }

    r++;
    q[r]=item;
    printf("Element inserted %d",q[r]);
    return;
}

void insert_front()
{
    if(f==0&&r==-1)
    {
        r++;
        q[r]=item;
        printf("Item inserted %d",q[r]);
        return;
    }

    if(f!=0)
    {
        q[--f]=item;
        printf("Item inserted %d",q[f]);
        return;
    }

    printf("Insertion not possible");
}

void delete_front()
{

    if(f>r)
    {
        printf("Underflow");return;
    }
    printf("Deleted element is %d",q[f++]);
    if(f>r)
       {
         f=0;r=-1;
       }
    return;
}

void delete_rear()
{

    if(f>r)
    {
        printf("Underflow");return;
    }
    printf("Deleted element is %d",q[r--]);
    if(f>r)
       {
         f=0;r=-1;
       }
    return;
}

void display()
{
    int i,f1;
    if(f==0&&r==-1)
    {
        printf("Empty List");
        return;
    }

    printf("contents of the list \n \t");
    for(i=f;i<=r;i++)
    {
        printf("%d=>",q[i]);
    }
    return;
}
