/*
	 SPI ADC Client Driver , ADC(MCP3202)

	 Specification of Device
	 _______________________
	 PIN = 8
	 ADC input = 2 ( PIN = 7,8 )
	 Resolution = 12bit
	 Number of pin = 8
	 CS = low for select chip
	 Power supply = 5V
	 Dout = output for ADC
	 Din = input for ADC
	 _______________________
	 Driver Operation
	 _______________________
	 Read from ADC
	 Write command for chennel select

	 Auther : Kalsariya Ravindra Jivan Bhai

*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/ioctl.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/err.h>
#include <linux/list.h>
#include <linux/errno.h>
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/compat.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/cdev.h>
#include <linux/spi/spi.h>
#include <linux/spi/spidev.h>
#include <linux/uaccess.h>
#include <linux/interrupt.h>

#define FIRST_MINOR_NUM 11
#define NR_OF_DEVS 1

// Gpl License Mecro
MODULE_LICENSE("GPL");
MODULE_INFO(intree, "Y");


static dev_t mydev;
struct cdev *my_cdev;

// our Driver Name
char *devname="spi_adc";

// open function call
static int spidev_open(struct inode *inode, struct file *filep);

// read data from ADC
ssize_t spidev_read(struct file *, char __user *, size_t, loff_t *);

// release memory
static int spidev_Release (struct inode *in, struct file *fp);

// invoke when, doing insmod
static int spi_dev_init (void);

// exit invoke when doing rmmod
static void spi_dev_exit (void);


// file operation structure initializetion
struct file_operations fops = {

				.owner      = THIS_MODULE,
		    .open     	= spidev_open,
    		.release    = spidev_Release,
		    .read     	= spidev_read,

};

/*

struct spi_driver {
  const struct spi_device_id * id_table;
  int (* probe) (struct spi_device *spi);
  int (* remove) (struct spi_device *spi);
  void (* shutdown) (struct spi_device *spi);
  struct device_driver driver;
};

*/

/*
struct device_driver {
  const char * name;
  struct bus_type * bus;
  struct module * owner;
  const char * mod_name;
  bool suppress_bind_attrs;
  const struct of_device_id * of_match_table;
  int (* probe) (struct device *dev);
  int (* remove) (struct device *dev);
  void (* shutdown) (struct device *dev);
  int (* suspend) (struct device *dev, pm_message_t state);
  int (* resume) (struct device *dev);
  const struct attribute_group ** groups;
  const struct dev_pm_ops * pm;
  struct driver_private * p;
};*/

static struct class *mychar_class;
static struct device *mychar_device;
static struct spi_device *spi_prob_dev;

/*
 after registrer this function into file operation structure,
 when application call system call(open) than spidev_open invoke
*/
int spidev_open(struct inode *inode, struct file *filep)
{
	printk("muOpen is invoked\n");
	return 0;

}

/*
	 after registrer this function into file operation structure,
	 when application call system call(open) than spidev_open invoke
*/
int spidev_Release (struct inode *in, struct file *fp)
{
  printk (KERN_INFO "File released \n");
  return 0;
}
/*
	 after register our device name into DTS file,
	 using this function we can get to know that , our device is connected
	 SPI_device Structure reprasent our device
*/
static int spidev_probe(struct spi_device *dev)
{
	printk("probe function call..\n");
	printk("%s\n",dev->dev.init_name);

	spi_prob_dev = dev;

	printk("----> CHIP SELECT %d == \n"		,dev->chip_select);
	printk("----> BIT PER WORD %d == \n"	,dev-> bits_per_word);
	printk("----> SPI MODE %d == \n"			,dev-> mode);
	printk("----> IRQ %d == \n"						,dev-> irq);
	printk("----> SPI NAME %s == \n"			,dev->modalias);
	printk("----> CS GPIO NUMBER %d == \n",dev->cs_gpio);

	// for modefie structure members
//	spi_setup(dev);
  return 0;
}

