// Program to simulate the working for a Linked List BY Vinu J Isaac
  
#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <conio.h>
//#include <alloc.h>
  
struct node{
int info;
struct node *link;
};
  
typedef struct node N;
  
N *getnode()
{
  
    N *p;
    p=(N *) malloc(sizeof(N));
    if(p==NULL)
    {
  
        printf("memory not available!");
        exit(0);
    }
    //p->link=NULL;                 //comment this line since calling function already takes care of this
    return p;
}
  
N *insert_front(int item,N *first)
{
  
    N *temp;
    temp=getnode();
    temp->info=item;
    temp->link=NULL;
  
    temp->link=first;
    first=temp;
    return first;
}
  
N *insert_rear(int item,N *first)
{
  
    N *temp;
    N *prev=NULL;
    N *cur=first;
    temp=getnode();
    temp->info=item;
    temp->link=NULL;
    
    if(first==NULL) return temp;           //added this line if no nodes present
  
    while(cur!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
  
    prev->link=temp;
    return first;
}
  
N *insert_before(int key,int item,N *first)
{
  
    N *temp;
    N *prev=NULL;
    N *cur=first;
    temp=getnode();
    temp->info=item;
    temp->link=NULL;
    
    if(first==NULL) return temp;         //If no nodes present added must return only node
  
    while(cur->link!=NULL)
    {
  
        if(cur->info==key) break;
        prev=cur;
        cur=cur->link;
    }
  
    if(cur->info!=key)
    {
  
        printf("Invalid");
        return first;
    }
  
    prev->link=temp;
    temp->link=cur;
    return first;
  
}
  
N *insert_pos(int pos,int item,N *first)
{
  
    N *temp;
    N *cur=first;
    N *prev=NULL;
    int count=1;
  
    temp=getnode();
    temp->info=item;
    temp->link=NULL;
  
    while(cur->link!=NULL)
    {
        if(count==pos) break;
        prev=cur;
        cur=cur->link;
        count++;
    }
  
    if(count!=pos)
    {
  
        printf("Invalid Position");
        return NULL;
    }
  
    prev->link=temp;
    temp->link=cur;
    return first;
}
  
void display(N *first)
{
    N *cur=first;
  
    if(first==NULL)
    {
    printf("The List is empty");
    return;
    }
  
    printf("The contents of list is: \n \t");
    while(cur!=NULL)							//cant give cur->link!=NULL coz if no nodes are present obviosuly first node link is null loop fails .
    {
    printf("%d==>",cur->info);
    cur=cur->link;
    }
}
  
void main()
{
  
    N *first;
    int ch,item,pos,key;
    //first=getnode();        //takes garbage coz of this first time dont give.
//  clrscr();
    first=NULL;               //Uncomment this coz everything blank beginning. 
  
    while(1)
    {
  
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at end");
        printf("\n3. Insert before element");
        printf("\n4. Insert at position");
        printf("\n Please enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
  
            case 1: printf("\nEnter the element to be inserted");
                scanf("%d",&item);
                first=insert_front(item,first);//break;
                display(first);break;
  
            case 2: printf("\nEnter the element to be inserted");
                scanf("%d",&item);
                first=insert_rear(item,first);
                display(first);break;
  
            case 3: printf("\nEnter the element to be inserted");
                scanf("%d",&item);
                printf("\nEnter the element before which we need to insert");
                scanf("%d",&key);
                first=insert_before(key,item,first);
                display(first);break;
  
            case 4: printf("\nEnter the element to be inserted");
  
                scanf("%d",&item);
                printf("\nEnter the position to insert");
                scanf("%d",&pos);
                first=insert_pos(pos,item,first);
                display(first);break;
  
  
            case 5: exit(0);break;
  
            //case 6: display(first);
  
        }
    }
    getch();
} 
