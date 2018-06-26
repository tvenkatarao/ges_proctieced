#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <err.h>

#define FILE_NAME "/dev/eeprom"

int main(void)
{
 	int rc,wc,test=1;
	int fd, count, i,k;
	unsigned char buf[256];
        unsigned char *buf2,*buf3,*pos;
	
	strcpy(buf,"please work as all right at any time runnig thanks for working");
	wc=strlen(buf)+1;
	printf("count value %d\n",wc);
	if(wc>256)
	{
	printf("Invalid: string length should be lees than 256");
	return 0;

	}
	buf3=(char *)malloc(256);
	if(buf3==NULL)
	{
	printf("ERROR: buf3 memory allocated failed");
	}

	printf(" %s Opened \n", FILE_NAME);
        if ((fd= open(FILE_NAME, O_RDWR)) < 0) {
		perror("open");
		printf("Error:Failed open %s\n", FILE_NAME);
				exit(1);
	}
	sleep(1); 
	while(1)
	{
	int x;
	printf("enter \n 0 for continue \n 1 for break \n");
	scanf("%d",&x);
	if(x)
	break;

	buf2=mmap(0,256,PROT_READ | PROT_WRITE, MAP_SHARED,fd,0);
	if(buf2==MAP_FAILED)
	{
	printf("ERROR: mmap failed");
	return 0;
	}

	//printf("%s \n",buf2);
	/*strcpy(buf2,buf);
	
	strcpy(buf3,buf2);

   	printf("Recieved data prints as inteaser decimal value\n");
	printf("%s \n",buf3);*/

	printf("initial message: %s\n", buf2);
    	strcpy(buf2, "*user space memory to kernel*");
    	printf("changed message: %s\n", buf2);
	}
        close(fd);
	free(buf3);

       	printf("\n close completed\n");

	return 0;
}

