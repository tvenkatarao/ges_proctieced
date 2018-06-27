#include<stdio.h>

typedef void (*callback)(void);

void main_fun(callback fun_callback)
{

	printf("inside function\n");
	(*fun_callback)();
}

void my_callback(void)
{

	printf("inside my_callback\n");

}


int main()
{
	callback fun_callback  = my_callback;

	main_fun(fun_callback);
	printf("back inside main \n");
	return 0;


}
