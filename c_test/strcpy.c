#include<stdio.h>
int main()
{
int i;
char s[20] ,*p=NULL,*q=NULL;
printf("enter the string \n");
scanf("%s",s);

p=malloc(sizeof(s));
q=malloc(sizeof(s));
for(i=0,*p=s;q[i]=p[i];i++);

printf("%s\t%s\n",s,*q);


}
