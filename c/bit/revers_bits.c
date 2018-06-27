#include<stdio.h>

int main()
{
	int num,i,j,m,n;
	printf("enter the number :\n");
	scanf("%d",&num);

	for(i=31;i>=0;i--)
		printf("%d",num>>i&1);

	printf("\nrevers\n");

	for(i=31,j=0;i>=j;i--,j++)
	{
		m = num >> i & 1;
		n = num >> j & 1;
printf("m=%d---n=%d\n",m,n);

		if(m != n)
		{
			num = num^1<<i;
			num = num^1<<j;
		}
	}

	for(i=31;i>=0;i--)
		printf("%d",num>>i&1);

	printf("\n");


	return 0;

}
