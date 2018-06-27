#include<stdio.h>
#include<string.h>
void main()
{
	char MainStr[50],Str1[50],Str2[50];
	int n,Pos,i,j,l1,l2;
	printf("Enter the MainString\n");
	scanf("%s",MainStr);
	printf("Enter the No.of Characters U want to Delete\n");
	scanf("%d",&n);
	printf("Enter the Position From Where U Want to Delete\n");
	scanf("%d",&Pos);
	l1=strlen(MainStr);
	for(i=0;i<Pos;i++)
	{
		Str1[i]=MainStr[i];
	}
	for(i=n+Pos,j=0;i<l1;i++,j++)
	{
		Str2[j]=MainStr[i];
	}
	printf("\nStr1=%s",Str1);
	printf("\nStr2=%s",Str2);
	printf("After Removing Set of Characters From Main String=%s\n",strcat(Str1,Str2));
}
