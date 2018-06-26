#include <linux/input.h>
#include <linux/input/mt.h>
#include <linux/dma-mapping.h>
#include <linux/module.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <linux/slab.h>
#include <linux/stddef.h>
#include <asm/io.h>
#include <linux/platform_device.h>
#include <linux/bitops.h>
#include <soc/bcm2835/raspberrypi-firmware.h>

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/mutex.h>
#include <linux/sysfs.h>
#include <linux/mod_devicetable.h>
#include <linux/log2.h>
#include <linux/jiffies.h>
#include <linux/of.h>
#include <linux/i2c.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/kobject.h>
#include <linux/proc_fs.h>
#include <linux/ioctl.h>
#include <linux/mm.h>  

#include <linux/input-polldev.h> 
#include <linux/io.h>

#define MAX_POINTS 5
#define SCR_WIDTH 800
#define SCR_HEIGHT 480
#define FTS_TOUCH_CONTACT 2
#define FTS_TOUCH_UP 1
#define FTS_TOUCH_DOWN 0

MODULE_DESCRIPTION("The FT5406 touch screen driver on Raspberry pi");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Tatikonda Venkata Rao");
MODULE_INFO(intree,"Y");

struct my_device
{
	struct platform_device *p_dev;
	struct input_dev *input_dev;
	void __iomem *ts_base;
	dma_addr_t bus_addr;
	struct task_struct *thread;
};

struct dev_regis
{
	uint8_t device_mode;
	uint8_t gesture_id;
	uint8_t num_points;
	struct dev_touch
	{
		uint8_t xh;
		uint8_t xl;
		uint8_t yh;
		uint8_t yl;
		uint8_t res1;
		uint8_t res2;
	} point[MAX_POINTS];

};



static int my_thread(void *data)
{
	struct my_device *ts = (struct ft5406 *) data;
	
	struct dev_regis regs;
	int known_ids = 0;

	while(!kthread_should_stop())
	{
		int i, modified_ids = 0, released_ids;

		dev_info(&ts->p_dev->dev, "VV: thread fun in device ft5406\n");
		msleep_interruptible(9);
		memcpy_fromio(&regs, ts->ts_base, sizeof(struct dev_regis));
		iowrite8(99, ts->ts_base + offsetof(struct dev_regis, num_points));

		if (regs.num_points == 99)
		continue;
		dev_info(&ts->p_dev->dev, "V: thread fun in device ft5406\n");
	
		//if (regs.num_points == 0 && known_ids == 0)
		if (known_ids == 0)
		continue;
		dev_info(&ts->p_dev->dev, "V: thread fun in device ft5406\n");

		for (i = 0; i < regs.num_points; i++) 
		{
			int x, y, touchid;
			x = (((int) regs.point[i].xh & 0xf) << 8) + regs.point[i].xl;
			y = (((int) regs.point[i].yh & 0xf) << 8) + regs.point[i].yl;
			touchid = (regs.point[i].yh >> 4) & 0xf;
			int event_id = (regs.point[i].xh >> 6) & 0x3;

			modified_ids |= 1 << touchid;
			if (event_id == FTS_TOUCH_CONTACT || event_id == FTS_TOUCH_DOWN) 
			{


				input_mt_slot(ts->input_dev, touchid);
				input_mt_report_slot_state(ts->input_dev, MT_TOOL_FINGER, 1);

				input_report_abs(ts->input_dev, ABS_MT_POSITION_X, x);
				input_report_abs(ts->input_dev, ABS_MT_POSITION_Y, y);
			}		
		}
		dev_info(&ts->p_dev->dev, "V: thread fun in device ft5406\n");
		released_ids = known_ids & ~modified_ids;
		for (i = 0; released_ids && i < MAX_POINTS; i++)
 		{
			if (released_ids & (1<<i))
 			{
				dev_dbg(&ts->p_dev->dev, "Released %d, known = %x modified = %x\n", i, known_ids, modified_ids);
				input_mt_slot(ts->input_dev, i);
				input_mt_report_slot_state(ts->input_dev, MT_TOOL_FINGER, 0);
				modified_ids &= ~(1 << i);
			}
		}
		known_ids = modified_ids;

		input_mt_report_pointer_emulation(ts->input_dev, true);
		input_sync(ts->input_dev);
		dev_info(&ts->p_dev->dev, "V: Thread func of device ft5406\n");
	}
	return 0;
}

