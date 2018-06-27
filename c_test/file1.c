//#include<stdio.h>
int a=0,b=10;
static int fun1(int x,int y)
{
x=y;

printf("%d, %d",x,y);
return 0;
}
int (*pfun)(int , int )=&fun1;
//pfun=fun1;
/*
int main(void)
{
fun1(a,b);
return 0;
}
*/
