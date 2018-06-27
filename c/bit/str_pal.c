#include<stdio.h>
#include<string.h>

int main()
{
	int i,j=0;
	char str[20];
	printf("enter the string:\n");
	scanf("%s",str);
	for(i=0,j=strlen(str)-1;i<=j;i++,j--)
		if(str[i]!=str[j])
			break;
	if(i>j)
		printf("pall");
	else
		printf("not");
}
