#include<stdio.h>
void print(char *p)
{

if(*p)
{
printf("%c",*p);
print(p+1);
printf("\n");
printf("%c",*p);
}

}

int main()
{
char s[20];
printf("string:");
scanf("%[^\n]",s);
printf("\nprinting the string ni recursive:\n");
print(s);


return 0;
}
