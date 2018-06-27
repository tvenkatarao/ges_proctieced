
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
 * myRelease: close function of the pseudo driver
 *
 */

int myRelease ( struct inode *in, struct file *fp )
{
    printk (KERN_INFO "File released \n") ;
    return 0 ;
}

EXPORT_SYMBOL_GPL(myRelease);
