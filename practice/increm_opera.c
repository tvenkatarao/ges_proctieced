#include<stdio.h>
main()
{

int a = 10;
int b=a++;
a = ++a;
printf("before a=a++  b=%d a=%d\n",b,a);
a = a++;
printf("after a=a++  b=%d a=%d\n",b,a);
int c = ++a;
printf("after c=++a  b=%d a=%d\n",b,a);
printf("c=%d b=%d a=%d\n", c,b,a);
a = ++a;

a = a++;
a = a++;
a = a++;
a = a++;
a = a++;
a = a++;
printf("c=%d b= %d a=%d\n", c,b,a);


}
