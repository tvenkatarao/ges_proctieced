#include<stdio.h>
register int x = 10;
int main()
{
int i =100; 
register int *p = &i;



printf("%p\n",p);
printf("%d\n",*p);



}
