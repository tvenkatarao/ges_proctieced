#include<stdio.h>
int main()
{
int *x = malloc(10);
void *q = x;
int *i = malloc(sizeof(int));
*i = 100;
printf("%d",*i);

void *p  = i;
//printf("%d",*p);




}
