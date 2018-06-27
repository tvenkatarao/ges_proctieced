#include<stdio.h>
const int x=10;
int main()
{
int y=100;
//const int *p =&x;
//int const *q=&y;
//*q= 30;
int *p =&x;
*p = 20;
y = 200;
printf("%d",*p);
printf("%d",x);
printf("%d",y);
}
