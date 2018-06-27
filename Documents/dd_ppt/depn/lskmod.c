
/** System Includes **/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>


MODULE_LICENSE("Dual BSD/GPL") ;

extern struct list_head modules;
struct module *temp1;
struct module *temp;
long myioctl ( struct file *pfile, unsigned int pid, unsigned long m)
{
	int i;
	printk (KERN_INFO "ioctl successful \n") ;
	printk (KERN_INFO "pid=%ld\n",m) ;

	printk(KERN_INFO "%-30s%-10s%-10s\n", "module neme", "size","used by");
	list_for_each_entry(temp1, &modules, list) {
		i=0;
		list_for_each_entry(temp, temp1->source_list.next, source_list) {
			i++;
			//printk(KERN_INFO "%s", temp->name);

		}
		printk(KERN_INFO "%-30s%-10d%-5d\n", temp1->name, (temp1->core_layout).size,i);
	}
	return 0 ;
}

EXPORT_SYMBOL_GPL(myioctl);
