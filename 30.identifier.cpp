#include <stdio.h>
#include <ctype.h>
int main()
{
	char a[10];
	printf("\nEnter an identifier: \n");
	gets(a);
	if (isalpha(a[0]))
	{
		printf("valid identifier");
		
	}
	else
	{
		printf("not a valid identifier");
	}
	return 0;
}
