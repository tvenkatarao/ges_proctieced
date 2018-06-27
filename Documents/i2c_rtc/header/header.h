#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

unsigned char input (void);

void set_time_date (int);
void set_time (unsigned char [], int);
void set_date (unsigned char [], int);
void set_day (unsigned char [], int);

void read_date_time (int);
