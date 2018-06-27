#include<stdio.h>
int main()
{
	int pos1,pos2,no_of_bits,num,bit1,bit2,i;
	printf("enter the pos1,pos2,num\n");
	scanf("%d %d %d",&pos1,&pos2,&num);

	for(i=31;i>=0;i--)
		printf("%d",(num&(1<<i))?1:0);
mask = 0xffffffff;
   no_of_bits = pos2-pos1;
	for(i=0;i<no_of_bits+1;i++)
	{
		
      mask = mask 
       
       
       
       bit1 = num & (1<<pos1+i);
		bit2 = num & (1<<pos2+i);

		bit2 = bit2 >>(pos2-pos1);

		if(bit1 != bit2)
		{
			num = num ^ (1<<(pos1+i));
			num = num ^ (1<<(pos2+i));
		}

	}
	printf("\n%d\n",num);
	for(i=31;i>=0;i--)
		printf("%d",num &(1<<i)?1:0);
printf("\n");

}
