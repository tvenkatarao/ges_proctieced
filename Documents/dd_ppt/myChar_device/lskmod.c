
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

/** Constants **/

#define FIRST_MINOR 4
#define NR_DEVS 1 //Number of device numbers

//Function declarations for syscall definitions

int myOpen ( struct inode *inode, struct file *filep ) ;
int myRelease ( struct inode *in, struct file *fp ) ;

//Initialization routines

static int myInit ( void ) ;
static void myExit ( void ) ;

struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = myOpen,
    .release = myRelease
} ;

/* Global variables */

char *devname ; //contains device name
int majNo ;
static dev_t mydev ; //encodes major number & minor number device
struct cdev *my_cdev ; //holds character device driver descriptor

/* To accept input from the command line */

module_param(devname, charp, 0000) ;

//Class & device structures

static struct class *mychar_class ;
static struct device *mychar_device ;


int myOpen ( struct inode *inode, struct file *filep )
{
    printk (KERN_INFO "open successful \n") ;
    return 0 ;
}


int myRelease ( struct inode *in, struct file *fp )
{
    printk (KERN_INFO "File released \n") ;
    return 0 ;
}

/*
 * myInit: init function of the kernel module
 */

static int __init myInit ( void )
{
    int ret = -ENODEV ;
    int status ;


    /**********  Allocating Device Numbers   ************/


    status = alloc_chrdev_region ( &mydev, FIRST_MINOR, NR_DEVS, devname ) ;
//    status = register_chrdev_region ( mydev , NR_DEVS, devname ) ;

    if ( status < 0 ) {
        printk ( KERN_NOTICE "Device numbers allocation failed: %d\n", status ) ;
	goto err ;
    }

    printk ( KERN_INFO "Major number allocated= %d\n", MAJOR(mydev) ) ;
    printk ( KERN_INFO "Minor number allocated= %d\n", MINOR(mydev) ) ;







    my_cdev = cdev_alloc () ;//Alllocate memory for my_cdev

    if ( my_cdev == NULL ) {
	    printk (KERN_ERR "cdev_alloc failed \n") ;
	    goto err_cdev_alloc ;
    }

    cdev_init ( my_cdev, &fops ) ; //Initialize my_cdev with fops
    my_cdev->owner = THIS_MODULE ;
    status = cdev_add ( my_cdev, mydev, NR_DEVS ) ; //Add my_cdev to the list

    if ( status ) {
        printk ( KERN_ERR "cdev_add failed \n") ;
        goto err_cdev_add ;
    }

    //create a class and an entry in sysfs

    mychar_class = class_create (THIS_MODULE, devname) ;

    if ( IS_ERR (mychar_class )
       ) {
        printk ( KERN_ERR "class_creat () failed\n") ;
        goto err_class_create ;
    }

    //creates mychar_device in sysfs and a device entry
    //will be made in /dev directory

    mychar_device = device_create ( mychar_class, NULL, mydev, NULL, devname ) ;

    if ( IS_ERR ( mychar_device ) ) {
        printk (KERN_ERR "device_create () failed\n") ;
        goto err_device_create ;
    }

    return 0 ;
err_device_create:
    class_destroy ( mychar_class ) ;
err_class_create:
    cdev_del ( my_cdev ) ;
err_cdev_add:
    kfree ( my_cdev ) ;
err_cdev_alloc:
    unregister_chrdev_region ( mydev, NR_DEVS ) ;
err:
    return ret ;
}

/*
 * myExit: Cleanup function of the kernel module
 */

static void __exit myExit ( void )
{
    printk ( KERN_INFO "Exiting the character Driver \n") ;
    device_destroy ( mychar_class, mydev ) ;
    class_destroy ( mychar_class ) ;
    cdev_del ( my_cdev ) ;


/******* unregistering the device numbers *********/

    unregister_chrdev_region ( mydev, NR_DEVS ) ;

    return ;
}

module_init ( myInit ) ;
module_exit ( myExit ) ;
