#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fp;
	char ch;
	char s[20];

	fp = fopen( "one.txt", "w+");
	if(fp==NULL)
	{
		printf("could not  open file one.txt");
		return 1;
	}

	printf("enter the data: ");
scanf("%s",s);
fprintf(fp,"name = %s\n",s);
	
fclose(fp);
	return 0;
}
