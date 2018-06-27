#include<stdio.h>
int main()
{
	int num,i=2,flag=0;
	printf("enter the num\n");
	scanf("%d",&num);
	for(;i<=num/2;i++)
	{
		if(num%i == 0)
		{
			printf("not prime\n");
			flag = 1;
			break ;
		}
	}
	if(flag == 0)
		printf("num is prime\n");


}
