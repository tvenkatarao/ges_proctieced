#include<stdio.h>
int main()
{
	char s[30],s1[20];
	printf("enter the string 1:\n");
	scanf("%[^\n]",s);
	printf("enter the string 2:\n");
	scanf(" %[^\n]",s1);

	int i,j,k;

	for(i=0,k=0;s[i];i++)
	{
		if(s[i] == s1[0])
		{
			for(j=0;s1[j];j++,i++)
				if(s[i] != s1[j])
					break;
			if(s1[j] == '\0')
				k++;
			j--;
		}
	}
printf("no.of sub strings:%d\n",k);
	return 0;
}
