#include<stdio.h>
int main()
{

	int i,j,l;
	char s[30],temp;
	printf("enter the string :\n");
	scanf("%s",s);

	for(l=0;s[l];l++);
	for(i=0;i<l;i++)
	{
		for(j=0;j<l-1;j++)
			if(s[j]>s[j+1])
			{
				temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			}
	}
	printf("\n%s\n",s);

}
