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

#define FILE_NAME "/dev/eeprom"

int main(void) 
{
	int fd, count, i,k;
	unsigned char buf[10]={48,49,50,51,52,53,54,55};
        unsigned char buf2[10],*j;
	unsigned char buf3[256]={0};
	/*

	printf(" enter 1 for write same byte in all locations\n");
	printf(" enter 0 for write different random byte in all locations\n");
	scanf("%d",&k);
       // unsigned char buf3[1]={0x00}; */
	printf(" %s Opened \n", FILE_NAME);
        if ((fd= open(FILE_NAME, O_RDWR)) < 0) {
		perror("open");
		printf("Error:Failed open %s\n", FILE_NAME);
				exit(1);
	}	
        printf("Invoking Write\n");
	 sleep(1); 
	if (write(fd,buf,10)<=0)
	        printf("Error:In calling Write\n");

	printf("Invoking Read \n");
        sleep(1);
	if ((count = read(fd, buf2, 10)) <= 0) {
		printf("Error:Read failed \n");
		return 0;
	}
        printf("Recieved data prints as inteaser decimal value : count = %d\n",count);

	for (i = 0; i < 10; i++)
	{
	if (!(i % 16))
		printf("\n");
	printf("%c  ", buf2[i]);
	}

        close(fd);
        printf("\n close completed\n");

   return 0;
}
