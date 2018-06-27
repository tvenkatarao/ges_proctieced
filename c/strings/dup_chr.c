#include<stdio.h>
int main()
{
	char s[100],c;
	int i,j,k;
	printf("enter the string...\n");
	scanf("%[^\n]",s);
	printf("before:%s\n",s);
	for(i=0;s[i];i++)
	{
		c=s[i];
		for(j=i+1;s[j];j++)
		{
			if(c==s[j])
			{
				for(k=j;s[k];k++)
					s[k]=s[k+1];
				j--;
			}
		}
	}
	printf("after string:%s\n",s);

}
