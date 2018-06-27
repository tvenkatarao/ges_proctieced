/*module_parameter.c - Demonstrates command line argument passing to a module.*/
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");


static short int myshort = 1;
static int myint = 420;
static long int mylong = 500;
static char *mystring = "hello";
static int  myintArray[5] = { 10, 20, 30, 40 };
static int arr_argc = 0;

/* 
 * module_param(foo, int, 0000)
 * The first param is the parameters name
 * The second param is it's data type
 * The final argument is the permissions bits, 
 */

module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
module_param(mylong, long, S_IWUSR);
module_param(mystring, charp, 0000);

/*
 * module_param_array(name, type, num, perm);
 * The first param is the parameter's (in this case the array's) name
 * The second param is the data type of the elements of the array
 * The third argument is a pointer to the variable that will store the number 
 * of elements of the array initialized by the user at module loading time
 * The fourth argument is the permission bits
 */
module_param_array(myintArray, int, &arr_argc, 0000);
//module_param_array(myintArray, int, NULL, 0000);

static int __init my_param_init(void)
{
	int i;
	printk(KERN_INFO "Hello, world \n=============\n");
	printk(KERN_INFO "myshort is a short integer: %hd\n", myshort);
	printk(KERN_INFO "myint is an integer: %d\n", myint);
	printk(KERN_INFO "mylong is a long integer: %ld\n", mylong);
	printk(KERN_INFO "mystring is a string: %s\n", mystring);
	for (i = 0; i < (sizeof myintArray / sizeof (int)); i++){
	
		printk(KERN_INFO "myintArray[%d] = %d\n", i, myintArray[i]);
	}
	printk(KERN_INFO "got %d arguments for myintArray.\n", arr_argc);
	return 0;
}

static void __exit my_param_exit(void)
{
	printk(KERN_INFO "Goodbye, world \n");
}

module_init(my_param_init);
module_exit(my_param_exit);




MODULE_AUTHOR ("starting who wrote the module");
MODULE_DESCRIPTION ("a human readable statement of what the module does");
MODULE_VERSION ("for code revision number");
MODULE_ALIAS ("another name by which module can be known");
