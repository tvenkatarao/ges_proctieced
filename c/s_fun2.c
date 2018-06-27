#include<stdio.h>
//static int fun(void);
static int fun(int x)
{
	printf("inside fun 2\n");
	return x*x;
}


int foo(int x)
{
	printf("inside foo:\n");
	return fun(x);

}


int (*fptr)(int) = fun;


