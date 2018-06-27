#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd;
    int pid_num;
    fd = open("/dev/mychar",O_RDWR);
    if(fd < 0)
        perror ("unable to open the device");
    else
        printf ("File opened Suceessfully %d\n",fd);

    pid_num = getpid();
    printf("pid is =%d\n", pid_num);

    ioctl(fd, pid_num, NULL);

    close(fd);
    return 0;
}


