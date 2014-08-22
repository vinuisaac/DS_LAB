/*Lab 01 - convert prefix notation to postfix*/
#include<stdio.h>
#include<string.h>
void push(char [],int*,char [][20]);
char *pop(int*,char [][20]);
void pre_post(char [],char []);
void main()
{
   char prefix[20];
   char postfix[20];
   //clrscr();
   printf("Enter the prefix expression\n");
   scanf("%s",prefix);
   pre_post(prefix,postfix);
   printf("The postfix expression is %s\n",postfix);
   //getch();
}
void push(char item[],int* top,char stack[][20])
{
   *top=*top+1;
   strcpy(stack[*top],item);
}
char* pop(int* top,char stack[][20])
{
   char *item;
   item=stack[*top];
   *top=*top-1;
   return item;
}
void pre_post(char prefix[],char postfix[])
{
   char stack[20][20],symb,temp[2],*opnd1,*opnd2;
   int top=-1,i;
   strrev(prefix);
   for(i=0;i<strlen(prefix);i++)
   {
      symb=prefix[i];
      temp[0]=symb;
      temp[1]='\0';
      switch(symb)
      {
	case'+':
	case'-':
	case'*':
	case'/':
	case'$':
		opnd1=pop(&top,stack);
		opnd2=pop(&top,stack);

		strcpy(postfix,opnd1);
		strcat(postfix,opnd2);
		strcat(postfix,temp);

		push(postfix,&top,stack);
		break;

	default:
		push(temp,&top,stack);
      }
   }
}