static int my_probe(struct platform_device *pdev)
{  
		
	struct device *dev = &pdev->dev;
	struct device_node *np = dev->of_node;
	struct my_device *ts;
	struct device_node *fw_node;
	struct rpi_firmware *fw;
	u32 touchbuf;
	int ret=0;
	dev_info(dev, "V:Probing device ft5406\n");


	if(!(ts = devm_kzalloc(dev, sizeof(struct my_device), GFP_KERNEL) ))
	{
		dev_err(dev, "ERRPR:memory alloction for ts failed \n");
		return -ENOMEM;
	}


	ts->ts_base = dma_zalloc_coherent(dev, PAGE_SIZE, &ts->bus_addr, GFP_KERNEL);
	if (!ts->ts_base) 
	{
		pr_err("[%s]: failed to dma_alloc_coherent(%ld)\n",
				__func__, PAGE_SIZE);
		ret = -ENOMEM;
	
	}
	touchbuf = (u32)ts->bus_addr;
	fw_node = of_parse_phandle(np, "firmware", 0);
	if (!fw_node) 
	{
		dev_err(dev, "ERROR: Missing firmware node\n");
		return -ENOENT;
	}

	fw = rpi_firmware_get(fw_node);
	if (!fw)
		return -EPROBE_DEFER;

	ret = rpi_firmware_property(fw, RPI_FIRMWARE_FRAMEBUFFER_SET_TOUCHBUF, &touchbuf, sizeof(touchbuf));

	if (ret || touchbuf != 0)
 	{
		dev_warn(dev, "ERROR:Failed to set touchbuf, trying to get err:%x\n",ret);
		dma_free_coherent(dev, PAGE_SIZE, ts->ts_base, ts->bus_addr);
		ts->ts_base = 0;
		ts->bus_addr = 0;
	}

	if (!ts->ts_base)
	{
		dev_warn(dev, "set failed, trying get (err:%d touchbuf:%x virt:%p bus:%x)\n", ret, touchbuf, ts->ts_base, ts->bus_addr);

		ret = rpi_firmware_property(fw, RPI_FIRMWARE_FRAMEBUFFER_GET_TOUCHBUF,
				    &touchbuf, sizeof(touchbuf));
		if (ret)	
		{
			dev_err(dev, "ERROR: Failed to get touch buffer\n");
			if (ts->bus_addr) 
			{
				dma_free_coherent(dev, PAGE_SIZE, ts->ts_base, ts->bus_addr);
				ts->bus_addr = 0;
				ts->ts_base = NULL;
			} 
			else if (ts->ts_base) 
			{
				iounmap(ts->ts_base);
				ts->ts_base = NULL;
			}
			
			return ret;
		}

		if (!touchbuf) 
		{
			dev_err(dev, "ERROR: Failed to detecting  Touchscreen\n");
			ret = -ENODEV;
			if (ts->bus_addr) 
			{
				dma_free_coherent(dev, PAGE_SIZE, ts->ts_base, ts->bus_addr);
				ts->bus_addr = 0;
				ts->ts_base = NULL;
			} 
			else if (ts->ts_base) 
			{
				iounmap(ts->ts_base);
				ts->ts_base = NULL;
			}
			
			return ret;
		}

		

		touchbuf &= ~0xc0000000;
		ts->ts_base = ioremap(touchbuf, sizeof(struct dev_regis));
		if (ts->ts_base == NULL)
		{
			dev_err(dev, "ERROR: Failed to mapping physical address\n");
			ret = -ENOMEM;
			if (ts->bus_addr) 
			{
				dma_free_coherent(dev, PAGE_SIZE, ts->ts_base, ts->bus_addr);
				ts->bus_addr = 0;
				ts->ts_base = NULL;
			} 
			else if (ts->ts_base) 
			{
				iounmap(ts->ts_base);
				ts->ts_base = NULL;
			}
			return ret;
		}
	}


	if(!( ts->input_dev = input_allocate_device() ))
	{
		pr_err("[%s]: failed to dma_alloc_coherent(%ld)\n", __func__, PAGE_SIZE);
		ret = -ENOMEM;
		if (ts->bus_addr) 
		{
			dma_free_coherent(dev, PAGE_SIZE, ts->ts_base, ts->bus_addr);
			ts->bus_addr = 0;
			ts->ts_base = NULL;
		} 
		else if (ts->ts_base) 
		{
			iounmap(ts->ts_base);
			ts->ts_base = NULL;
		}
		return ret;
		
	}
	platform_set_drvdata(pdev, ts);
	ts->p_dev = pdev;
	
	ts->input_dev->name = "FT5406 touch driver";
	
	__set_bit(EV_KEY, ts->input_dev->evbit);
	__set_bit(EV_SYN, ts->input_dev->evbit);
	__set_bit(EV_ABS, ts->input_dev->evbit);

	input_set_abs_params(ts->input_dev, ABS_MT_POSITION_X, 0, SCR_WIDTH, 0, 0);
	input_set_abs_params(ts->input_dev, ABS_MT_POSITION_Y, 0, SCR_HEIGHT, 0, 0);

	input_mt_init_slots(ts->input_dev, MAX_POINTS, INPUT_MT_DIRECT);

	input_set_drvdata(ts->input_dev, ts);

	if(input_register_device(ts->input_dev) )
	{
		dev_err(dev, "ERROR: Failed to register input device, %d\n", ret);
		if (ts->bus_addr) 
		{
			dma_free_coherent(dev, PAGE_SIZE, ts->ts_base, ts->bus_addr);
			ts->bus_addr = 0;
			ts->ts_base = NULL;
		} 
		else if (ts->ts_base) 
		{
			iounmap(ts->ts_base);
			ts->ts_base = NULL;
		}
		if (ts->input_dev)
		{
			input_unregister_device(ts->input_dev);
		ts->input_dev = NULL;
		}
		return ret;
	}


	dev_info(dev, "V: Probe climax in device ft5406\n");
	ts->thread = kthread_run(my_thread, ts, "my_touch");
	if(ts->thread == NULL)
	{
		dev_err(dev, "ERROR: Failed to create kernel thread");
		ret = -ENOMEM;
		if (ts->bus_addr) 
		{
			dma_free_coherent(dev, PAGE_SIZE, ts->ts_base, ts->bus_addr);
			ts->bus_addr = 0;
			ts->ts_base = NULL;
		} 
		else if (ts->ts_base) 
		{
			iounmap(ts->ts_base);
			ts->ts_base = NULL;
		}
		if (ts->input_dev)
		{
			input_unregister_device(ts->input_dev);
			ts->input_dev = NULL;
		}
		return ret;
	
	}
	return 0;
}

