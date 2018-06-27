/*
 *	i2c_rtc.c - RTC client driver for DS1307.
 *	
 *	Specifications of device:                                                   
 *      Device type      : RTC uses I2C bus                                     
 *      Device Name      : DS1307                                               
 *      I2C address      : 0x68                                                 
 *      Register address : SECOND	=	0x00H  ,	MIN 	 = 	0x01H,
 * 						   HOUR		=   0x02h  ,	WEEKDAYS = 	0x03H,
 *						   DATE		=	0x04h  ,    MONTH 	 =	0x05h,
 *						   YEAR		=	0x06h
 *                                                                              
 *   Driver Operations :                                                        
 *         i)  Read time, day and date                                               
 *        ii)  Write time, day  & date                                                
 */

#include <asm/uaccess.h>
#include <linux/cdev.h>
#include <linux/bcd.h>
#include <linux/i2c.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/slab.h>


#define FIRST_MINOR		10
#define NR_DEVS			1 	/* Number of device numbers */
#define N_REGISTER 		7
#define START_REG_IDX	8	
#define END_REG_IDX		9
/*
 *	RTC DS1307 Registers MACROS
 */

#define RTC_SECONDS_REG       0X00
#define RTC_MINUTES_REG       0x01
#define RTC_HOURS_REG         0x02
#define RTC_WDAY_REG          0x03
#define RTC_MDAY_REG          0x04
#define RTC_MONTH_REG         0x05
#define RTC_YEAR_REG          0x06
#define RTC_CONTROL_REG       0x07



struct time {
	unsigned char second;
	unsigned char minute;
	unsigned char hour;
	unsigned char day;
	unsigned char date;
	unsigned char month;
	unsigned char year;
};


/*
 *	struct i2c_rtc_device - Represent the rtc device 
 *	@client: Represent the pointer to struct i2c_client 
 *	@time_buff: Array of time register
 *	@rtc_address: Address of rtc ds1307
 *	@rtc_time: Object of struct time
 */

struct i2c_rtc_device {
	struct i2c_client 	*client;
	unsigned int	time_buff[8];
	unsigned int	rtc_address;
	struct time 	rtc_time;
}i2c_rtc_device;


/*
 * int myInit (void) : init() function called during insmod.
 * void myExit (void) : exit() function called during rmmod.
 */
static int myInit (void);
static void myExit (void);


/*
 * int myOpen (struct inode *, struct file *) : open() function.
 *
 * int myRelease (struct inode *,struct file *) : close() function.
 */
int myOpen (struct inode *,struct file *);
int myRelease (struct inode *,struct file *);


/*
 *  int i2c_rtc_setup (void) : initialise the rtc registers.
 *
 *  unsigned char i2c_rtc_get_reg (unsigned char *, unsigned char, 
 *	unsigned char) :  get the status of registers in char*.
 *
 *	Return 0 on success.
 */
static int i2c_rtc_setup (void);
static unsigned char i2c_rtc_get_reg (unsigned char * buff, unsigned char addr,
									unsigned char len);

/*
 *	int i2c_rtc_probe (struct i2c_client *, const struct i2c_device_id*):
 *	probe() function invoked when a platform device is registered and it's 
 *	device name matches the name specified on the device driver.            
 *
 *	int i2c_rtc_remove (struct i2c_client *) : remove() function opposite of 
 *	probe function.
*/
static int i2c_rtc_remove (struct i2c_client *);
static int i2c_rtc_probe (struct i2c_client *, const struct i2c_device_id *);



/*
 *	ssize_t myread (struct file *, char __user *, size_t , loff_t *) : read()
 *	function.
 *
 *	ssize_t mywrite (struct file *, const char __user *, size_t, loff_t *):
 *	write funciton.
 *
 *	Return 0 on success or -1 on failure.
*/
ssize_t myread (struct file *, char __user *, size_t , loff_t *);
ssize_t mywrite (struct file *, const char __user *, size_t, loff_t *);

char *devname = "i2c_rtc";
int majNo;
static dev_t mydev;
struct cdev *my_cdev;

static struct class *mychar_class;
static struct device *mychar_device;


/*
 * Initializing the file pointers in struct file_operations
 */
