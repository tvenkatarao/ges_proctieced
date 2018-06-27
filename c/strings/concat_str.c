#include<stdio.h>
#include<string.h>
int main()
{
	int i=0,j=0;
	char str1[20],str2[10];
	printf("enter the strings...\n");
	scanf("%s",str1);
	scanf("%s",str2);
	i=strlen(str1);
	for(;str2[j]!='\0';i++,j++)
	{
		str1[i] = str2[j];

	}
	str1[i]='\0';
	printf("str1:%s\n",str1);
	printf("str2:%s\n",str2);
}

