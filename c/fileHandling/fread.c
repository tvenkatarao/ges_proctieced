#include<stdio.h>
int main()
{
	char ch;
	FILE *fp;
	char ch;
	fp = fopen("/home/naveen/sample3.yuv", "r");

	fp = fopen("one.txt", "r");

	while( (ch = getc(fp) != EOF))
	{
		if(ch ==(char*)0xFF)// && if((ch =getc(fp)) == ch2))
			printf("strting....\n");

	}

}
