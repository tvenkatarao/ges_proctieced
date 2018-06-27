#include<stdio.h>
int add(int x,int y)
{
	while(y!=0)
	{
		int carry = x & y;

		x = x ^ y;
printf("\n-----------------%d\n",x);
		y = carry << 1;
printf("\n-----------------%d\n",y);
	}
	return x;
}
int main()
{
	int x=1515151515,y=3215151515;
	printf("%d",add(x,y));
	return 0;


}
