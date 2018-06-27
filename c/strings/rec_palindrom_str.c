#include<stdio.h>
#include<string.h>
str_plndr(char str[],int len)
{
	int l = (strlen(str) - (len+1));
	printf("l=%d\n",l);
	if(str[l] == str[len])
	{
		if(len+1 == l || len == l)
		{
			printf("the entered string is a palindrome\n");
			return;
		}
		str_plndr(str,len+1);
	}
	else
	{
		printf("not a palindrome\n");
	}

}
int main()
{
	char str[10];
	printf("enter the string ..\n");
	scanf("%s",str);
//	int len=strlen(str)-1;
	str_plndr(str,0);

	return 0;
}
