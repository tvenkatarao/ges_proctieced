/*
 * set_time.c : Set the time in 12 hours formate 
 */

#include "header.h"

/*
 * unsigned char bcd2bin (unsigned char ) : Function to convert the binary code
 * decimal into binary.
 */
unsigned char bcd2bin (unsigned char bcdByte)                                              
{                                                                               
		return (((bcdByte & 0xF0) >> 4) * 10) + (bcdByte & 0x0F);               
}                                                                               

/*
 * unsigned char bin2bcd (unsigned char ) : Function to convert binary into 
 * binary code decimal.
 */
unsigned char  bin2bcd (unsigned char decimalByte)                                          
{                                                                               
		return (((decimalByte / 10) << 4) | (decimalByte % 10));                
}  


void set_time (unsigned char time_buff[], int size)
{
	unsigned char time_period; 
	unsigned char data;

	printf ("Enter time in 12 hours formate (HH:MM:SS):\n");
	
	printf ("Enter the hours in 12 hours formate\n");
	data = input();
	if ((data < 1) || (data > 12)) {
		printf ("Invalid hour formate");
		exit (EXIT_FAILURE);
	}
	time_buff[3] = data;
	
	
	printf ("Enter the no. of  mintues\n");
	data = input();
	if ((data < 0) || (data > 59)) {
		printf ("Invalid no. of minutes");
		exit (EXIT_FAILURE);
	}
	time_buff[2] = data;
	

	printf ("Enter the no. of seconds :\n");
	data = input();
	if ((data < 0) || (data > 59)) {
		printf ("Invalid no. of seconds");
		exit (EXIT_FAILURE);
	}
	time_buff[1] = data;


	printf ("Enter the time period (for AM press 0 / for PM press 1)\n");
	data = input();
	if ((data != 0) && (data != 1)){
		printf ("Invalid time formate");
		exit (EXIT_FAILURE);
	}

	if (data)
		time_buff[3] = bcd2bin ((bin2bcd (time_buff[3])) | bin2bcd (60));
	else
		time_buff[3] = bcd2bin (((bin2bcd (time_buff[3])) & (~bin2bcd(20))) 
								| bin2bcd (40));
	return;
}
