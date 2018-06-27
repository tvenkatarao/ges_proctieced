#include<stdio.h>
int main()
{
int i, num=128;
printf("enter the pos\n");
//scanf("%d",&pos);

for(i=31;i>=0;i--)
{
if(num & ~(1<<i))
printf("i=%d is set\n",i);


}

return 0;
}
