#include <stdio.h>
int Atoi(char *str)
{
	if (*str == '\0')
		return 0;
	int res = 0;	// Initialize result
	int sign = 1;	// Initialize sign as positive
	int i = 0;	// Initialize index of first digit
	if (str[0] == '-') 
	{
		sign = -1;
		i++;	// Also update index of first digit
	}
	if (str[0] == '+') 
	{
		sign = 1;
		i++;	// Also update index of first digit
	}
	for (; str[i] != '\0'; ++i)
	{
		if ( str[i] <= '0' || str[i] >= '9')
			return 0;
		res = res*10 + str[i] - '0';
	}
	return sign*res;
}
int main()
{
	char str[10];// = "1234";
printf("enter the string ...\n");
scanf("%s",str);
int re ;
re = atoi(str);
if(re)
printf("if str is :%d\n",re);
else
printf("else str is :%d\n",re);
int res;
res = Atoi(str);
if(res == 0)
printf("entred string is not an integer ...\n");
else
	printf("entered string is integer:-%d \n", res);
	return 0;
}
