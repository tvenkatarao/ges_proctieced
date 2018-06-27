#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	int res,temp1,temp2;

printf("%s %s %s\n",argv[1].argv[2],argv[3]);

	if((argc < 3) && (argc >4))
	{
		printf("Usage: ./a.out num1 opertation(|,!,&,^) num2\n");
		return 0;
	}
char op = argv[2];

	switch(op)
	{
		case '|': 
			temp1 = atoi(argv[1]);
			temp2 = atoi(argv[3]);
			res = temp1 | temp2;
			break ;
		case '&': 
			temp1 = atoi(argv[1]);
			temp2 = atoi(argv[3]);
			res = temp1 & temp2;
			break ;
		case '!': 
			temp1 = atoi(argv[1]);
			//	temp2 = atoi(argv[3]);
			res = !temp1;
			break ;
		case '^': 
			temp1 = atoi(argv[1]);
			temp2 = atoi(argv[3]);
			res = temp1 ^ temp2;
			break ;

		default:
			printf("unknown arguments \n");
			break ;
	}

	printf("res:%d\n",res);

	return 0;
}
