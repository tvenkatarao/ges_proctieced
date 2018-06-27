#include<stdio.h>
char * fun(char *s1,char *s2)
{

	while(*s1)
	{
		if(*s1 == *s2)
		{
			for(;*s1 == *s2;s1++,s2++);
		}
		s1++;
	}
	if(*s1 == *s2)
		printf("%s--> is present\n",*s2);
	else
		printf("not\n");
}


int main()
{
	char s1[20];//="naveenkumarreddy";
	char s2[29];//="ku";
printf("enter the strings\n");
scanf("%s %s",s1,s2);
	fun(s1,s2);

	return 0;

}
