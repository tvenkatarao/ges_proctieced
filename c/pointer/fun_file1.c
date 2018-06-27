#include<stdio.h>


int (*foop)(int);

int main()
{
	int x=20;
	printf("foop(%d)= \n",x);
	printf("%d\b",x=foop(x));

	return 0;
}


