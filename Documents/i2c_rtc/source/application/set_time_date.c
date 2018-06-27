/*
 * set_time_date.c - Set time or  date or day or b based on user input.
 * set_time (char [], int) : set the time in 12 hours formate.
 * set_date (char [], int) : set the date.
 * set_day (char [], int)  : set the day of the week.
*/

#include "header.h"

void set_time_date (int fd)
{
	int choice;
	unsigned char time_buff[10] = {0};

	memset (time_buff, '\0', sizeof (time_buff));

	printf ("Enter the choice from the following\n"
			"1. Set time\n"
			"2. Set date\n"
			"3. Set day\n"
			"4. Set time, date and day\n"
			"5. Exit\n");


	choice = input();

	switch (choice) {
	
		case 1	:	set_time(time_buff, sizeof (time_buff));
					
					time_buff [8] = 0x01;
					time_buff [9] = 0x03;
					
					if (-1 == write (fd, time_buff, sizeof (time_buff))){
						perror ("write failed");
						exit (EXIT_FAILURE);
					}
					read_date_time(fd) ;
					break;

		case 2	:	set_date (time_buff, sizeof (time_buff));
					time_buff [8] = 0x05;
					time_buff [9] = 0x07;
					
					if (-1 == write (fd, time_buff, sizeof (time_buff))){
						perror ("write failed");
						exit (EXIT_FAILURE);
					}
					read_date_time(fd) ;
					break;

		case 3	:	set_day (time_buff, sizeof (time_buff));
					
					time_buff [8] = 0x04;
					time_buff [9] = 0x04;
					
					if (-1 == write (fd, time_buff, sizeof (time_buff))){
						perror ("write failed");
						exit (EXIT_FAILURE);
					}	
					read_date_time(fd) ;
					break;

		case 4	:	set_time (time_buff, sizeof (time_buff));
					set_date (time_buff, sizeof (time_buff));
					set_day (time_buff, sizeof (time_buff));
					
					time_buff [8] = 0x01;
					time_buff [9] = 0x07;
					
					if (-1 == write (fd, time_buff, sizeof (time_buff))){
						perror ("write failed");
						exit (EXIT_FAILURE);
					}
					read_date_time(fd) ;
					break;

		case 5	:	break;

		default	:	printf ("Entered wrong choice\n");

	}

	return;
}
