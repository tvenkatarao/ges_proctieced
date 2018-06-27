#include<stdio.h>

int *call();
int main(){

	int *ptr;
	ptr=call();

//	fflush(stdin);
free(ptr);

ptr = call();
	printf("%d",*ptr);
	return 0;
}
int * call(){

//static int x=25;
 int x=25;
	++x;

	return &x;
}