/*
	 when application call read function that time READ will call
	 its only for reading data into ADC
*/
ssize_t spidev_read(struct file * fp, char __user * ch, size_t sz, loff_t * lf)
{


				/// Command for select ADC chennel and MODE and MSB first set.
				unsigned char cmd [3] = {0x01,0xA0,0x00};
				unsigned char buf [3] = {0x00,0x00,0x00};

				int i = 0,res;
				char *p = &i;

				/**
				 * struct spi_transfer - a read/write buffer pair
				 * @tx_buf: data to be written (dma-safe memory), or NULL
				 * @rx_buf: data to be read (dma-safe memory), or NULL
				 * @tx_dma: DMA address of tx_buf, if @spi_message.is_dma_mapped
				 * @rx_dma: DMA address of rx_buf, if @spi_message.is_dma_mapped
				 * @len: size of rx and tx buffers (in bytes)
				 * @speed_hz: Select a speed other than the device default for this
				 *      transfer. If 0 the default (from @spi_device) is used.
				 * @bits_per_word: select a bits_per_word other than the device default
				 *      for this transfer. If 0 the default (from @spi_device) is used.
				 * @cs_change: affects chipselect after this transfer completes
				 * @delay_usecs: microseconds to delay after this transfer before
				 *	(optionally) changing the chipselect status, then starting
				 *	the next transfer or completing this @spi_message.
				 * @transfer_list: transfers are sequenced through @spi_message.transfers
				 */

				struct spi_transfer t 	= {

								.tx_buf     		= cmd,
								.rx_buf     		= buf,
								.len        		= 3,
								.bits_per_word 	= 8,

				};

				/**
				 * struct spi_message - one multi-segment SPI transaction
				 * @transfers: list of transfer segments in this transaction
				 * @spi: SPI device to which the transaction is queued
				 * @is_dma_mapped: if true, the caller provided both dma and cpu virtual
				 *	addresses for each transfer buffer
				 * @complete: called to report transaction completions
				 * @context: the argument to complete() when it's called
				 * @actual_length: the total number of bytes that were transferred in all
				 *	successful segments
				 * @status: zero for success, else negative errno
				 * @queue: for use by whichever driver currently owns the message
				 * @state: for use by whichever driver currently owns the message
				 */

				struct spi_message  m;
				int final_Voltage;

				printk("spi_adc_called..\n");

				 /// Initialize message
				spi_message_init(&m);

				// make transfer into tail in message list.
				spi_message_add_tail(&t, &m);

				/*
				 * All these synchronous SPI transfer routines are utilities layered
				 * over the core async transfer primitive.  Here, "synchronous" means
				 * they will sleep uninterruptibly until the async transfer completes.
				 */
				// using spi_sync() function we can transfer data synchronoiusly
				if( spi_sync(spi_prob_dev, &m) == 0) {

								printk("sync is SUCSESS\n");

								/*
									 after reading we get out data into two different register
									 wee need to merge two different byte and make one singale word.
									 using single word we can get entire data , which is outpot of ADC
								*/
								*p = buf[2];
								++p;
								*p = buf[1];
								i = i & 0x000FFF;

								// Printing Final Result
								printk("final output num data -> %d \n", i);

								final_Voltage = (i * 5) / 4096;

								// copy result into Application or USer space
    		        res = copy_to_user(ch, &final_Voltage, sizeof(int));

								if(res == 0){

												printk("COPY_TO_USER ARE SUCSECCCC..\n");

								} else {

												printk("COPY_TO_USER ARE FAILLL..\n");
								}


				} else {
								printk("sync is FAIL.......\n");
				}
				return 0;
}



static int spidev_remove(struct spi_device *dev)
{
  printk("remove call function call..\n");
  return 0;
}

// Register Device name
static const struct of_device_id spi_adc_id[] = {
    { .compatible = "spi_adc",  },
    {}
};

// Update device table
MODULE_DEVICE_TABLE(of, spi_adc_id);


