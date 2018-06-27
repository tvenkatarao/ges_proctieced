#include<stdio.h>
#include<stdlib.h>

int main()
{
	char *ptr[5];
	int i=0;
		char *p;
	for(i=0;i<5;++i)
	{
		p = malloc(sizeof(char)*15);
		printf("enter the string \n");
		scanf("%s",p);
		ptr[i] = malloc(sizeof(p)+1);
		ptr[i] = p;
//		free(p);
	}


	for(i=0;i<5;++i){
		printf("%s\n",ptr[i]);
}
		free(p);
	return 0;

}
