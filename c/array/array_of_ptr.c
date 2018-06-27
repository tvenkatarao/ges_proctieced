#include <stdio.h>
#include <string.h>

/* function prototype */
void match_str(char const * const, char const * const[], int const);

int main(void)
{
	char const *car_make[9] = {"Suzuki","Toyota","Nissan","Tata","BMW", 
		"Audi","Chevrolet","Honda","Mahindra"};
	char to_search[15];

	printf("Give choice of \'car make\' u want to search for...\n");
	gets(to_search);
	match_str(to_search, car_make, 9);
	return 0;
}

void match_str(char const * const to_match, char const * const arr_str[],
		int const size)
{
	char const **check_make;

	for (check_make = arr_str; check_make < arr_str + size; check_make++)
		if (strcmp(to_match, *check_make) == 0) {
			printf("Matched at location %d in car_make.\n",
					check_make - arr_str);
			return;
		}

	printf("Not matched!\n");
	return;
}