struct file_operations fops = {
		.owner			=	THIS_MODULE,
		.open			=	myOpen,
		.release		=	myRelease,
		.read			= 	myread,
		.write			=	mywrite
};

static const struct i2c_device_id i2c_rtc_id[] = {
		{ "i2c_rtc", 0 },
		{}
};

MODULE_DEVICE_TABLE (i2c, i2c_rtc_id);


/* Structure of the drive  */ 
static struct i2c_driver rtc_client_driver =  {
	.driver = {
		.name = "i2c_rtc",
	},
	.probe   = i2c_rtc_probe,
	.remove  = i2c_rtc_remove,
	.id_table = i2c_rtc_id
};



int myOpen (struct inode *inode, struct file *filep)
{	
	int i = 0;
	printk (KERN_INFO "Open successful\n");
	for (i = 1; i <= 8; i++ )
		printk ("time_buff = %u\n",i2c_rtc_device.time_buff[i]);


	printk ("\nrtc_address = %u\n",i2c_rtc_device.rtc_address);

	printk ("\nseconds = %d\n", i2c_rtc_device.rtc_time.second);
	printk ("minute = %d\n",i2c_rtc_device.rtc_time.minute);
	printk ("hour = %d\n", i2c_rtc_device.rtc_time.hour);
	printk ("day = %d\n", i2c_rtc_device.rtc_time.day);
	printk ("date = %d\n", i2c_rtc_device.rtc_time.date);
	printk ("month = %d\n", i2c_rtc_device.rtc_time.month);
	printk ("year = %d\n", i2c_rtc_device.rtc_time.year);

	return 0;
}


int myRelease (struct inode *in, struct file *fp)
{
	printk (KERN_INFO "File released \n");
	return 0;
} 

ssize_t myread (struct file *filp, char __user *buf, size_t count, 
				loff_t *f_pos)
{
		/* RTC register buffer */

		static unsigned char buff[N_REGISTER];                        
		char *day[] 	= 	{
								" "			, 	"Sunday"	,	"Monday", 	
								"Tuesday"	,	"Wednesday" , 	"Thursday",	
								"Friday" 	,	"Saturday"	
							};

		char *month[]  =	{
								" "	 	, 	"Jan" 	, "Feb"		, "March",
								"Apr" 	, 	"May"	, "June" 	, "July" , 	
								"Aug"	, 	"Sep"  	, "Oct" 	, "Nov"	 , 
								"Dec"
							};

		char *time[]  =		{ "AM", "PM"};

		if (0 != i2c_rtc_get_reg (buff, N_REGISTER, RTC_SECONDS_REG)) {
				printk (KERN_ERR "i2c_rtc_get_reg() failed\n");
				return -1;
		}

		printk ("*******************rtc time**************************\n");

		printk ("time_date: %s %s %02d 20%02d %02d:%02d:%02d %s\n",
						day[i2c_rtc_device.rtc_time.day],
						month[i2c_rtc_device.rtc_time.month],
						i2c_rtc_device.rtc_time.date,
						i2c_rtc_device.rtc_time.year, 
						i2c_rtc_device.rtc_time.hour,
						i2c_rtc_device.rtc_time.minute,
						i2c_rtc_device.rtc_time.second,
						time [((buff[RTC_HOURS_REG] >> 5) & 1)]);

		printk ("****************************************************\n");

		/* Read the time */
		i2c_rtc_device.rtc_time.second  	= 	bcd2bin (buff[RTC_SECONDS_REG] 
												& 0x7F);
		i2c_rtc_device.rtc_time.minute		= 	bcd2bin (buff[RTC_MINUTES_REG]
												& 0x7F); 
		i2c_rtc_device.rtc_time.hour 		= 	bcd2bin (buff[RTC_HOURS_REG] 
												& (~(-(1 << 5 ))));
		i2c_rtc_device.rtc_time.day		  	= 	bcd2bin (buff[RTC_WDAY_REG]
												& (~(-(1 << 3))));
		i2c_rtc_device.rtc_time.date 		= 	bcd2bin (buff[RTC_MDAY_REG] 
												& 0x3F);
		i2c_rtc_device.rtc_time.month 		= 	bcd2bin (buff[RTC_MONTH_REG] 
												& 0x1F);
		i2c_rtc_device.rtc_time.year		= 	bcd2bin (buff[RTC_YEAR_REG]);

		printk ("*******************rtc time**************************\n");

		printk ("time_date: %s %s %02d 20%02d %02d:%02d:%02d %s\n",
						day[i2c_rtc_device.rtc_time.day],
						month[i2c_rtc_device.rtc_time.month],
						i2c_rtc_device.rtc_time.date,
						i2c_rtc_device.rtc_time.year, 
						i2c_rtc_device.rtc_time.hour,
						i2c_rtc_device.rtc_time.minute,
						i2c_rtc_device.rtc_time.second,
						time [((buff[RTC_HOURS_REG] >> 5) & 1)]);

		printk ("****************************************************\n");
		return 0;
}


