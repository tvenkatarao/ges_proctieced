#include<stdio.h>
#include<stdlib.h>

int main()
{

static int x;

char ch;
do{
x++;
printf("do u want to increment x value:(y/N):\n");
scanf("%c ",&ch);
}while(ch == 'y');
printf("x=%d",x);

}
