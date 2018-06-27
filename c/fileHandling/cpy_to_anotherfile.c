#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	FILE *in,*out;
	char ch;

	if(argc != 3)
	{
		printf("./a.out arg1 arg2 ...\n");
		exit(1);
	}

	if((in = fopen(argv[1],"rb")) == NULL)
	{
		printf("cannot open input file.\n");
		exit(1);
	}

	if((out =fopen(argv[2],"wb")) ==NULL)
	{
		printf("cannot open output file.\n");
		exit(1);
	}
	while(!feof(in))
	{
		ch = getc(in);
		if(ferror(in))
		{
			printf("read error\n");
			clearerr(in);
			break;
		}
		else
		{
			if(!feof(in) )
				putc(ch,out);
			if(ferror(out))
			{
				printf("write error\n");
				clearerr(out);
				break;
			}
		}
	}
	fclose (in);
	fclose (out);

	return 0;
}
