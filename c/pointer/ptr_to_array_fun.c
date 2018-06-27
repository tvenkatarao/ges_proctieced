#include<stdio.h>
#include<stdlib.h>

int display();
int(*arr[3])();
int (*(*ptr)[3])();

int main()
{
	arr[0] = display;
//	arr[1] = getch;
	ptr = &arr;

	printf("%d",(**ptr)());
	(*(*ptr+1))();
	return 0;
}

int display()
{
	int num =25;
	return num;

}


