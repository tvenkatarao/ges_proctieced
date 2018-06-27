/*
 * The below are header files provided by the kernel which are
 * required for all modules.  They include things like the definition
 * of the module_init() macro.
 */

#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

/*
 * This is the init function, which is run when the module is first
 * loaded.  The __init keyword tells the kernel that this code will
 * only be run once, when the module is loaded.
 */

//int __init hello_init(void)
int  hello_init(void)
{
    printk("Hello, world!\n");
	return 0;
}
/*
 * Similary, the exit function is run once, upon module unloading, and
 * the module_exit() macro identifies which function is the exit
 * function.
 */
 void hello_exit(void)
// void __exit hello_exit(void)
{
	printk("Goodbye, world!\n");
}
module_init(hello_init);
module_exit(hello_exit);


