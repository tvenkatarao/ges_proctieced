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

#define FILE_NAME "/dev/eeprom"
struct user_info 
{
int pos;
int count;
char buf[256];
};


int main(void) 
{      	struct user_info *user,*user2;
	user=(struct user_info *)malloc(sizeof(struct user_info));
	user2=(struct user_info *)malloc(sizeof(struct user_info));
	int rc,wc,test=1;
	int fd, count, i,k;
	unsigned char buf[256];
        unsigned char *buf2,*pos;
	
	strcpy(buf,"please work as all right at any time runnig");
	wc=strlen(buf)+1;
	printf("count value %d\n",wc);
	if(wc>256)
	{
	printf("Invalid: string length should be lees than 256");
	return 0;
	}
	buf2=(char *)malloc(sizeof(char)*wc);
	if(buf2==NULL)
	{
	printf("Error: memory allocation of buf2 failed.");
	return 0;
	}
//printf("count value %d\n",wc);
	user->pos=20;
	user->count=wc;
	user2->pos=20;
	user2->count=wc;
//printf("count value %d\n",wc);
	strcpy(user->buf,buf);
	printf(" %s Opened \n", FILE_NAME);
        if ((fd= open(FILE_NAME, O_RDWR)) < 0) {
		perror("open");
		printf("Error:Failed open %s\n", FILE_NAME);
				exit(1);
	}
	sleep(1); 
	if (ioctl(fd,0,user )<0)

        printf("Error:In calling Write\n");

	printf("Invoking Read \n"); 
	//strcpy(user->buf,buf2);    
        sleep(1);
	if ((count =ioctl(fd, 1,user2)) <0) {
	printf("Error:Read failed \n");
	return 0;
	}
        printf("Recieved data prints as inteaser decimal value\n");
	printf("%s \n",user2->buf);


        close(fd);
	free(user);
	free(user2);
	free(buf2); 
       printf("\n close completed\n");

   return 0;
}
