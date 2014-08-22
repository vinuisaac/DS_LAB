/*Lab 04 - a. Calculate GCD and LCM of 3 integer numbers*/
#include<stdio.h>
#include<conio.h>
int gcd(int m,int n)
{
	if(n==0) return m;
	if(m<n) return gcd(n,m);
	return gcd(n,m % n);
}

void main()
{
	int x,y,z,res;
	clrscr();
	printf("Enter the values of x,y and z");
	scanf("%d%d%d",&x,&y,&z);
	res=gcd(gcd(x,y),z);
	printf("gcd(%d,%d,%d)=%d\n",x,y,z,res);
	printf("lcm(%d,%d,%d)=%d",x,y,z,((x*y*z)/res));
	getch();
}
