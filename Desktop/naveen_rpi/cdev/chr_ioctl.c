#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/errno.h>
#include <asm/uaccess.h>
 
 //------------------------------------------
#ifndef APP_IOCTL_H
#define APP_IOCTL_H
#include <linux/ioctl.h>
 
typedef struct
{
    int status;
} st_arg_t;

/*
The direction of command operation  read, write, both, or none — filled by the corresponding macro (_IOR, _IOW, _IOWR, _IO) 
*/

 
#define APP_GET_VARIABLES _IOR('q', 1, st_arg_t *) // read 
#define APP_CLR_VARIABLES _IO('q', 2) 		   // none
#define APP_SET_VARIABLES _IOW('q', 3, st_arg_t *) //write

 
#endif
// -----------------------------------------------





#define FIRST_MINOR 0
#define MINOR_CNT 1
 
static dev_t dev;
static struct cdev c_dev;
static struct class *cl;
static int status = 1; 
 
static int my_open(struct inode *i, struct file *f)
{

printk(KERN_INFO "inside open \n");
    return 0;
}
static int my_close(struct inode *i, struct file *f)
{

printk(KERN_INFO "inside close \n");

    return 0;
}
static long my_ioctl(struct file *f, unsigned int cmd, unsigned long arg)
{
    st_arg_t q;
 
    switch (cmd)
    {
        case APP_GET_VARIABLES:
            q.status = status;
            if (copy_to_user((st_arg_t *)arg, &q, sizeof(st_arg_t)))
            {
                return -EACCES;
            }
            break;
        case APP_CLR_VARIABLES:
            status = 0;
            break;
        case APP_SET_VARIABLES:
            if (copy_from_user(&q, (st_arg_t *)arg, sizeof(st_arg_t)))
            {
                return -EACCES;
            }
            status = q.status;
            break;
        default:
            return -EINVAL;
    }
 
    return 0;
}
 
static struct file_operations query_fops =
{
    .owner = THIS_MODULE,
    .open = my_open,
    .release = my_close,
/*#if (LINUX_VERSION_CODE < KERNEL_VERSION(2,6,35))
    .ioctl = my_ioctl
#else*/
    .unlocked_ioctl = my_ioctl
/*#endif*/
};
 
static int __init char_ioctl_init(void)
{
    int ret;
    struct device *dev_ret;
 
 
    if ((ret = alloc_chrdev_region(&dev, FIRST_MINOR, MINOR_CNT, "query_ioctl")) < 0)
    {
        return ret;
    }
 
    cdev_init(&c_dev, &query_fops);
 
    if ((ret = cdev_add(&c_dev, dev, MINOR_CNT)) < 0)
    {
        return ret;
    }
     
    if (IS_ERR(cl = class_create(THIS_MODULE, "char")))
    {
        cdev_del(&c_dev);
        unregister_chrdev_region(dev, MINOR_CNT);
        return PTR_ERR(cl);
    }
    if (IS_ERR(dev_ret = device_create(cl, NULL, dev, NULL, "query")))
    {
        class_destroy(cl);
        cdev_del(&c_dev);
        unregister_chrdev_region(dev, MINOR_CNT);
        return PTR_ERR(dev_ret);
    }
 
    return 0;
}
 
static void __exit char_ioctl_exit(void)
{
    device_destroy(cl, dev);
    class_destroy(cl);
    cdev_del(&c_dev);
    unregister_chrdev_region(dev, MINOR_CNT);
}
 
module_init(char_ioctl_init);
module_exit(char_ioctl_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("naveen-venkat-ravi");
MODULE_DESCRIPTION("APP ioctl() Char Driver");
