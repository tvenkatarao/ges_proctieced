// code error bcos core dump 


#include<stdio.h>
int (*funp)(char *,...);

void str_fun(char *p,char *q,int len)
{
	int i=len-1,j;
char *temp;
temp = (char*)malloc(len+len);
while(*q)
{
temp[j++]=*q++; // core dump


}
//*temp='\0';

printf("after concatination :%s\n",*temp); 
	return; 

}

int main()
{

	char s1[20],s2[20];
	printf("enter the string one:");
	scanf("%s",s1);

	printf("\nenter the string TWO:");
	scanf("%s",s2);

int len=sizeof(s1)/sizeof(s1[0]);


	funp=str_fun;
	funp(s1,s2, len);
printf("after concatination :%s\n",s1); 

	return 0;

}
