#include<stdio.h>
int main()
{


	char s[20],s1[20];
	printf("enter the string s:\n");
	scanf("%s",s);
	printf("enter the string s1:\n");
	scanf("%s",s1);

	int res;
	res = str_cmp(s,s1);
	if(res)
		printf("not eql\n");
	else
		printf("eql\n");
}

int str_cmp(char *s , char *s1)
{
	int i;
	for(i=0;s[i] && s1[i];i++)
		if(s[i] == s1[i] || (s[i] ^32)==s1[i])
			continue;
		else
			break;


	if(s[i] == s1[i])
	{
	printf("s=%c\ts1=%c",s[i],s1[i]);
		return 0;
		}
	else
		return 1;
}
