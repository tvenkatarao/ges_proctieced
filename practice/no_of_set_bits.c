/* the programme for find no of set bits in givren number*/
#include<stdio.h>

int no_of_set_bits(int x)
{
	int res=0;
	while(x)
	{
		if(x&1)
			res++;
		x=x>>1;
	}

	printf("no of set bits of given x value = %d \n",res);
    	return res;
}

int main(void)
{
	int res, x;
	printf("enter the x value:");
	scanf("%d",&x);
	res = no_of_set_bits(x);
	printf("no of set bits of given x value = %d \n",res);
	return;

}
