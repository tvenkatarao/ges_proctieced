#include<stdio.h>
#include<stdlib.h>




struct arra
{

char *ch;

}*aptr[5];


int main()
{
	char *ptr[5];
//	char *sptr[5];
	int i=0;
		char *p;
	for(i=0;i<5;++i)
	{
		p = malloc(sizeof(char)*15);
		printf("enter the string \n");
		scanf("%s",p);
		ptr[i] = malloc(sizeof(p)+1);
		ptr[i] = p;
		aptr[i]->ch = p;
	}


	for(i=0;i<5;++i){
		printf("%s-->array\n",ptr[i]);
		printf("%s-->structure\n",aptr[i]->ch);
}
		free(p);
	return 0;

}
