#include<stdio.h>
#include<stdlib.h>
int main()
{
	char str1[100] = "ab cde fg hg";
	char str2[100] ; 
	char str3[200] ; 

	sscanf(str1,"%s",str2);
	printf("%s\n",str2);
	sscanf(str1,"%s %s",str2,str3);
	printf("%s %s\n",str2 ,str3);




}
