#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd ;
    pid_t pid1;
    pid_t ppid;

    fd = open ("/dev/myChar", O_RDWR) ;
    if ( fd < 0 ) {
        perror ("unable to open the device") ;
    } else {
		pid1 = getpid();
		ppid = getppid();
                printf("%d\n",pid1);
                printf("%d\n",ppid);
             ioctl(fd, pid1, ppid, NULL);
        printf ("File opened succesfully %d\n", fd) ;
    }

    close (fd) ;
    return 0 ;
}
