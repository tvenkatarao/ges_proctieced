#include<stdio.h>
int main()
{

int a[5]={1,2,3,4,5}, *ptr ,(*p)[3];
ptr = a;
p = a;
a=ptr+1;

printf("ptr:%x p:%x\n",((ptr+1)-ptr),((p+1)-p));
printf("ptr:%x p:%x\n",(ptr+1),(p+1));
printf("ptr:%x\n",(ptr)); 
printf("ptr:%x\n",a); 
}
