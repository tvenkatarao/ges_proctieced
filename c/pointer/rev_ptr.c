#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void pr_reve(char *s)
{

register int t;
for(t=strlen(s)-1;t>=0;t--) putchar(s[t]);
}

int main()
{
pr_reve("i like c");
return 0;

}
