#include<stdio.h>
#include<string.h>

int main()
{
	int i,j,k=0,l=0,count = 1;
	char s[1024],temp[1024],temp2[1024];

	printf("enter the string \n");
	scanf("%[^\n]",s);

int len = strlen(s);
	for(i=0;i<= len;i++)
	{
		temp[k++]=s[i];
		if(s[i] == ' ' || s[i] == '\0')
		{
			temp[i] = '\0';
			for(j=i+1;j<=len;j++)
			{
				temp2[l++] = s[j];
				if(s[j] == ' ' || s[j] == '\0')
				{
					temp2[l]='\0';
//					printf("\n\t--->%s = %s\n",temp,temp2);
					if(strcmp(temp2,temp) == 0 ){
						count++;
						}
					l = 0;

				}

			}

		count = 0;
		k = 0;
		}
	printf("\n%s\tcount=%d\n",temp,count);

	}



}
