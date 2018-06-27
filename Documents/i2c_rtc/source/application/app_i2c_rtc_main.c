/*
 * app_i2c_main.c - RTC application showing menu to set and read time-date 
 * from the RTC device.
 * 
 * set_time_date (int) - Function having argument of int type and provide 
 * options to user to set time, day and date based on requirement.
 *
 * read_date_time (int) - Function having argument of int type and read the
 * day, date and time from the rtc driver.
 */

#include "header.h"

int main (void)
{
	int fd;
	int choice;

	fd = open ("/dev/i2c_rtc", O_RDWR);
	if (fd < 0) {
		perror ("Unable to open the device\n");
		exit (EXIT_FAILURE);
	}
	
	else 
		printf ("File opened Successfully with file descriptor %d\n", fd);
	
	printf ("Enter the choice from the following menu\n"
			"1. Set Time and Date\n"
			"2. Read Time and Date\n"
			"3. Exit\n");
	
	choice = input();

	switch (choice) {
		
		case 1  :	set_time_date(fd);
					break;

		case 2  :	read_date_time(fd);
					break;

		case 3  :	break;

		default :	printf ("Entered wrong choice\n");

	}

	if	(-1 ==  close (fd)) {
		perror ("Unable to close\n");
		exit (EXIT_FAILURE);
	}

	return 0;	
}
