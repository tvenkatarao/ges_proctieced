#include<stdio.h>
int main()
{
	int i;
	char s[20],d[20],*p,*q;

	printf("enter the string \n");
	scanf("%s",s);

	for(p=s,q=d;*q=*p;p++,q++);


	printf("s=sring:%s\nd=string :%s\n",s,d);


}
