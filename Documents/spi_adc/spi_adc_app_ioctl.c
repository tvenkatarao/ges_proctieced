#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/types.h>
#include<sys/ioctl.h>

int main()
{

	int fd, i=0,j,p = 0;
	fd = open("/dev/spi_adc",O_RDWR);

	if(fd < 0) {
		printf("Unable to open the Device");
		return 0;
	}
	else {
		printf("File opened successfully %d\n",fd);
	}

	printf("FILE DESCRIPTER == %d \n", fd);

		if(ioctl(fd,1,1) != 0) {
						perror("ioctl");
		} else {
						printf("ioctl is not invoked...\n");
		}
		printf("%d ----------------> \n",p);
		close(fd);

	return 0;
}
