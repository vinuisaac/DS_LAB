//Program to simulate the working for circular queue BY Vinu J Isaac
#include <stdio.h>
#include <stdlib.h>
#include <process.h>

# define qz 5
int ch,count,f,r,item,q[20];

void main()
{
    f=0,r=-1,count=0;
    for(;;)
    {

        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\nEnter Choice:");
        scanf("%d",&ch);

        switch(ch)
        {

            case 1: printf("\n enter the element");
                    scanf("%d",&item);
                    insert_rear();
                    break;
            case 2: delete_front();
                    break;
            case 3: display();
                    break;
        }
    }
}

void insert_rear()
{
    if(count==qz-1)
    {
        printf("overflow \n");
        exit;
    }
    r=(r+1) % qz;
    q[r]=item;
    count++;
    printf("inserted %d",q[r]);
}

void delete_front()
{

        if(count==0)
        {
            printf("Empty List \n");
        }
        printf("deleted %d",q[f]);
        f=(f+1) % qz;
        count--;
}

void display()
{
        int i,f1=f;
        if(count==0)
        {

            printf("Empty List\n");
        }
        for(i=1;i<=count;i++)
        {
            printf("%d=>",q[f1]);
            f1=(f1+1) % qz;
        }
}
