#include<stdio.h>
/*
struct A{
		int i;
		char ch[30];	};
*/
int main()
{
char *p = "abc";
		printf ("%c", *p++);
//		printf ("%c", ++*p);
		printf ("%c", (*p)++);
//printf("%d\n",sizeof (struct A));

}
