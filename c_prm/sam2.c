#include<stdio.h>
main()
{
int x,c=0,y,z=1;
scanf("%d",&x);
while(x)
{
y=(x&1)*z;

c=c+y;
//c=c*10;
x=x>>1;
z*=10;
}
//c/=10;
printf("%d\n",c);
}
