/* the for formula of A square and B square */

#include <stdio.h>
int  a_square_b_square_formula(int a, int b)
{
	int result= a+b;
//	result = (a*a) + (b*b) + (2*a*b);
	return result*=result;
}
main()
{
	int res,x,y;
char ch ;
	printf("enter two A and B numbers: ");
	scanf("%d",&x);
	scanf("%d",&y);
	printf( "enter the char \n");
	scanf("%c",&ch);
	res = a_square_b_square_formula(x,y);
        printf("Result=%d \n", res);
	return;
}

