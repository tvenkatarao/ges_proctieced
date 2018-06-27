/* 
 * unsigned char input() : function to take integer input from the user and 
 * return it
 */

#include "header.h"

unsigned char input (void)
{
	unsigned char data[4];

	if (NULL == fgets (data, sizeof (data), stdin)) {
		printf ("input failed\n");
		exit (EXIT_FAILURE);
	}
	
	return (((char) (atoi (data))));

}
