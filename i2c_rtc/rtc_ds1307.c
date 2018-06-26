#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/i2c.h>
#include<linux/slab.h>
MODULE_INFO(intree,"Y");
struct my_str{

	struct i2c_client *client;
	struct rtc_device *rtc;
	char *regs;
	char buf[10];
};

struct my_str *data ;
ssize_t device_file_read (struct  file *fp, char *buf, size_t count, loff_t *offset){
	printk("I'm in read function\n");
	return 0;
}
static struct file_operations rtc_driver_fops = 
{
	.owner   = THIS_MODULE,
	.read    = device_file_read,
};
static int device_file_major_number = 0;
static const char device_name[] = "eeprom";

static int rtc_probe(struct i2c_client *client, const struct i2c_device_id *id){
	int result =0;
	
	printk("I'm in probe function\n");
	result = register_chrdev( 0, device_name, &rtc_driver_fops );
		if( result < 0 )
		{
			printk( KERN_WARNING "rtc-driver: errorcode = %d\n", result );
			return result;
		}	
	device_file_major_number = result;
		printk( KERN_NOTICE "%d Major number\n" , device_file_major_number );
	
	if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA |
				     I2C_FUNC_SMBUS_WORD_DATA)){
		printk("i2c Checking error:\n");
	}
	
	
	if (!(data= kmalloc(sizeof(struct my_str), GFP_KERNEL))) {
		return -ENOMEM;
	}
	/* we read registers 0x0f then 0x00-0x0f; skip the first one */
	data->regs = &data->buf[1];

	struct my_str	*data = (struct my_str *)client;
	struct i2c_msg		msgs[] = {
		{ client->addr, I2C_M_RD, sizeof data->buf, data->buf },
	};
	
	if ((i2c_transfer(client->adapter, msgs, 1)) != 1) {
			dev_warn(&client->dev, "can't read registers\n");
			return -EIO;
	}
	printk(KERN_INFO "%02x %02x %02x (%02x) %02x %02x %02x (%02x)",	data->regs[0],  data->regs[1],  data->regs[2],  data->regs[3],
		data->regs[4],  data->regs[5],  data->regs[6],  data->regs[7]);
	

	return 0;
}
static int rtc_remove (struct i2c_client*client){

	
	printk( "rtc-driver: unregister_device() is called" );
	if(device_file_major_number != 0)
	{
		unregister_chrdev(device_file_major_number, device_name);
	}
	return 0;
}
static const struct i2c_device_id rtc_id[]={
	{"eeprom",0},
	{},
};
MODULE_DEVICE_TABLE(i2c,rtc_id);
static struct i2c_driver rtc_driver= {
	.driver = {
		.name = "eeprom",
		.owner = THIS_MODULE,
		},
	.probe = rtc_probe,
	.remove = rtc_remove,
};

static int __init rtc_fun(void){
	printk("I'm in initialization\n");
	if(i2c_add_driver(&rtc_driver)<0){
		printk("error:");
		return -1;
	}
	
	printk("completed ini\n");
	return 0;
}
void __exit rtc_exit(void){
	printk("I'm in exit \n");
	 i2c_del_driver(&rtc_driver);
}

module_init(rtc_fun);
module_exit(rtc_exit);

MODULE_LICENSE("GPL");