ssize_t mywrite (struct file *filp, const char __user *buf, size_t count, 
				loff_t *f_pos)
{
	struct i2c_msg i2c_rtc_msg;
	static unsigned char bcd_buff[8];

	int i ;
	int ret;

	if (0 != i2c_rtc_get_reg (bcd_buff + 1, N_REGISTER, RTC_SECONDS_REG)) {
		printk (KERN_ERR "i2c_rtc_get_reg() failed\n");
		return -1;
	}
	

	bcd_buff[0] = buf [0];

	for (i = buf[START_REG_IDX] ; i <= buf[END_REG_IDX]; i++)
		bcd_buff[i] = bin2bcd (buf[i]);

	i2c_rtc_msg.addr		= 	i2c_rtc_device.rtc_address;
	i2c_rtc_msg.flags 		= 	0;
	i2c_rtc_msg.len			= 	8;
	i2c_rtc_msg.buf			= 	bcd_buff;
		
	if ((ret = (i2c_transfer (((i2c_rtc_device.client) -> adapter), 
				&i2c_rtc_msg, 1))) < 0) {                 
		printk (KERN_ERR "i2c_test: i2c_transfer failed = %d\n", ret);          
		return ret;
	}   
	return 0;
}

static unsigned char i2c_rtc_get_reg (unsigned char *buff, unsigned char len,
										unsigned char addr)
{
		int ret;
		struct i2c_msg i2c_rtc_msg[] = {                                        
				/*                                                                      
				 * Writing register address information to the RTC                      
				 */                                                                     
				{                                                               
						.addr       = i2c_rtc_device.rtc_address,                   
						.flags      = 0,                                            
						.buf        = &addr,                                      
						.len        = 1                                             
				},                                                              
				/*                                                                      
				 * Read current time by getting 'len' bytes of data from 
				 * address 'addr'.           
				 */                                                                     
				{                                                               
						.addr       = i2c_rtc_device.rtc_address, /* Slave address */
						.flags      = I2C_M_RD, /* Read command */                  
						.buf        = buff,                                         
						.len        = len                                        
				}                                                               
		};

		/* Generate bus transactions corresponding to the above                 
		   two messages */                                                      
		if ((ret = (i2c_transfer (((i2c_rtc_device.client) -> adapter),         
												i2c_rtc_msg, 2))) < 0){                                     
				printk (KERN_ERR "i2c_test: i2c_transfer failed = %d\n", ret);
				return ret;
		}         
	
	return 0;
}	

static int i2c_rtc_setup (void)
{
	int ret;
	unsigned char buff[9];
	struct i2c_msg i2c_rtc_msg;

	printk (KERN_INFO "entering in the i2c_rtc_setup()\n");

	if (0 != i2c_rtc_get_reg (buff + 1, N_REGISTER, RTC_SECONDS_REG)) {
			printk (KERN_ERR "i2c_rtc_get_reg() failed\n");
			return -1;
	}


	/*	Setting the appropiate bits in RTC registers  */
	buff[RTC_SECONDS_REG ] 		 =  RTC_SECONDS_REG;
	buff[RTC_SECONDS_REG + 1] 	&=  0x7F;
	buff[RTC_MINUTES_REG + 1] 	&=  0x7F;
	buff[RTC_HOURS_REG	 + 1] 	|=  0x40;
	buff[RTC_WDAY_REG	 + 1] 	&=  0x07;
	buff[RTC_MDAY_REG	 + 1] 	&=  0x3F;
	buff[RTC_MONTH_REG	 + 1] 	&=	0x1F;
	buff[RTC_YEAR_REG	 + 1] 	&=  0xFF;
	buff[RTC_CONTROL_REG + 1] 	=   0x10;


	i2c_rtc_msg.addr        =   i2c_rtc_device.rtc_address;                     
	i2c_rtc_msg.flags       =   0;                                              
	i2c_rtc_msg.len         =   9;                                              
	i2c_rtc_msg.buf         =   buff;  

	if ((ret = (i2c_transfer (((i2c_rtc_device.client) -> adapter), 
				&i2c_rtc_msg, 1))) < 0) {                 
		printk (KERN_ERR "i2c_test: i2c_transfer failed = %d\n", ret);          
		return ret;
	}

	printk (KERN_INFO "exiting in the i2c_rtc_setup()\n");
	
	return 0;
}

