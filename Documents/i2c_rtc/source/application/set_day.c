/*
 * set_day.c : Set the day of the week
 * Sunday is the starting day of the week i.e. Weekday no. 1 .
 * Saturday is the last day of the week i.e. Weekday no. 7 .
 */

#include "header.h"

void set_day(unsigned char time_buff[], int index)
{
	unsigned char data;

	printf ("Enter the week day no. from the below:\n"
			"1. Sunday\n"
			"2. Monday\n"
			"3. Tuesday\n"
			"4. Wednesday\n"
			"5. Thursday\n"
			"6. Friday\n"
			"7. Saturday\n");
	
	data = input();

	if ((data < 1) || (data > 7)) {
		printf ("Invalid week day no.");
		exit (EXIT_FAILURE);
	}

	time_buff [4] = data;
	return;
}
