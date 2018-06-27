#include<stdio.h>
struct st
{
  unsigned int a:5=5;
};
main()
{
struct st p,*c;
c=&p;

printf("%d,%d \n", sizeof(p),(c-++c));
}
