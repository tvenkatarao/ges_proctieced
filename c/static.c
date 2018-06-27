#include<stdio.h>
static int a=100;
//int a=11;
int main()
{
{
int a=10;
}
static int c=100;
//static int d=c; // error 
int d=c;

printf("%d\n",a);
printf("%d\n",d);
printf("%d\n");
int c1=10;
//static int *p=&c1;//error
//       int *p=&c1;   	//error

//.............................
static int c2=10;
//static int *p=&c2; //error
//         int *p=&c2;//error
}
