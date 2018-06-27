#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int res, fd[2],s;
	char str[25],str1[25];
	res=pipe(fd);
	if(res == -1)
	{
		perror("\n pipe creation failed...\n");
		exit(1);
	}
	else
	{
		printf("\n pipe created successfully ...\n");
		printf("\ndescriptors are:%d\t%d\n",fd[0],fd[1]);
		switch(fork())
		{
			case -1: perror("\n fork failed...\n");
				 exit(1);
			case 0: wait(&s);
				res = read(fd[0],str1,sizeof(str1));
				if(res<0)
				{
					perror("\n read error...\n");
					exit(1);
				}
				else
				{
					printf("\n child process read successfully\n");
					printf("data:%s\n",str1);
				}
				break;
			default:
				printf("\nparent process...\n");
				printf("\nenter the data to be written to pipe\n");
//				gets(str);
				scanf("%s",str);
				res = write(fd[1],str,sizeof(str));
				if(res<0)
				{
					perror("\n write error occurred\n");
					exit(1);
				}
				else
				{
					printf("\npipe written successfully..\n");
				}
				break;
		}
	}
}





