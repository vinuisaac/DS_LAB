#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct Tree
{
int data;
struct Tree *left,*right;
}node;
node *get_node()
{	
node *temp=(node *)malloc(sizeof(node));
temp->left=temp->right=NULL;
return temp;
}
void insert(node *root, node *new_node)
{
if(new_node->data < root->data)
{
if(root->left==NULL)
root->left = new_node;
else
insert(root->left,new_node);
}
if(new_node->data > root->data)
{
if(root->right==NULL)
root->right=new_node;
else
insert(root->right,new_node);
}
}
void inorder(node *temp)
{
if(temp!=NULL)
{
inorder(temp->left);
printf("%5d",temp->data);
inorder(temp->right);
}
}
void preorder(node *temp)
{
if(temp!=NULL)
{
printf("%5d",temp->data);
preorder(temp->left);
preorder(temp->right);
}
}
void postorder(node *temp)
{
if(temp!=NULL)
{
postorder(temp->left);
postorder(temp->right);
printf("%5d",temp->data);
}
}
int main()
{
int choice;
char ans='N';
node *new_node,*tmp,*parent,*root=NULL;
clrscr();
do
{
printf("\n	Menu\n1.Create\n2.Traversals\n0.Exit\nEnter your choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1: do
{
new_node=get_node();
printf("Enter The Element: ");
scanf("%d",&new_node->data);
if(root==NULL)  
root=new_node;
else
insert(root,new_node);
printf("Want To enter More Elements?(y/n)");
scanf("\n%c",&ans);
}while(ans=='y');
break;

case 2: if(root==NULL)
printf("Tree Is Not Created");
else {
printf("\nThe Inorder display: ");
inorder(root);
printf("\nThe Preorder display: ");
preorder(root);
printf("\nThe Postorder display: ");
postorder(root);
}
break;
}
}while(choice);
return 0;
}
