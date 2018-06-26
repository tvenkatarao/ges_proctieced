#include<stdio.h>
main()
{
int a=10,b=7;
while(b)
{
printf("before inner while\n");
for( ;a; )
{
printf("in inner while\n");
//break;
printf("after inner break\n");
a=0;
}
printf("after inner while\n");
b=0;
}

}
