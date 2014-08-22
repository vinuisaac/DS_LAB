/* Lab 01 -Evaluate postfix expression */
#include<stdio.h>
#include<string.h>
#include<math.h>

double compute(char,double,double);
double res;
main()
{
char s[20],postfix[20],symbol;
int i,top=-1;
double op1,op2;
printf("\n Enter Valid Postfix Expression : ");
scanf("%s",postfix);
for(i=0;i<strlen(postfix);i++)
{
symbol=postfix[i];
if(isdigit(symbol))
{
s[++top]=symbol-'0';
}
else
{
op1=s[top--];
op2=s[top--];
res=compute(symbol,op1,op2);
s[++top]=res;
}
}
printf("\n Result : %f \n",res);
}
double compute(char symbol,double op1,double op2)
{
switch(symbol)
{
case '+':
return(op1+op2);
case '-':
return(op2-op1);
case '*':
return(op1*op2);
case '/':
return(op2/op1);
case '^':
return(pow(op2,op1));
case '$':
return(pow(op2,op1));
}
}
