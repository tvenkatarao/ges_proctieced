#include<stdio.h>
#include<stdlib.h>
func(a,b)
	int a,b;
{
	return( a=(a==b) );
}
void main()
{
	int process(),func();
	printf("The value of process is %d \n ",process(func,3,6));
}
process(pf,val1,val2)
	int (*pf) ();
	int val1,val2;
{
	return((*pf) (val1,val2));
}
