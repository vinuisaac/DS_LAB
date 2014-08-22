/*Lab 04 - c. Calculate the sum for a given number ‘n’ from 1 to n.*/

#include<stdio.h>
#include<conio.h>

int add(int m)
{
int sum;
if(m==1)
    return(1);
else
   sum=m+add(m-1);
return(sum);
}

void main()
{
int i,num;
int sum;
clrscr();
printf("Input a number : ");
scanf("%d",&num);
sum=add(num);
printf("nSum of Number From 1 to %d :%d",num,sum);
getch();
}
