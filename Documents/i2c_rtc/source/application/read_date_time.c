/*
 * read_date_time.c - Read the time, day and date from the rtc driver
 */

#include "header.h"

void read_date_time(int fd)
{
	unsigned char read_time_buff[7];

	if (-1 == read (fd, read_time_buff, sizeof (read_time_buff))) {
		printf ("read function failed\n");
		exit (EXIT_FAILURE);	
	}

	return;
}