static int my_remove(struct platform_device *pdev)
{
	 
	struct device *dev = &pdev->dev;
	struct my_device *ts = (struct my_device *) platform_get_drvdata(pdev);
	dev_info(dev, "V:Removing device ft5406\n");
	kthread_stop(ts->thread);

	if (ts->bus_addr) {
		dma_free_coherent(dev, PAGE_SIZE, ts->ts_base, ts->bus_addr);
		ts->bus_addr = 0;
		ts->ts_base = NULL;
	} else if (ts->ts_base) {
		iounmap(ts->ts_base);
		ts->ts_base = NULL;
	}
	if (ts->input_dev) {
		input_unregister_device(ts->input_dev);
		ts->input_dev = NULL;
	}
	return 0;
}


static const struct of_device_id my_match[] = {
	{ .compatible = "rpi,rpi-ft5406", },
	{},
};
MODULE_DEVICE_TABLE( , my_match);



static struct platform_driver my_touch_driver = {
	.driver = {
		.name   = "rpi-ft5406",
		.owner  = THIS_MODULE,
		.of_match_table = my_match,
	},
	.probe          = my_probe,
	.remove         = my_remove,
};

static int __init my_touch_init(void)
{
	
	return platform_driver_register(&my_touch_driver);
}

static void __exit my_touch_exit(void)
{
	platform_driver_unregister(&my_touch_driver);
 	return 0;
}


module_init (my_touch_init);
module_exit (my_touch_exit);