/**
 * struct spi_driver - Host side "protocol" driver
 * @id_table: List of SPI devices supported by this driver
 * @probe: Binds this driver to the spi device.  Drivers can verify
 *	that the device is actually present, and may need to configure
 *	characteristics (such as bits_per_word) which weren't needed for
 *	the initial configuration done during system setup.
 * @remove: Unbinds this driver from the spi device
 * @shutdown: Standard shutdown callback used during system state
 *	transitions such as powerdown/halt and kexec
 * @driver: SPI device drivers should initialize the name and owner
 *	field of this structure.
 */


/*
	 spi_driver struct reprasent our actual driver
	 once our driver load into kernal, using device tree entry
	 kernal get to know that device is connected
	 after prob function will call
*/
static struct spi_driver spidev_driver = {

	.driver = {

				 	.owner = THIS_MODULE,
			  	.name = "spi_adc",
					.of_match_table = of_match_ptr(spi_adc_id),

	   	},

				.probe = spidev_probe,
		   	.remove = spidev_remove,
};

// invoke when driver is insert into kernal.
static int __init spi_dev_init(void)
{

				int ret = -ENODEV;
				int status;

				struct task_struct *get_pid1;
				get_pid1 = current;
				printk( "current pid :%d\n",get_pid1 ->pid);

				// Allocation Device Numbers
				status = alloc_chrdev_region( &mydev, FIRST_MINOR_NUM, NR_OF_DEVS, devname);
				if(status < 0) {
								printk(KERN_NOTICE "Device number allocation failed: %d \n", status);
								goto err;
				} else {
								printk(KERN_NOTICE "Device number allocation SUCSESS");
				}

				printk(KERN_INFO "Major number allocated = %d \n", MAJOR(mydev));
				printk(KERN_INFO "Minor number allocated = %d \n", MINOR(mydev));

				// Allocate Memory for my_cdev
				my_cdev = cdev_alloc();
				if(my_cdev == NULL) {
								printk(KERN_ERR "cdev_alloc failed \n");
								goto err_cdev_alloc;
				} else {
								printk(KERN_ERR "cdev_alloc SUCSESS \n");
				}

				// Initialize my_cdev with fops
				cdev_init(my_cdev, &fops);
				my_cdev->owner = THIS_MODULE;

				// Add my_cdev to the list
				status = cdev_add(my_cdev, mydev, NR_OF_DEVS);
				if(status) {
								printk(KERN_ERR "cdev_add failed \n");
								goto err_cdev_add;
				} else {
								printk(KERN_ERR "cdev_add SUCSESS");
				}

				//Creating a class and an entry in sysfs
				mychar_class = class_create(THIS_MODULE, devname);
				if(IS_ERR(mychar_class)) {
								printk(KERN_ERR "class_create() failed....... \n");
								goto err_class_create;
				} else {
								printk(KERN_ERR "class_create() SUCSESS........\n");
				}

				//create mychar_device in sysfs and an
				//device entry will be made in /dev directory
				mychar_device = device_create(mychar_class, NULL, mydev, NULL, devname);

				if(IS_ERR(mychar_device)) {
								printk(KERN_ERR "device_create() failed \n");
								goto err_device_create;
				} else {
								printk(KERN_ERR "device_create() SUCSESS");
				}

				// Register driver
				if (0 != (ret = spi_register_driver(&spidev_driver))) {
								goto err_device_create;
				} else {
								printk(KERN_ERR "spi_register_driver() SUCSESS");
				}


				return 0;

err_device_create:
				class_destroy(mychar_class);

err_class_create:
				cdev_del(my_cdev);

err_cdev_add:
				kfree(my_cdev);

err_cdev_alloc:
				unregister_chrdev_region(mydev, NR_OF_DEVS);

err:
				return ret;

}

// invoke when we remove driver into kernal
static void spi_dev_exit (void)
{

				// unregistere driver
				spi_unregister_driver(&spidev_driver);
				printk(KERN_INFO "Exiting the Character Driver \n");
				device_destroy(mychar_class, mydev);
				class_destroy(mychar_class);
				cdev_del(my_cdev);
				unregister_chrdev_region(mydev, NR_OF_DEVS);

				return;
}

module_init (spi_dev_init);
module_exit (spi_dev_exit);
