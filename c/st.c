#include<stdio.h>
static int x=30;
int *fun()
{
				{
								static int x = 5;
				}		             
				return &x;
}						
int main()
{
				int *p = fun();
printf("%d\n",x);
				printf("%d", *p);
				return 0;

}
