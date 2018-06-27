#include<stdio.h>

int sum_fun(int num)
{
int res;
for(res=0;num>0;res+=num%10,num/=10);
return res;


}


int main()
{
int num,sum,res;
printf("enter the number :");
scanf("%d",&num);

printf("in sun_fun=%d",sum_fun(num));
do{

sum=0;
while(num != 0)
{
res = num%10;
sum +=res;
num = num/10;
}
printf("\nsum=%d",sum);
num = sum;
}while(num/10!=0);


return 0;

}


