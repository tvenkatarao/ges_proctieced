#include<stdio.h>
char *fun(char *p)
{
static int count =0;
    if(*p!='\0'){
        	fun(p+1);
        //fun(p++); // core dump
    }
	printf("%c",*p);
}
int main()
{
	char s[20]="hello";
	fun(s);
printf("\n");
	return 0;
}
