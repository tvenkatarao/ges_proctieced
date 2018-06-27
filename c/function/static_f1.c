#include<stdio.h>

int (*fptr)(int);

int main()
{
	int x=20;
	
	printf("fun ret val :- %d\n",x=fptr(x));
	printf("fun address :- %d\n",fptr(x));
	return 0;
}

