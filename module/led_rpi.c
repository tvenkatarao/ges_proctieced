#include<linux/module.h>                                       
#include<linux/init.h>

#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/kernel.h>
#include<linux/errno.h>
#include<linux/io.h>
#include<linux/interrupt.h>                                                 

#include<linux/sched.h>
#include<linux/list.h>
#include<linux/irq.h>
#include<linux/slab.h>
#include<linux/delay.h>
#include<linux/time.h> 
#include<linux/gpio.h>

#include<asm/uaccess.h>
#include<linux/string.h>


#define LED0 
#define LED1 
#define MY_MAJOR 
#define MY_MINOR  0
#define MY_DEV_COUNT 2
#define GPIO_ANY_GPIO_DEVICE_DESC    "myLED"

MODULE_LICENSE("GPL");                                                 
MODULE_AUTHOR("venkatarao");
MODULE_DESCRIPTION("A Led on device Driver module for RaspPi with out ethernet cable");

static char   *msg=NULL;
struct cdev my_cdev;


struct file_operations my_fops = {
        read    :       my_read,
        write   :       my_write,
        open    :       my_open,
        release :       my_close,
        owner   :       THIS_MODULE
};

static int led_init(void)
{

	dev_t devno;
	unsigned int count = MY_DEV_COUNT; 
	int err;

	devno = MKDEV(MY_MAJOR, MY_MINOR);
	register_chrdev_region(devno, count , "myLED");

	cdev_init(&my_cdev, &my_fops);
	my_cdev.owner = THIS_MODULE;

	err = cdev_add(&my_cdev, devno, count);                            

	if (err < 0)
	{
		printk("Device Add Error\n");
		return -1;
	}

	// -- print message 
	printk("<1> Hello World. This is myLED Driver.\n");
	printk("'mknod /dev/myLED0 c %d 0'.\n", MY_MAJOR);
	printk("'mknod /dev/myLED1 c %d 1'.\n", MY_MAJOR);

	// -- make 
	msg          = (char *)kmalloc(32, GFP_KERNEL);
	if (msg !=NULL)
		printk("malloc allocator address: 0x%p\n", msg);
	
	printk("***** LED GPIO Init ******************\n");
	if(gpio_is_valid(LED0) < 0){
		printk("gpio %d is valid error \n", LED0);
		return -1;
	}
	if(gpio_is_valid(LED1) < 0){
		printk("gpio %d is valid error \n", LED1);
		return -1;
	}
	if(gpio_request(LED0,"LED0_GPIO") < 0){
		printk("gpio %d is request error \n", LED0);
		return -1;
	}
	if(gpio_request(LED1,"LED1_GPIO") < 0){
		printk("gpio %d is request error \n", LED1);
		return -1;
	}
	gpio_direction_output(LED0, 0);
	gpio_direction_output(LED1, 0);

	gpio_set_value(LED0,1);
	gpio_set_value(LED1,1);
        return 0;
}


static void led_exit(void)
{
	dev_t devno;
        printk("<1> Goodbye\n");

	gpio_set_value(LED0,0);
	gpio_set_value(LED1,0);
	gpio_free(LED0);
	gpio_free(LED1);
	devno = MKDEV(MY_MAJOR, MY_MINOR);

	if (msg){
        /* release the malloc */
        kfree(msg);
	}

	unregister_chrdev_region(devno, MY_DEV_COUNT);
	cdev_del(&my_cdev);
}

module_init(led_init);
module_exit(led_exit);
