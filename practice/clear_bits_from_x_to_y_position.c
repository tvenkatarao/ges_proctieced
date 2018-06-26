#include<stdio.h>

int clear_bits(int *i,int s, int e)
{
while(s<=e)
{
*i= *i & ~(1<<s);
s++;
}

}

int main(void)
{
int *res,i,s,e;
printf("enter i value:\n");
scanf("%d",&i);
printf("enter strat position value:\n");
scanf("%d",&s);
printf("enter enter end position value:\n");
scanf("%d",&e);
res=&i;
clear_bits(res,s,e);
printf("Result=%d\n",*res);
return;
}
