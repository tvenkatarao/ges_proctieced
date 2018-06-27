#include<stdio.h>
int divi(int n)
{

	if(n<0) 
		n=-n;
	else if(n ==0)
		return 1;
	while(n>3)
	{
		int sum = 0;
		while(n > 0)
		{
			sum += n & 3;
			n >>= 2;
		}
		n = sum;
	}
	return n == 3;
}
int divi_3(int n1)
{
	for(;n1;){
		while(!(n1&1)) n1>>=1;
		n1>>=1;
		if(n1==0) return 0;
		n1-= 1;
	}
	return 1;
}



int main()
{
	int num;
	printf("enter the number ..:\n");
	scanf("%d",&num);

	int res = divi(num);
	if(res == 1)
		printf("num is divisible by 3...:\n");
	else printf("num is not divisible by 3...:\n");
	int res1 = divi_3(num);
	if(res1 == 1)
		printf("num is divisible by 3...:\n");
	else printf("num is not divisible by 3...:\n");
}

