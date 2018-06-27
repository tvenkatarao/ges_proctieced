#include <stdio.h>
int main(void)
{
int n=5;

printf("inside main :%d\n",n=fptr(n));
return 0;
}


int (*fptr)(int);
