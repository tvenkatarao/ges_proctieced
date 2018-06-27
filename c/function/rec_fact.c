#include<stdio.h>
int fact_fun(int num)
{

	if(num)
		return (num* fact_fun(num-1));
	else
		return 1;

}

int main()
{
	int num;
	printf("enter the number:\n");
	scanf("%d",&num);

	int res = fact_fun(num);
	printf("%d\n",res);

	return 0;

}
