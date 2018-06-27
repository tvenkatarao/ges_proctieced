#include<stdio.h>
int main()
{
	char s[100],temp;
	printf("enter the string:\n");
	scanf("%[^\n]",s);

	int i,j,k;
	for(i=0,k=0;s[i];i++)
	{
		if(s[i] == ' '||s[i+1] == '\0')
		{
			if(s[i+1] == '\0')
				i++;
			for(j=i-1;j>k;j--,k++)
			{
				temp = s[j];
				s[j] = s[k];
				s[k] = temp;
			}
			k = i+1;
		}
	}
	printf("%s\n",s);



}
