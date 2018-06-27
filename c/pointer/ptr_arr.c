#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int pwr(int a ,int b)
{
	register int t=1;
	for(;b;b--)
	t = t*a;
return t;

}

int main()
{
	int (*p)[10];
	register int i,j;

	p = malloc(40*sizeof(int));
	if(!p)
	{

		printf("memory request failed..\n");
		exit(1);
	}

	for(j=1;j<11;j++)
		for(i=1;i<5;i++)
		 p[i-1][j-1] = pwr(i,j);
		printf("\n");

	for(j=1;j<11;j++)
	{
		for(i=1;i<5;i++)
			printf("%10d ", p[i-1][j-1]);
		printf("\n");
	}
	return 0;
}
