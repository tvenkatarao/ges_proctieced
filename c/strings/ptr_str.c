#include<stdio.h>
int main()
{
char s[10],d[10];
printf("enter the string\n");
scanf("%s",s);

char *p;
p=&s;
printf("%c",*p);


}
