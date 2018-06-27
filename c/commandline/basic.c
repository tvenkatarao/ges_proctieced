#include<stdio.h>
int main(int argc,char *argv[])
{
	int i;
	if(argc < 2)
	{
		printf("usage ./a.out num ");
		return 0;
	}
	for(i=argc-1;i>=0;i--)
		printf("arguments:%s\n",argv[i]);


	return 0;

}
