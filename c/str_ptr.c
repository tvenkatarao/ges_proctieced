#include <stdio.h>
int main()
{
	char s[] = "geeksquiz";
	char *s1 = "geeksquiz";
	printf("s[]:-%lu", sizeof(s));
	printf("*s1:-%lu", sizeof(s1));
s1=s1+12;	
	s[0] = 'j';
	printf("\n%s\n", s);

	printf("\n%s\n", s1);
	return 0;
}

