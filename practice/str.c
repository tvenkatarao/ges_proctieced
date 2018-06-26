#include<stdio.h>
char *ptr="helo";

//const int *ptr=4;

main()
{
char *ptr1="helo";
//const int *ptr1=4;
if(ptr==ptr1)
printf("true ptr=%x....ptr1=%x \n",ptr,ptr1);
else
printf("False");

}