static int i2c_rtc_probe(struct i2c_client *client,	const struct 
						i2c_device_id *id)
{
	printk (KERN_INFO "probe function called\n");
	
	printk ("client name = %s\n", client -> name);
	i2c_rtc_device.client 	= 	client;
	
	printk ("client address = %x\n", client -> addr);
	i2c_rtc_device.rtc_address = client -> addr;

	/* Check if adapter support the capabilty of  i2c functionality */
	if (!i2c_check_functionality (client -> adapter, I2C_FUNC_I2C)) {           
			printk (KERN_ERR "i2c_check_functionality failed");
			return -1;
	}  
		
	/* set up the rtc function is called if success return 0*/
	if (i2c_rtc_setup ()) {
		printk (KERN_ERR "i2c_rtc_setup failed\n");
		return -1;
	}

	printk (KERN_INFO "probe function exiting\n");
	
	return 0;
}

static int i2c_rtc_remove (struct i2c_client *client)
{
	printk (KERN_INFO "remove function called\n");
	return 0;
}

static int __init myInit (void)
{
	int ret	=	-ENODEV;
	int status;

	printk (KERN_INFO "Initializing Character Device \n");

	status	=	alloc_chrdev_region (&mydev, FIRST_MINOR, NR_DEVS, devname);

	if (status < 0)
	{
		printk (KERN_NOTICE "Device numbers allocation failed: %d \n",status);
		goto err;
	}

	printk (KERN_INFO "Major number allocated = %d \n",MAJOR(mydev));
	my_cdev	=	cdev_alloc ();

	if (my_cdev == NULL) {
		printk (KERN_ERR "cdev_alloc failed \n");
		goto err_cdev_alloc;
	}

	cdev_init (my_cdev, &fops);
	my_cdev->owner	=	THIS_MODULE;

	status	=	cdev_add (my_cdev, mydev, NR_DEVS);
	if (status) {
		printk (KERN_ERR "cdev_add failed \n");
		goto err_cdev_add;
	}

	mychar_class	=	class_create (THIS_MODULE, devname);
	if (IS_ERR(mychar_class)) {
		printk (KERN_ERR "class_create() failed \n");
		goto err_class_create;
	}

	mychar_device =	device_create (mychar_class, NULL, mydev, NULL, devname);
	if (IS_ERR(mychar_device)) {
		printk (KERN_ERR "device_create() failed \n");
		goto err_device_create;
	}

	status = i2c_add_driver (&rtc_client_driver);
	if (status) {
		printk (KERN_ERR "i2c_add_driver() failed\n");
		goto err_i2c_add_driver;
	}

	printk (KERN_INFO "Driver added successfully\n");
	return 0;

err_i2c_add_driver:
	device_destroy (mychar_class, mydev);

err_device_create:
	class_destroy (mychar_class);

err_class_create:
	cdev_del(my_cdev);

err_cdev_add:
	kfree (my_cdev);

err_cdev_alloc:
	unregister_chrdev_region (mydev, NR_DEVS);

err:
	return ret;
}


static void myExit (void)
{
	printk (KERN_INFO "Exiting the Character Driver \n");
	i2c_del_driver (&rtc_client_driver);
	device_destroy (mychar_class, mydev);
	class_destroy (mychar_class);
	cdev_del (my_cdev);
	unregister_chrdev_region (mydev, NR_DEVS);

	return;
}

module_init (myInit);
module_exit (myExit);

MODULE_LICENSE ("Dual BSD/GPL");
MODULE_AUTHOR("MOHANA"); 

