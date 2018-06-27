
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

/*
 * myOpen: open function of the pseudo driver
 *
 */

int myOpen ( struct inode *inode, struct file *filep )
{
    printk (KERN_INFO "open successful \n") ;
    return 0 ;
}

EXPORT_SYMBOL_GPL(myOpen);
