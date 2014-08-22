//Program to show the working of a circular linked list BY Vinu J Isaac

#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#include<alloc.h>

struct node
{
	int info;
	struct node *link;
};
typedef struct node NODE;

NODE *getnode()
{
	NODE *p;
	p=(NODE *) malloc(sizeof(NODE));

	if(p==NULL)
	{
		printf("\n Memory not allocated");
		exit(0);
	}
	p->link=NULL;
	return p;
}

NODE *insert_front(int item, NODE *head)
{
	NODE *temp;
	temp=getnode();
	temp->info=item;

	temp->link=head->link;
	head->link=temp;
	head->info+=1;
	return head;
}

NODE *delete_item(int item,NODE *head)
{
	NODE *prev,*cur;
	if(head->link==head)
	{
		printf("\n list is empty");
		return NULL;
	}
	prev=head;
	cur=head->link;
	while(cur!=head)
	{
		if(item==cur->info)
		break;
		prev=cur;
		cur=cur->link;
	}
	if(cur==head)
	{
		printf("\n item not found");
		return head;
	}

	prev->link=cur->link;
	head->info-=1;
	free(cur);

	return head;
}

NODE *delete_front(NODE *head)
{
	NODE *cur=head->link;

	if(head->link==head)
	{
		printf("\n List is empty");
		return head;
	}

	head->link=cur->link;
	head->info-=1;
	free(cur);

	return head;
}

NODE *delete_rear(NODE *head)
{
	NODE *cur=head->link, *prev=head;
	if(head->link == head)
	{
		printf("\nList is empty\n");
		return head;
	}
	while(cur->link != head)
	{
		prev=cur;
		cur = cur->link;
	}
	prev->link = head;
	head->info -=1;
	free(cur);
	return head;
}

NODE *delete_position(int pos, NODE *head)
{
	NODE *prev, *cur;
	int count;
	if(head->link == head)
	{
		printf("\nList is empty\n");
		return head;
	}
	prev=head;
	cur=head->link;
	count=1;
	while(cur != head)
	{
		if(count==pos)
		break;
		prev=cur;
		cur=cur->link;
		count++;
	}
	prev->link = cur->link;
	free(cur);
	head->info -=1;
	return head;
}

NODE *delete_alternate(NODE *head)
{
	int i;
	if(head->link == head)
	{
		printf("\nList is empty\n");
		return head;
	}
	for(i=1;i<=head->info;i++)
	head = delete_position(i, head);

	return head;
}

void display(NODE *head)
{
	NODE *cur;
	if(head->link == head)
	{
		printf("\nList is empty\n");
		return;
	}
	printf("\nContents of the list is\n \t HEAD==>");
        //printf("\n");
	cur=head->link;
	while(cur != head)
	{
		printf("%d==>",cur->info);
		cur=cur->link;
	}
	printf("HEAD\n \t Total nodes = %d", head->info);
}
void main()
{
	//clrscr();
	NODE *head;
	int ch, item, pos;
        clrscr();
	head=getnode();
	head->info=0;
	head->link=head;
	while(1)
	{
		printf("\n1. Insert at Front");
		printf("\n2. Delete at Front");
		printf("\n3. Delete at Rear");
		printf("\n4. Delete a given element");
		printf("\n5. Delete every alternate element");
		printf("\n6. Exit");
		printf("\nEnter your choice :\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
			printf("\nEnter the item to be inserted:");
			scanf("%d", &item);
			head = insert_front(item, head);
			display(head);
			break;

			case 2:
			head = delete_front(head);
			display(head);
			break;

			case 3:
			head = delete_rear(head);
			display(head);
			break;

			case 4:
			printf("\nEnter the item to be deleted:");
			scanf("%d", &item);
			head = delete_item(item, head);
			display(head);
			break;

			case 5:
			head = delete_alternate(head);
			display(head);
			break;

			default: return;
		}
	}
}


