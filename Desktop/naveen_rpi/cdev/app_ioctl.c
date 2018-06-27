#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>


//------------------------------------------------------
#ifndef APP_IOCTL_H
#define APP_IOCTL_H
#include <linux/ioctl.h>

typedef struct
{
	int status;
} st_arg_t;

#define APP_GET_VARIABLES _IOR('q', 1, st_arg_t *)
#define APP_CLR_VARIABLES _IO('q', 2)
#define APP_SET_VARIABLES _IOW('q', 3, st_arg_t *)

#endif
//-------------------------------------------------------


void get_vars(int fd)
{
	st_arg_t q;

	if (ioctl(fd, APP_GET_VARIABLES, &q) == -1)
	{
		perror("apps ioctl get");
	}
	else
	{
		printf("Status : %d\n", q.status);
	}
}
void clr_vars(int fd)
{
	if (ioctl(fd, APP_CLR_VARIABLES) == -1)
	{
		perror("apps ioctl clr");
	}
}
void set_vars(int fd)
{
	int v;
	st_arg_t q;

	printf("Enter Status: ");
	scanf("%d", &v);

	q.status = v;

	 if (ioctl(fd, APP_SET_VARIABLES, &q) == -1)
	{
		perror("apps ioctl set");
	}
}

int main(int argc, char *argv[])
{
	char *file_name = "/dev/query";
	int fd;
	enum
	{
		e_get,
		e_clr,
		e_set
	} option;

	if (argc == 1)
	{
		option = e_get;
	}
	else if (argc == 2)
	{
		if (strcmp(argv[1], "-g") == 0)
		{
			option = e_get;
		}
		else if (strcmp(argv[1], "-c") == 0)
		{
			option = e_clr;
		}
		else if (strcmp(argv[1], "-s") == 0)
		{
			option = e_set;
		}
		else
		{
			fprintf(stderr, "Usage: %s [-g | -c | -s]\n", argv[0]);
			return 1;
		}
	}
	else
	{
		fprintf(stderr, "Usage: %s [-g | -c | -s]\n", argv[0]);
		return 1;
	}
	fd = open(file_name, O_RDWR);
	if (fd == -1)
	{
		perror("apps open");
		return 2;
	}

	switch (option)
	{
		case e_get:
			get_vars(fd);
			break;
		case e_clr:
			clr_vars(fd);
			break;
		case e_set:
			set_vars(fd);
			break;
		default:
			break;
	}

	close (fd);

	return 0;
}
