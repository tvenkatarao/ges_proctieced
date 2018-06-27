#include<stdio.h>
#define SIZEOF(x) (char*)(&x+1) -(char*)(&x)


int main()
{
int i;
float f;
double d;

printf("i=%d\n",SIZEOF(i));
printf("f=%d\n",SIZEOF(f));
printf("d=%d\n",SIZEOF(d));


}
