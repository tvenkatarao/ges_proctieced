#include<stdio.h>
int prime(int num ,int i)
{
	if(i==1)
	{
		return 1;
	}
	else
	{
		if(num%i == 0)
			return 0;
		else
			prime(num,i-1);
	}

}


int main()
{

	int num,res;
	printf("enter the number:");
	scanf("%d",&num);
	res = prime(num,num/2);

	if(res == 1)
		printf("\nit is prime number:%d\n",num);
	else
		printf("it is not a prime number:%d\n",num);


	return 0;
}
