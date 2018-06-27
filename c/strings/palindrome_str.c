#include<stdio.h>
#include<string.h>
int main()
{
	char str[10];
	printf("enter the string ...\n");
	scanf("%s",str);
	int i,j;
	j=strlen(str)-1;
	for(i=0;j>=i;i++,j--)
	{
		if(str[i]!=str[j])
		{
		break;
		}
	}
	if(str[i] == str[j])
		printf("string is palindrom :-%s\n",str);
	else
		printf("string is not palindrom:%s\n",str);

return 0;
}
