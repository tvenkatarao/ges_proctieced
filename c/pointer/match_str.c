#include<stdio.h>
#include<stdlib.h>
char *match(char c,char *s)
{
while(c!=*s && *s) s++;
return (s);

}

int main()
{

char s[20],*p,ch;
gets(s);
ch = getchar();
p = match(ch ,s);

if(*p)
printf("%s \n",p);
else
printf("no match found\n");

return 0;
}


