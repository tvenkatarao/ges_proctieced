#include<stdio.h>
#include<stdlib.h>
void display_array(char *q)
{
int t;
for(t=0;t<10;t++)
printf("%c ",*q++);

}
int main()
{
char s[20];
printf("enter data:");
scanf("%s",s);
display_array(&s);

}
