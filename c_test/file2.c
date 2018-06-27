#include<stdio.h>
int (*pfun) (int q,int k);
int main(void)
{
int x=2,y=20;
 pfun(x,y);
return 0;
}

