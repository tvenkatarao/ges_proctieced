#include<stdio.h>
main()
{
int a=0,b=4,c=3,d;
 a=b=c=5;
 d= a>1?b>1&&c>1?100:200:300;
printf("%d",d);
}
