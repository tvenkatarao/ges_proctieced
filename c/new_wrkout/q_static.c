#include<stdio.h>
static int a=2;
volatile int b=5;
int main()
{
int a=3;
int b=0x27;
//int c= b>>a | ++b & ++a *b;
int c= b>>a | ++b & ++a *b;
//int d= ~(c>>2)/c++|++b*++a;
int d= ~(c>>2)|c++|++b*++a;
printf("%d %d %d %d\n",a,b,c,d);
}
