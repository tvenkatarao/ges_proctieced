#include<stdio.h>
int main()
{
	char str1[20],str[10];
	printf("enter the strings...\n");
	scanf("%[^\n]s",str1);

	printf("enter the sub strings...\n");
	scanf("%s",str);
	int i=0,j=0,k=0;
	for(i=0;str1[i];i++){
		if(str1[i]==str[0])
		{
			for(k=i;str[j];j++,k++)
			{
				if(str1[k]==str[j]);
				break;
			}
		}
	}
			if(str1[k]==str[j])
				printf("sub is present...\n");
}
