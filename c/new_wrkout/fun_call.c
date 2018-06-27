#include<stdio.h>

int *call();
int main()
{
	int *ptr;
	ptr=call();
	fflush(stdin);
	printf("%d",*ptr);
	return 0;
}
int * call()
{
	int x=25;
	++x;
	return &x;
}
