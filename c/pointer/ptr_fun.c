#include<stdio.h>
#include<string.h>
void check(char *a,char *b,int (*cmp)(const char *,const char*));

int main()
{
	char s1[20] , s2[20];
	int (*p)(const char *,const char*);
	p = strcmp;
	printf("enter two strings...\n");
	gets(s1);
	gets(s2);

	check(s1 ,s2,p);
	return 0;
}
void check(char *a,char *b, int (*cmp)(const char *,const char *))
{
	printf("testing for equality,...\n");
	if(!(*cmp)(a,b))
		printf("equal");
	else
		printf("not equal");
}



