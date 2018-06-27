#include<stdio.h>
#include<stdlib.h>
int main()
{
	char *p;
	char s[20];

	do{
		p=s;
		gets(s);
		while(*p)
			printf(" %d ",*p++);
	}while(strcmp(s,"done"));
	return 0;

}
