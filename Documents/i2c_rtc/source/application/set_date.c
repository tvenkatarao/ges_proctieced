/*
 * set_date.c : Set the date and year is in 20xx formate
 */

#include "header.h"

void set_date (unsigned char time_buff[], int size)
{
	unsigned char data;

	printf ("Enter date of the month:\n");
	data = input();

	if ((data < 1) || (data > 31)) {
	   printf ("Invalid date");
	   exit (EXIT_FAILURE);
	}
	time_buff[5] = data;

	printf ("Enter the month no. of the year (e.g. for Jan, month no is 1)\n");
	data = input();

	if ((data < 1) || (data > 12)) {
	   printf ("Invalid month no.");
	   exit (EXIT_FAILURE);
	}
	time_buff[6] = data ;

	printf ("Enter year (20xx)\n");
	data = input();

	if ((data < 0) || (data > 99)) {
	   printf ("Invalid year range.");
	   exit (EXIT_FAILURE);
	}
	time_buff[7] = data;
	
	return;
}
