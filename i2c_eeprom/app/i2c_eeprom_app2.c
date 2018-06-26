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
	
	printf("enter how many bytes you want to write, it should be in between 0 t0 256\n");
	scanf("%d",&wc);
	while(test)
	{
	if(wc<=256)
	test=0;
	else
		{
		printf("Error: Entered value is invalid\n");
		printf("enter how many bytes you want to write, it should be in between 0 t0 256\n");
		scanf("%d",&wc);
		}
	
	}
	test=1;
	while(test)
	{
	if(rc<=256)
	test=0;
	else
		{
		printf("Error: Entered value is invalid\n");
		printf("enter how many bytes you want to read, it should be in between 0 t0 256\n");
		scanf("%d",&rc);
		}
	
	}
	
	int fd, count, i,k;
	unsigned char buf[wc];
        unsigned char buf2[rc],*j;
	
	printf("Enter the data, it should be 8 bits(0 to 256) \n");
	scanf("%[^\n]%*c", buf);
	test=1;	
	while(test)
	{
	if(wc=strlen(buf)<=256)
	test=0;
	else
		{
		printf("Error: Entered value is invalid\n");
		printf("Enter the starting input byte data, it should be 8 bits(0 to 256) \n");
		scanf("%[^\n]%*c", buf);
		}
	
	}
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
 	//scanf("write how many bytes want to write %d \n",&wmax);

    
	 sleep(1); 
	if (write(fd,buf,wc)<=0)

        printf("Error:In calling Write\n");

	printf("Invoking Read \n");
        //scanf("write how many bytes want to read %d\n",&rmax);            
        sleep(1);
	if ((count = read(fd, buf2, rc)) <= 0) {
	printf("Error:Read failed \n");
	return 0;
	}
        printf("Recieved data prints as inteaser decimal value\n");

	for (i = 0; i < rc; i++)
	{
	if (!(i % 16))
		printf("\n");
	printf("%c  ", buf2[i]);
	}

        close(fd);
        printf("\n close completed\n");

   return 0;
}
