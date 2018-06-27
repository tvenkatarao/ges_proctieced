#include<stdio.h>
#include<string.h>

void reverse(char str1[],int index,int size)
{
	char temp;
	temp = str1[index];
	str1[index] = str1[size - index];
	str1[size - index] = temp;
	if(index == size/2)
	{
		return;
	}
	reverse(str1 , index+1, size);
}
int  main()
{
	char str1[10];
	int size;
	printf("enter the string to reverse...\n");
	scanf("%s",str1);
	size = strlen(str1);
	reverse(str1,0,size-1);
	printf("the string after reverse is :%s\n",str1);
	return 0;

}
