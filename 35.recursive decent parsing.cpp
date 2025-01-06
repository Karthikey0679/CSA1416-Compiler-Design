#include<stdio.h>
int c=0;
char p[20];
void s();
void l();
void lprime();
void l()
{
	s();
	lprime();
}
void lprime()
{
	if(p[c]==',')
	{
		c++;
		s();
		lprime();
		
	}
}
void s()
{
	if(p[c]=='a')c++;
	else if(p[c]=='(')
	{
		c++;
		l();
		if(p[c]==')')
		c++;
		else
		c--;
	}
	else
	printf("\n Invalid Expression");
}
int main()
{
	printf("\n Implementation of recursive descent parser");
	printf("\n enter the expression: ");
	scanf("%s",p);
	s();
	if(p[c]=='$')
	printf("\n the string is accepted");
	else
	printf("\n the string is rejected");
}
