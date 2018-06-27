// swap the position of bits 
#include<stdio.h>

int (*funp)(int *,...);


int bit_swap(int *p,int pos1, int pos2)
{
	int bit1=0,bit2=0;
	if(bit1 != bit2)
	{
		(*p)^=(1<<pos1);
		(*p)^=(1<<pos2);

	}
	

	printf("p:-%d\tpos1:-%d\tpos2:-%d\n",*p,pos1,pos2);
	printf("bit1:-%d\n",bit1 = (*p)&(1<<pos1));
	printf("bit2:-%d\n",bit2 = (*p)&(1<<pos2));

return 0;
}
int bit_print(int *num)
{
	int i;
	printf("bit print\n");
	for(i=31;i>=0;i--)
		printf("%d",((1<<i)&(*num)) ? 1:0);
return 0;
}



int main()
{
	int num, pos1,pos2 ,i;
	printf("enter the number num:\n");
	scanf("%d %d %d",&num,&pos1,&pos2);

	funp = &bit_print;
	funp(&num);

	printf("\n");


	funp = bit_swap;
	(*funp)(&num,pos1,pos2);

	printf("\n");
	funp = bit_print;
	(*funp)(&num);

	printf("\n");


	return 0;

}
