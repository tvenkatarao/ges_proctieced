//system includes//


#include <linux/init.h>
#include <linux/module.h>
//#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

//constants//
#define FIRST_MINOR 10
#define NR_DEVS 1//number of device numbers//

//Function Declarations for syscall definations//

int myOpen (struct inode *inode , struct file *filep);
int myRelease (struct inode *in,struct file *fp);
int my_ioctl(int, int, char*);
//intialization routines

static int myInit (void);
static void  myExit(void);

struct file_operations fops = {

    .owner = THIS_MODULE,
    .open = myOpen,
    .release = myRelease,
    .unlocked_ioctl = my_ioctl
};

//Global variables
//
char *devname; //contains device name

int majNo;
static dev_t mydev; //encodes maj num and minor num
struct cdev *my_cdev; //holds character device descriptor

//to accept input from command line//

module_param (devname,charp, 0000);

//class and device structures//
static struct class *mychar_class;
static struct device *mychar_device;
//
int myOpen (struct inode *inode,struct file *filep)
{
    printk (KERN_INFO "open successfull\n");
    return 0;
}
//
int myRelease (struct inode *in,struct file *fp)
{
   printk (KERN_INFO "file released\n");
   return 0; 
}

//my IOCTL function
int my_ioctl(int fd, int pid ,char *temp )
{
    printk (KERN_INFO "pid is %d\n", pid);
    return 0;
}



//myinit :init function of the kernel module//
static int __init myInit(void)
{
    int ret = -ENODEV;
    int status;
    printk (KERN_INFO "intializing character device\n");
//allocating device numbers//

        status = alloc_chrdev_region (&mydev ,FIRST_MINOR,NR_DEVS,devname);
        if ( status < 0)
        {
            printk (KERN_NOTICE "Device nums allocation failled %d \n",status);
            goto err;
        }
    printk (KERN_INFO "major number allocated = %d\n",MAJOR(mydev));
    my_cdev = cdev_alloc();

    if (my_cdev == NULL)
    {
        printk (KERN_ERR "cdev allocation faiiled\n");
        goto err_cdev_alloc;
    }
    cdev_init(my_cdev,&fops);
    my_cdev->owner = THIS_MODULE;
    status = cdev_add (my_cdev,mydev,NR_DEVS);
    if ( status) { 
        printk (KERN_ERR "cdev_addfaiiled\n");
        goto err_cdev_add;
    }
    //create a class and an empty systs//

    mychar_class = class_create (THIS_MODULE ,devname);
    
    if ( IS_ERR (mychar_class)) {
        printk (KERN_ERR "CLAss create failled\n");
        goto err_class_create;
    }


    mychar_device = device_create (mychar_class,NULL,mydev,NULL,devname);
    if (IS_ERR (mychar_device)) {
        printk (KERN_ERR "device create failled\n");
        goto err_device_create;
    }
    return 0;

err_device_create:
class_destroy (mychar_class);

err_class_create:

cdev_del(my_cdev);
err_cdev_add:
kfree (my_cdev);
err_cdev_alloc:
unregister_chrdev_region(mydev,NR_DEVS);

err:
    return ret;
}

//myExit:cleanup Function to the kernel module//

static void myExit(void)
{
    printk (KERN_INFO "Existing the character driver\n");
    device_destroy (mychar_class, mydev);
    class_destroy (mychar_class);
    cdev_del (my_cdev);
    unregister_chrdev_region(mydev,NR_DEVS);
    return;
}
module_init (myInit);
module_exit (myExit);






