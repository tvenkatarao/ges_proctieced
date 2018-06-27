#include<stdio.h>
int main()
{
int a[5]={10,1,2,3,4};
printf("%d\n",*(a+3));
printf("%d\n",*((char*)(a+3)));
main();
return 0;

}
