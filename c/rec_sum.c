#include<stdio.h>
long int rec_sum1(int a[],int n)
{
 static long sum = 0;
 
   if (n == 0)
      return sum;
 
   sum = sum + a[n-1];
 
   return rec_sum(a, n--);
}

int rec_sum(int *a,int i)
{

	if(i<=0)
		return 0;

return (rec_sum(a,i-1) + a[i-1]);

}

int main()
{
	//int num1,num2,num3,num4;
	int a[4];
int i;
	printf("enter the numbers :\n");
	//scanf("%d %d %d %d",&num1,&num2,&num3,&num4);
	for(i=0;i<4;i++)
		scanf("%d",&a[i]);

	int res ;
	res= rec_sum(a,4);
	printf("%d\n",res);
	res= rec_sum1(a,4);
	printf("%d\n",res);

}




