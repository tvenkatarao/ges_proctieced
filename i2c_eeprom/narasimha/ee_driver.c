#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/mutex.h>
#include <linux/sysfs.h>
#include <linux/mod_devicetable.h>
#include <linux/log2.h>
#include <linux/bitops.h>
#include <linux/jiffies.h>
#include <linux/of.h>
#include <linux/i2c.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>


MODULE_DESCRIPTION("eeprom Client Driver");
MODULE_AUTHOR("venkatarao");
MODULE_LICENSE("GPL");
MODULE_INFO(intree,"Y");
#define devname "eeprom"


struct eeprom_data {
	struct i2c_client *client;
	u8 *write_buff;
	u16 write_max;
	dev_t devt;
	struct cdev cdev;
	struct class *class;
};	

static ssize_t eeprom_read(struct file* file, char *buf, size_t count, loff_t *pos) 
{
	struct i2c_msg msg[2];
	char *tmp;
	char *buf2;
	struct eeprom_data *dev = (struct eeprom_data *)(file->private_data);
	struct i2c_adapter *adap = dev->client->adapter;
	int ret;
	printk(KERN_INFO "read started\n");
	if (count > 256)
	{
	printk("Error:reading the more than device size\n");
	return 0;
	
	}
	buf2 = kmalloc(1, GFP_KERNEL);
	if (buf2 == NULL)
	  return -ENOMEM;
	tmp = kmalloc(count, GFP_KERNEL);
	if (tmp == NULL)
	  return -ENOMEM;
	*buf2=0;

	msg[0].addr = 0x50; 
	msg[0].flags = 0x0000; 
	msg[0].len = 1;
	msg[0].buf = buf2;
	//printk("read started11111\n");
	msg[1].addr = 0x50; 
	msg[1].flags = 0x0001; 
	msg[1].len = count;
	msg[1].buf = tmp;
	//printk("Invoking Transfer\n");
	msleep(2);
	ret = i2c_transfer(adap, &msg, 2);
  
	if (ret < 0)
	{
	printk("Error: data read from device failed\n");
 
	}

	else	
	ret = copy_to_user(buf, tmp, count) ? -EFAULT : count;
	kfree(tmp);
	kfree(buf2);
	printk("\nread completed\n");	
	return ret;
}
static ssize_t eeprom_write(struct file* file, const char *buf, size_t count, loff_t *pos)
{
	struct eeprom_data *dev = (struct eeprom_data *)(file->private_data);
	struct i2c_adapter *adap = dev->client->adapter;
	char *tmp;
	struct i2c_msg msg;
	unsigned char buf2[9];
	int ret,cnt;
        int k=0x00,i;
	printk("write started\n");

        if (count > 256)
	{	
	printk("Error:no free space for writing lorge data\n");
	return 0;
	}
     	tmp = kmalloc(count, GFP_KERNEL);
	printk(" temp count  %d",count);  
     	if (tmp == NULL)
		return -ENOMEM;

	tmp = memdup_user(buf, count);
	
	printk(" user count  %d",count); 
	if (IS_ERR(tmp))
		return PTR_ERR(tmp);
	while(count>k){
		for(i=0;i<9;i++){
			if(i==0)
				*(buf2+i)=k;
			else{
				*(buf2+i)=*(tmp++);
				printk(KERN_INFO "%d\t",*(buf2+i));
			}
		}

	msg.addr = 0x50; 
	msg.flags = 0; 
	msg.len =9;
	msg.buf = buf2;

	msleep(1);
     	ret = i2c_transfer(adap, &msg,1); 
        if(ret<0)
        	printk("error: write tranfer 2222\n");
	k=k+8;
	}
 	kfree(tmp);
	printk("write completed\n");
	return (ret == 1 ? count : ret);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static int eeprom_open(struct inode *inode, struct file *file)
{
	struct eeprom_data *dev = container_of(inode->i_cdev, struct eeprom_data, cdev);
	if (dev == NULL) {
		printk("Error: open failed\n");
		return -1;
	}
	file->private_data = dev;

	return 0;
}

static int eeprom_close(struct inode *inode, struct file *file)
{
	return 0;
}

struct file_operations fops = {
	.open = eeprom_open,
	.release = eeprom_close,
	.read = eeprom_read,
	.write = eeprom_write,
};

static int eeprom_remove(struct i2c_client *client)
{
	printk("Remove started\n");
	struct eeprom_data *dev;
	dev = i2c_get_clientdata(client);
	cdev_del(&dev->cdev);
	device_destroy(dev->class, dev->devt);
	class_destroy(dev->class);
	unregister_chrdev_region(dev->devt, 1);
	printk("Remove completed\n");
	return 0;

}
static int eeprom_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	printk("Probe started\n");
	struct eeprom_data *data;
	int init_result;
	data = devm_kzalloc(&client->dev,sizeof(struct eeprom_data), GFP_KERNEL);
	data->write_max = 32;
	data->write_buff = devm_kzalloc(&client->dev, data->write_max, GFP_KERNEL);
	i2c_set_clientdata(client, data);
	init_result = alloc_chrdev_region(&data->devt, 0, 1, "eeprom");
	data->client = client;

	if( 0 > init_result )
	{
	printk(KERN_ERR "Error:Device Registration failed\n");
	return -1;
	}
	printk("Major Nr: %d\n", MAJOR(data->devt));

	if ((data->class = class_create(THIS_MODULE, "eeprom")) == NULL)
	{
	printk(KERN_ALERT "Error:class creat faileed\n");
	return -1;
	}
	if(device_create(data->class, NULL, data->devt, NULL, "eeprom") == NULL)
	{
	printk(KERN_ALERT "Error:device create faileed\n");
	return -1;
	}

	cdev_init(&data->cdev, &fops);

	if(cdev_add(&data->cdev, data->devt, 1) <0)
	{
	printk("Error:cdev add faileed\n");
	return -1;
	}

	printk("Probe completed\n");
	return 0;
}

static const struct i2c_device_id eeprom_ids[] = {
	//{ 0x50, 0},
	{ devname, 0},
	{ }
};
MODULE_DEVICE_TABLE(i2c, eeprom_ids);

static struct i2c_driver eeprom_driver = {
	.driver = {
		.name = "eeprom",
		.owner = THIS_MODULE,
	},
	.probe = eeprom_probe,
	.remove = eeprom_remove,
	.id_table = eeprom_ids,
};

static int __init eeprom_init(void)
{
return i2c_add_driver(&eeprom_driver);
}

static void __exit eeprom_exit(void)
{
i2c_del_driver(&eeprom_driver);
}

module_init(eeprom_init);
module_exit(eeprom_exit);



