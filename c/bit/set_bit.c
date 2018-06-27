#include<stdio.h>

//#define BIT(POS) (1<<pos)
int main()
{
	int num,count=0,i;
	printf("enter the number:\n");
	scanf("%d",&num);
int res=sizeof(int);

	for(i=res;i>=0;i--)
		if(num&(1<<i))
		count++;





	printf("\ncount: %d\n",count);

	return 0;

}
