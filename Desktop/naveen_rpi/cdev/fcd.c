#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>


static int __init ofcd_init(void) /* Constructor */
{
	printk(KERN_INFO "Namaskar: ofcd registered:-");
	return 0;
}

static void __exit ofcd_exit(void) /* Destructor */
{
	printk(KERN_INFO "nvr: ofcd unregistered");
}

module_init(ofcd_init);
module_exit(ofcd_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("naveen venkat ravi");
MODULE_DESCRIPTION("Our First Character Driver");
