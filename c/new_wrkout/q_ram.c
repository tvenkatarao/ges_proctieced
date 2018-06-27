#include<stdio.h>
int main()
{
	char c[]="ram\0";
	char s[4]="hari";
	int i;
	for(i=0;c[i]!='\0';i++)

		s[i]=c[i];
	s[i]='\0';

	printf("%s %s\n",c,s);

}
