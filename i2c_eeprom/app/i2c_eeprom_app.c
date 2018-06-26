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
	int rc,wc,test=1;
	int fd, count, i,k;
	unsigned char buf[256];
        unsigned char buf2[256];
	strcpy(buf,"please work as al right");
	/*for (i = 0; i < 256; i++)
	{
	buf[i]=3;
	}*/
	wc=strlen(buf)+1;
	if(wc>256)
	{
	printf("Invalid: string length should be lees than 256");
	return 0;
	
	}

	printf(" %s Opened \n", FILE_NAME);
        if ((fd= open(FILE_NAME, O_RDWR)) < 0) {
		perror("open");
		printf("Error:Failed open %s\n", FILE_NAME);
				exit(1);
	}
        printf("Invoking Write\n");
 	//scanf("write how many bytes want to write %d \n",&wmax);

    
	sleep(1); 
	if (write(fd,buf,wc)<=0)

        printf("Error:In calling Write\n");

	printf("Invoking Read \n");
        //scanf("write how many bytes want to read %d\n",&rmax);            
        sleep(1);
	if ((count = read(fd, buf2, wc)) <= 0) {
	printf("Error:Read failed \n");
	return 0;
	}
        printf("Recieved data prints as inteaser decimal value\n");
	printf("%s \n",buf2);
   	//puts(buf2);
	//char *b; 
	//b=itoa(2, b, 16);
	//printf("%s \n",b);

	/*for (i = 0; i < 256; i++)
	{
	if (!(i % 16))
		printf("\n");
	printf("%x  ", buf2[i]);
	}
*/
        close(fd);
        printf("\n close completed\n");

   	return 0;
}
