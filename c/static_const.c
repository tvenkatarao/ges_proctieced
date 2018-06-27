#include<stdio.h>

void display (void)
{

	int j=10;
	++j;
	printf("J=%d \n",j);

}

main(void)
{

	int i;
	for (i=0;i<10;++i)
		display();

}


